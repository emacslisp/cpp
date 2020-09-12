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

void pidEntry() 
{
    enum EVSFSysUtilOpenMode open_mode = kVSFSysUtilOpenReadWrite;
    printf("%d\n", open_mode);

    printf("%d\n", vsf_sysutil_getpid_nocache());
}