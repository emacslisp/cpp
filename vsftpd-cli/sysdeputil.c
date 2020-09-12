#include <sys/types.h>
#include <unistd.h>

int
vsf_sysutil_getpid_nocache(void)
{
#ifdef VSF_SYSDEP_HAVE_LINUX_CLONE
  /* Need to defeat the glibc pid caching because we need to hit a raw
   * sys_clone() above.
   */
  return syscall(__NR_getpid);
#else
  return getpid();
#endif
}