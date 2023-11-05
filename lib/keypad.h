#ifndef KEYPAD_H
#define KEYPAD_H

#include <stdio.h>
#include <stdint.h>

void configure_keypad();
void keypad_scan_column(uint8_t col);
uint8_t keypad_get_row();

#define ALL_KEYPAD_COLUMNS 0xff

#endif