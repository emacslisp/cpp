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

/*
 * Forward decls of helper functions
 */
static void die_unless_privileged(void);
static void do_sanity_checks(void);
static void session_init(struct vsf_session* p_sess);
static void env_init(void);
static void limits_init(void);

int
main(int argc, const char* argv[])
{
  struct vsf_session the_session =
  {
    /* Control connection */
    0, 0, 0, 0, 0,
    /* Data connection */
    -1, 0, -1, 0, 0, 0, 0,
    /* Login */
    1, 0, INIT_MYSTR, INIT_MYSTR,
    /* Protocol state */
    0, 1, INIT_MYSTR, 0, 0,
    /* HTTP hacks */
    0, INIT_MYSTR,
    /* Session state */
    0,
    /* Userids */
    -1, -1, -1,
    /* Pre-chroot() cache */
    INIT_MYSTR, INIT_MYSTR, INIT_MYSTR, INIT_MYSTR, 1,
    /* Logging */
    -1, -1, INIT_MYSTR, 0, 0, 0, INIT_MYSTR, 0,
    /* Buffers */
    INIT_MYSTR, INIT_MYSTR,
    /* Parent <-> child comms */
    -1, -1,
    /* Number of clients */
    0, 0,
    /* Home directory */
    INIT_MYSTR,
    /* Secure connection state */
    0, 0, 0, 0, 0, INIT_MYSTR, 0, -1, -1,
    /* Login fails */
    0
  };

enum EVSFSysUtilOpenMode open_mode = kVSFSysUtilOpenReadWrite;
printf("%d\n", open_mode);
}