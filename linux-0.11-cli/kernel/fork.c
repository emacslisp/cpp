/*
 * fork.c
 *
 *  Created on: 28 Dec 2019
 *      Author: wudi
 */


#include <string.h>
#include <errno.h>

#include <linux/sched.h>
#include <linux/kernel.h>
#include <asm/segment.h>
#include <asm/system.h>

extern void write_verify(unsigned long address);

long last_pid=0;

void verify_area(void * addr,int size)
{

}

