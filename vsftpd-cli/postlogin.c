#include "postlogin.h"
#include "session.h"
#include "oneprocess.h"

/* Private local functions */
static void handle_pwd(struct vsf_session* p_sess);
static void handle_cwd(struct vsf_session* p_sess);
static void handle_pasv(struct vsf_session* p_sess, int is_epsv);
static void handle_retr(struct vsf_session* p_sess, int is_http);
static void handle_cdup(struct vsf_session* p_sess);
static void handle_list(struct vsf_session* p_sess);
static void handle_type(struct vsf_session* p_sess);
static void handle_port(struct vsf_session* p_sess);
static void handle_stor(struct vsf_session* p_sess);
static void handle_mkd(struct vsf_session* p_sess);
static void handle_rmd(struct vsf_session* p_sess);
static void handle_dele(struct vsf_session* p_sess);
static void handle_rest(struct vsf_session* p_sess);
static void handle_rnfr(struct vsf_session* p_sess);
static void handle_rnto(struct vsf_session* p_sess);
static void handle_nlst(struct vsf_session* p_sess);
static void handle_size(struct vsf_session* p_sess);
static void handle_site(struct vsf_session* p_sess);
static void handle_appe(struct vsf_session* p_sess);
static void handle_mdtm(struct vsf_session* p_sess);
static void handle_site_chmod(struct vsf_session* p_sess,
                              struct mystr* p_arg_str);
static void handle_site_umask(struct vsf_session* p_sess,
                              struct mystr* p_arg_str);
static void handle_eprt(struct vsf_session* p_sess);
static void handle_help(struct vsf_session* p_sess);
static void handle_stou(struct vsf_session* p_sess);
static void handle_stat(struct vsf_session* p_sess);
static void handle_stat_file(struct vsf_session* p_sess);
static void handle_logged_in_user(struct vsf_session* p_sess);
static void handle_logged_in_pass(struct vsf_session* p_sess);
static void handle_http(struct vsf_session* p_sess);

