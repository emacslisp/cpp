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

void strEntry() {
    struct mystr str = INIT_MYSTR;
    str_alloc_text(&str, vsf_sysutil_get_current_date());
    str_append_text(&str, "Hello World");
    str_append_ulong(&str, 1234);
    str_append_char(&str, 'a');
    printf("%s\n", str.PRIVATE_HANDS_OFF_p_buf);
    printf("%d\n", str.PRIVATE_HANDS_OFF_len);
}