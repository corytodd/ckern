#ifndef _RTC_H
#define _RTC_H
#include <string.h>
#include "types.h"
#include <stdio.h>

typedef struct _rtc {

	uint8_t second;
	uint8_t minute;
	uint8_t hour;
	uint8_t day;
	uint8_t month;
	uint32_t year;
	uint32_t century;

} rtc_t;

void outb(uint16_t port, uint8_t value);

uint8_t inb(uint16_t port);

void readRTC(rtc_t *result);

void wait(rtc_t *result, uint32_t seconds);

void rtc_string(const rtc_t *input, char *output);

#endif //_RTC_H
