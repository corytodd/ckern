#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
 
#include <kernel/tty.h>
 
void kernel_early(void)
{
	terminal_initialize();
}
 
 
#if defined(__cplusplus)
extern "C" /* Use C linkage for kernel_main. */
#endif 
void kernel_main(void)
{
	printf("Hello, kernel World!\n");
}

/*
 
static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;
 
size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer;
 
 
uint8_t make_color(enum vga_color fg, enum vga_color bg) {
	return (uint8_t)(fg | bg << 4);
}
 
uint16_t make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = (uint16_t)c;
	uint16_t color16 = color;
	return (uint16_t)(c16 | color16 << 8);
}
 
size_t strlen(const char* str) {
	size_t ret = 0;
	while ( str[ret] != 0 )
		ret++;
	return ret;
}
 

void terminal_initialize() {
	terminal_row = 0;
	terminal_column = 0;
	terminal_color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	terminal_buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			terminal_buffer[index] = make_vgaentry(' ', terminal_color);
		}
	}
}
 
void terminal_setcolor(uint8_t color) {
	terminal_color = color;
}
 
 

void terminal_putentryat(char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	terminal_buffer[index] = make_vgaentry(c, color);
}
 
 
void poorman_sleep(uint64_t sleep) {

	uint8_t dummy = 0;

	while(sleep-- > 0) { dummy ^= 1;}
}
 
void terminal_putchar(char c) {

	// Newline
	if(c == '\n') {
		terminal_column = 0;

		if (++terminal_row == VGA_HEIGHT) {
		
			terminal_scrollup(1);					
				
		}		
		
		goto end;
	}
	
	
	
	
	
	
	
	
	enum vga_color fg = c % 15;
	enum vga_color bg = (c % 15) ^ (c % 15);
	terminal_color = make_color(fg, bg);

	terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

	if (++terminal_column == VGA_WIDTH) {
	
		terminal_column = 0;	
		
		if (++terminal_row == VGA_HEIGHT) {
		
			terminal_scrollup(1);		
				
		}
	}
    
end:
	return;
}
 
 void terminal_writestring(const char* data) {
	size_t datalen = strlen(data);
	for (size_t i = 0; i < datalen; i++)
		terminal_putchar(data[i]);
}
 
 

 * terminal_scroll_up() - Scrolls visible text up 1 line
 * @arg1:	uint8_t rows to scroll up
 *
 * Shifts all content up by 1 row. All data in the current row 1 will 
 * be permanently deleted. Columns are not affected by this function.
 *
 *
 * Return: void

void terminal_scrollup(uint8_t count) {

	size_t i,j;
	size_t offset = count * VGA_WIDTH;
	const size_t last_coord = VGA_HEIGHT * VGA_WIDTH;
	
	for(i=0, j=offset; j < last_coord; i++, j++) {	
		terminal_buffer[i] = terminal_buffer[j];	
	}
	
	// Zero out last row
	for(i=last_coord - VGA_WIDTH; i<last_coord; i++) {
		terminal_buffer[i] = COLOR_BLACK | COLOR_BLACK << 8;
	}
	
	// Sets the new row count
	terminal_row -= count;
	
}

void kernel_main() {
	Initialize terminal interface 
	terminal_initialize();

	rtc_t r;

	readRTC(&r);

	terminal_writestring(&r.fuuuuuck);
	
 
	size_t i;
    for(i=0; i<13; i++) {
		terminal_writestring("Hello, loop!\n");
		poorman_sleep(10000000);
	}
	
	terminal_writestring("Did I do the scroll?!\n");
}
*/
