#ifndef _RTC_H
#define _RTC_H
#include "types.h"

typedef struct _rtc {

	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint32_t year;
	uint32_t century;

	char fuuuuuck;

} rtc_t;

void outb(uint16_t port, uint8_t value);

uint8_t inb(uint16_t port);

void readRTC(rtc_t *result);

void rtc_string(const rtc_t *input, char *output);

#endif //_RTC_H
