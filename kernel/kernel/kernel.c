#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
 
#include <kernel/tty.h>
#include <kernel/rtc.h>
 
void kernel_early(void)
{
	terminal_initialize();
}
 
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif 
void kernel_main(void) {

	rtc_t r;
	const rtcBufSz = 25;
	char buf[rtcBufSz];


	printf("Concur OS\n");

	while(1) {

		readRTC(&r);

		rtc_write(&r, &buf);

		// Keep the time on the same line
		buf[rtcBufSz-1] = '\r';

		terminal_writetime(&buf);

		memset(&buf, 0, rtcBufSz);

		wait(&r, 1);
	}
}
