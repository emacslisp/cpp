#include <sys/types.h>
#include <unistd.h>
#include <sys/mman.h>

#include "utility.h"

void*
vsf_sysutil_map_anon_pages(unsigned int length)
{
  char* retval = mmap(0, length, PROT_READ | PROT_WRITE,
                      MAP_PRIVATE | MAP_ANON, -1, 0);
  if (retval == MAP_FAILED)
  {
    die("mmap");
  }
  return retval;
}

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