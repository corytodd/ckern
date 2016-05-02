#include <kernel/rtc.h>
static uint8_t isSettled(void);
static uint8_t getRTCRegister(uint8_t reg);


typedef enum _cmos {
	cmops_address = 0x70, 
	cmos_data = 0x71,
} cmos_t;

void outb(uint16_t port, uint8_t value) {

	__asm__ __volatile__(
			"outb %0, %1"
			:
			: "a" (value), "Nd" (port)
			);
}


uint8_t inb(uint16_t port) {

	uint8_t result;

	__asm__ __volatile__(
			"inb %1, %0"
			: "=a" (result)
			: "Nd" (port)
			);
	return result;
}


static uint8_t isSettled(void) {

	outb(cmops_address, 0x0A);
	uint8_t result = inb(cmos_data);
	return (result & 0x80) == 0;
}

static uint8_t getRTCRegister(uint8_t reg) {

	outb(cmops_address, reg);
	uint8_t result = inb(cmos_data);
	return result;

}

void readRTC(rtc_t *result) {

	while(!isSettled()) {}

/*
	rtc_t last = {
		.second = getRTCRegister(0x01),
		.minute = getRTCRegister(0x02),
		.hour = getRTCRegister(0x04),
		.day = getRTCRegister(0x07),
		.month = getRTCRegister(0x08),
		.year = getRTCRegister(0x09),
	};	*/
	// TODO Make sure we are not getting junk from RTC
	result->second = getRTCRegister(0x00);
	result->minute = getRTCRegister(0x02);
	result->hour = getRTCRegister(0x04);
	result->day = getRTCRegister(0x07);
	result->month = getRTCRegister(0x08);
	result->year = getRTCRegister(0x09);
}

void wait(rtc_t *r, uint32_t seconds) {

	uint32_t t = 0;

	while(t < seconds) {
		t += getRTCRegister(0x00);
	}

}

void rtc_write(const rtc_t *r, char *output) {

	sprintf(output, 
		"Time: %d/%d/%d %d:%d:%d", 
		r->month,
		r->day, 
		r->year,
		r->hour, 
		r->minute,
		r->second);
}