void process_post_login(struct vsf_session* p_sess)
{
  str_getcwd(&p_sess->home_str);
  if (p_sess->is_anonymous)
  {
    vsf_sysutil_set_umask(tunable_anon_umask);
    p_sess->bw_rate_max = tunable_anon_max_rate;
  }
  else
  {
    vsf_sysutil_set_umask(tunable_local_umask);
    p_sess->bw_rate_max = tunable_local_max_rate;
  }
  if (p_sess->is_http)
  {
    handle_http(p_sess);
    bug("should not be reached");
  }

  /* Don't support async ABOR if we have an SSL channel. The spec says SHOULD
   * NOT, and I think there are synchronization issues between command and
   * data reads.
   */
  if (tunable_async_abor_enable && !p_sess->control_use_ssl)
  {
    vsf_sysutil_install_sighandler(kVSFSysUtilSigURG, handle_sigurg, p_sess, 0);
    vsf_sysutil_activate_sigurg(VSFTP_COMMAND_FD);
  }
  /* Handle any login message */
  vsf_banner_dir_changed(p_sess, FTP_LOGINOK);
  vsf_cmdio_write(p_sess, FTP_LOGINOK, "Login successful.");

  while(1)
  {
    int cmd_ok = 1;
    if (tunable_setproctitle_enable)
    {
      vsf_sysutil_setproctitle("IDLE");
    }
    /* Blocks */
    vsf_cmdio_get_cmd_and_arg(p_sess, &p_sess->ftp_cmd_str,
                              &p_sess->ftp_arg_str, 1);
    if (tunable_setproctitle_enable)
    {
      struct mystr proctitle_str = INIT_MYSTR;
      str_copy(&proctitle_str, &p_sess->ftp_cmd_str);
      if (!str_isempty(&p_sess->ftp_arg_str))
      {
        str_append_char(&proctitle_str, ' ');
        str_append_str(&proctitle_str, &p_sess->ftp_arg_str);
      }
      /* Suggestion from Solar */
      str_replace_unprintable(&proctitle_str, '?');
      vsf_sysutil_setproctitle_str(&proctitle_str);
      str_free(&proctitle_str);
    }
    /* Test command against the allowed lists.. */
    if (tunable_cmds_allowed)
    {
      static struct mystr s_src_str;
      static struct mystr s_rhs_str;
      str_alloc_text(&s_src_str, tunable_cmds_allowed);
      while (1)
      {
        str_split_char(&s_src_str, &s_rhs_str, ',');
        if (str_isempty(&s_src_str))
        {
          cmd_ok = 0;
          break;
        }
        else if (str_equal(&s_src_str, &p_sess->ftp_cmd_str))
        {
          break;
        }
        str_copy(&s_src_str, &s_rhs_str);
      }
    }
    if (tunable_cmds_denied)
    {
      static struct mystr s_src_str;
      static struct mystr s_rhs_str;
      str_alloc_text(&s_src_str, tunable_cmds_denied);
      while (1)
      {
        str_split_char(&s_src_str, &s_rhs_str, ',');
        if (str_isempty(&s_src_str))
        {
          break;
        }
        else if (str_equal(&s_src_str, &p_sess->ftp_cmd_str))
        {
          cmd_ok = 0;
          break;
        }
        str_copy(&s_src_str, &s_rhs_str);
      }
    }
    if (!cmd_ok)
    {
      vsf_cmdio_write(p_sess, FTP_NOPERM, "Permission denied.");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "QUIT"))
    {
      vsf_cmdio_write_exit(p_sess, FTP_GOODBYE, "Goodbye.", 0);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "PWD") ||
             str_equal_text(&p_sess->ftp_cmd_str, "XPWD"))
    {
      handle_pwd(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "CWD") ||
             str_equal_text(&p_sess->ftp_cmd_str, "XCWD"))
    {
      handle_cwd(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "CDUP") ||
             str_equal_text(&p_sess->ftp_cmd_str, "XCUP"))
    {
      handle_cdup(p_sess);
    }
    else if (tunable_pasv_enable &&
             !p_sess->epsv_all &&
             (str_equal_text(&p_sess->ftp_cmd_str, "PASV") ||
              str_equal_text(&p_sess->ftp_cmd_str, "P@SW")))
    {
      handle_pasv(p_sess, 0);
    }
    else if (tunable_pasv_enable &&
             str_equal_text(&p_sess->ftp_cmd_str, "EPSV"))
    {
      handle_pasv(p_sess, 1);
    }
    else if (tunable_download_enable &&
             str_equal_text(&p_sess->ftp_cmd_str, "RETR"))
    {
      handle_retr(p_sess, 0);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "NOOP"))
    {
      vsf_cmdio_write(p_sess, FTP_NOOPOK, "NOOP ok.");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "SYST"))
    {
      vsf_cmdio_write(p_sess, FTP_SYSTOK, "UNIX Type: L8");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "HELP"))
    {
      handle_help(p_sess);
    }
    else if (tunable_dirlist_enable &&
             str_equal_text(&p_sess->ftp_cmd_str, "LIST"))
    {
      handle_list(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "TYPE"))
    {
      handle_type(p_sess);
    }
    else if (tunable_port_enable &&
             !p_sess->epsv_all &&
             str_equal_text(&p_sess->ftp_cmd_str, "PORT"))
    {
      handle_port(p_sess);
    }
    else if (tunable_write_enable &&
             (tunable_anon_upload_enable || !p_sess->is_anonymous) &&
             str_equal_text(&p_sess->ftp_cmd_str, "STOR"))
    {
      handle_stor(p_sess);
    }
    else if (tunable_write_enable &&
             (tunable_anon_mkdir_write_enable || !p_sess->is_anonymous) &&
             (str_equal_text(&p_sess->ftp_cmd_str, "MKD") ||
              str_equal_text(&p_sess->ftp_cmd_str, "XMKD")))
    {
      handle_mkd(p_sess);
    }
    else if (tunable_write_enable &&
             (tunable_anon_other_write_enable || !p_sess->is_anonymous) &&
             (str_equal_text(&p_sess->ftp_cmd_str, "RMD") ||
              str_equal_text(&p_sess->ftp_cmd_str, "XRMD")))
    {
      handle_rmd(p_sess);
    }
    else if (tunable_write_enable &&
             (tunable_anon_other_write_enable || !p_sess->is_anonymous) &&
             str_equal_text(&p_sess->ftp_cmd_str, "DELE"))
    {
      handle_dele(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "REST"))
    {
      handle_rest(p_sess);
    }
    else if (tunable_write_enable &&
             (tunable_anon_other_write_enable || !p_sess->is_anonymous) &&
             str_equal_text(&p_sess->ftp_cmd_str, "RNFR"))
    {
      handle_rnfr(p_sess);
    }
    else if (tunable_write_enable &&
             (tunable_anon_other_write_enable || !p_sess->is_anonymous) &&
             str_equal_text(&p_sess->ftp_cmd_str, "RNTO"))
    {
      handle_rnto(p_sess);
    }
    else if (tunable_dirlist_enable &&
             str_equal_text(&p_sess->ftp_cmd_str, "NLST"))
    {
      handle_nlst(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "SIZE"))
    {
      handle_size(p_sess);
    }
    else if (!p_sess->is_anonymous &&
             str_equal_text(&p_sess->ftp_cmd_str, "SITE"))
    {
      handle_site(p_sess);
    }
    /* Note - the weird ABOR string is checking for an async ABOR arriving
     * without a SIGURG condition.
     */
    else if (str_equal_text(&p_sess->ftp_cmd_str, "ABOR") ||
             str_equal_text(&p_sess->ftp_cmd_str, "\377\364\377\362ABOR"))
    {
      vsf_cmdio_write(p_sess, FTP_ABOR_NOCONN, "No transfer to ABOR.");
    }
    else if (tunable_write_enable &&
             (tunable_anon_other_write_enable || !p_sess->is_anonymous) &&
             str_equal_text(&p_sess->ftp_cmd_str, "APPE"))
    {
      handle_appe(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "MDTM"))
    {
      handle_mdtm(p_sess);
    }
    else if (tunable_port_enable &&
             str_equal_text(&p_sess->ftp_cmd_str, "EPRT"))
    {
      handle_eprt(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "STRU"))
    {
      str_upper(&p_sess->ftp_arg_str);
      if (str_equal_text(&p_sess->ftp_arg_str, "F"))
      {
        vsf_cmdio_write(p_sess, FTP_STRUOK, "Structure set to F.");
      }
      else
      {
        vsf_cmdio_write(p_sess, FTP_BADSTRU, "Bad STRU command.");
      }
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "MODE"))
    {
      str_upper(&p_sess->ftp_arg_str);
      if (str_equal_text(&p_sess->ftp_arg_str, "S"))
      {
        vsf_cmdio_write(p_sess, FTP_MODEOK, "Mode set to S.");
      }
      else
      {
        vsf_cmdio_write(p_sess, FTP_BADMODE, "Bad MODE command.");
      }
    }
    else if (tunable_write_enable &&
             (tunable_anon_upload_enable || !p_sess->is_anonymous) &&
             str_equal_text(&p_sess->ftp_cmd_str, "STOU"))
    {
      handle_stou(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "ALLO"))
    {
      vsf_cmdio_write(p_sess, FTP_ALLOOK, "ALLO command ignored.");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "REIN"))
    {
      vsf_cmdio_write(p_sess, FTP_COMMANDNOTIMPL, "REIN not implemented.");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "ACCT"))
    {
      vsf_cmdio_write(p_sess, FTP_COMMANDNOTIMPL, "ACCT not implemented.");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "SMNT"))
    {
      vsf_cmdio_write(p_sess, FTP_COMMANDNOTIMPL, "SMNT not implemented.");
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "FEAT"))
    {
      handle_feat(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "OPTS"))
    {
      handle_opts(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "STAT") &&
             str_isempty(&p_sess->ftp_arg_str))
    {
      handle_stat(p_sess);
    }
    else if (tunable_dirlist_enable &&
             str_equal_text(&p_sess->ftp_cmd_str, "STAT"))
    {
      handle_stat_file(p_sess);
    }
    else if (tunable_ssl_enable && str_equal_text(&p_sess->ftp_cmd_str, "PBSZ"))
    {
      handle_pbsz(p_sess);
    }
    else if (tunable_ssl_enable && str_equal_text(&p_sess->ftp_cmd_str, "PROT"))
    {
      handle_prot(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "USER"))
    {
      handle_logged_in_user(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "PASS"))
    {
      handle_logged_in_pass(p_sess);
    }
    else if (str_equal_text(&p_sess->ftp_cmd_str, "PASV") ||
             str_equal_text(&p_sess->ftp_cmd_str, "PORT") ||
             str_equal_text(&p_sess->ftp_cmd_str, "STOR") ||
             str_equal_text(&p_sess->ftp_cmd_str, "MKD") ||
             str_equal_text(&p_sess->ftp_cmd_str, "XMKD") ||
             str_equal_text(&p_sess->ftp_cmd_str, "RMD") ||
             str_equal_text(&p_sess->ftp_cmd_str, "XRMD") ||
             str_equal_text(&p_sess->ftp_cmd_str, "DELE") ||
             str_equal_text(&p_sess->ftp_cmd_str, "RNFR") ||
             str_equal_text(&p_sess->ftp_cmd_str, "RNTO") ||
             str_equal_text(&p_sess->ftp_cmd_str, "SITE") ||
             str_equal_text(&p_sess->ftp_cmd_str, "APPE") ||
             str_equal_text(&p_sess->ftp_cmd_str, "EPSV") ||
             str_equal_text(&p_sess->ftp_cmd_str, "EPRT") ||
             str_equal_text(&p_sess->ftp_cmd_str, "RETR") ||
             str_equal_text(&p_sess->ftp_cmd_str, "LIST") ||
             str_equal_text(&p_sess->ftp_cmd_str, "NLST") ||
             str_equal_text(&p_sess->ftp_cmd_str, "STOU") ||
             str_equal_text(&p_sess->ftp_cmd_str, "ALLO") ||
             str_equal_text(&p_sess->ftp_cmd_str, "REIN") ||
             str_equal_text(&p_sess->ftp_cmd_str, "ACCT") ||
             str_equal_text(&p_sess->ftp_cmd_str, "SMNT") ||
             str_equal_text(&p_sess->ftp_cmd_str, "FEAT") ||
             str_equal_text(&p_sess->ftp_cmd_str, "OPTS") ||
             str_equal_text(&p_sess->ftp_cmd_str, "STAT") ||
             str_equal_text(&p_sess->ftp_cmd_str, "PBSZ") ||
             str_equal_text(&p_sess->ftp_cmd_str, "PROT"))
    {
      vsf_cmdio_write(p_sess, FTP_NOPERM, "Permission denied.");
    }
    else if (str_isempty(&p_sess->ftp_cmd_str) &&
             str_isempty(&p_sess->ftp_arg_str))
    {
      /* Deliberately ignore to avoid NAT device bugs. ProFTPd does the same. */
    }
    else
    {
      vsf_cmdio_write(p_sess, FTP_BADCMD, "Unknown command.");
    }
    if (vsf_log_entry_pending(p_sess))
    {
      vsf_log_do_log(p_sess, 0);
    }
    if (p_sess->data_timeout)
    {
      vsf_cmdio_write_exit(p_sess, FTP_DATA_TIMEOUT,
                           "Data timeout. Reconnect. Sorry.", 1);
    }
  }
}
