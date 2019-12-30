/*
 * main.c
 *
 *  Created on: 27 Dec 2019
 *      Author: wudi
 */

#include <linux/tty.h>
#include <linux/sched.h>
#include <linux/head.h>
#include <asm/system.h>
#include <asm/io.h>

#include <stddef.h>
#include <stdarg.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

#include <linux/fs.h>

extern int vsprintf();
extern void init(void);
extern void blk_dev_init(void);
extern void chr_dev_init(void);
extern void hd_init(void);
extern void floppy_init(void);
extern void mem_init(long start, long end);
extern long rd_init(long mem_start, int length);
extern long kernel_mktime(struct tm * tm);
extern long startup_time;

void init_test() {
	struct drive_info { char dummy[32]; } drive_info;
	/*
	 * This is set up by the setup-routine at boot-time
	 */
	#define EXT_MEM_K (*(unsigned short *)0x90002)
	#define DRIVE_INFO (*(struct drive_info *)0x90080)
	#define ORIG_ROOT_DEV (*(unsigned short *)0x901FC)

	static long memory_end = 0;
	static long buffer_memory_end = 0;
	static long main_memory_start = 0;
	memory_end = (1<<20) + (EXT_MEM_K<<10);
	memory_end &= 0xfffff000;
	if (memory_end > 16*1024*1024)
		memory_end = 16*1024*1024;
	if (memory_end > 12*1024*1024)
		buffer_memory_end = 4*1024*1024;
	else if (memory_end > 6*1024*1024)
		buffer_memory_end = 2*1024*1024;
	else
		buffer_memory_end = 1*1024*1024;
	main_memory_start = buffer_memory_end;
#ifdef RAMDISK
	main_memory_start += rd_init(main_memory_start, RAMDISK*1024);
#endif
	mem_init(main_memory_start,memory_end);
}

int main(int argc, char *argv[]) {

	// printf("linux 0.11 cli");

	// mktime_test();

	// printk_test();


	return 0;
}
