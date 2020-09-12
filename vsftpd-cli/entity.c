#include <stdio.h>

#include "session.h"
#include "utility.h"
#include "tunables.h"
#include "logging.h"
#include "str.h"
#include "filestr.h"
#include "ftpcmdio.h"
#include "sysutil.h"
#include "sysdeputil.h"
#include "defs.h"
#include "parseconf.h"
#include "oneprocess.h"
#include "twoprocess.h"
#include "standalone.h"
#include "tcpwrap.h"
#include "vsftpver.h"
#include "ssl.h"

#include "secbuf.h"

// important
void getcwdEntry()
{
    struct mystr t = INIT_MYSTR;
    struct mystr* p_str = &t;
    char* p_ret = NULL;
    char *p_getcwd_buf = NULL;
    if (p_getcwd_buf == 0)
    {
        vsf_secbuf_alloc(&p_getcwd_buf, VSFTP_PATH_MAX);
    }
    str_empty(p_str);
    p_ret = vsf_sysutil_getcwd(p_getcwd_buf, VSFTP_PATH_MAX);
    if (p_ret != 0)
    {
        str_alloc_text(p_str, p_getcwd_buf);
    }

    printf("%s\n", p_str ->PRIVATE_HANDS_OFF_p_buf);
}

void pidEntry() 
{
    enum EVSFSysUtilOpenMode open_mode = kVSFSysUtilOpenReadWrite;
    printf("%d\n", open_mode);

    printf("%d\n", vsf_sysutil_getpid_nocache());
}

void strEntry() {
    struct mystr str = INIT_MYSTR;
    str_alloc_text(&str, vsf_sysutil_get_current_date());
    str_append_text(&str, "Hello World");
    str_append_ulong(&str, 1234);
    str_append_char(&str, 'a');
    printf("%s\n", str.PRIVATE_HANDS_OFF_p_buf);
    printf("%d\n", str.PRIVATE_HANDS_OFF_len);
}