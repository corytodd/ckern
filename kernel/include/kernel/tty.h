#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H
 
#include <stddef.h>
 
void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);


/**
 * terminal_putentryat() - Puts character at VGA buffer index
 * @arg1:	char ASCII to print to screen
 * @arg2:	uint8_t color code
 * @arg3: 	size_t X coordinate (column)
 * @arg4:	size_t Y coordinate (row)
 *
 * Only ASCII characters will print normally. All other control codes
 * will be VGA specific characters. The color must be a color from the
 * enum vga_color to guarantee rendering. The coordinate system starts
 * in the upper left corner and expands left and downward.
 * 
 * 0,0_______
 *   |		 |
 * 	 |		 |
 *   |		 |
 *	 ...
 * 	 |_______|
 * 			 VGA_WIDTH,VGA_HEIGHT
 *
 * Return: void
 */ 
 
#endif
