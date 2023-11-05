#ifndef SYSTICK_H
#define SYSTICK_H

#include <stdint.h>
#include <stdbool.h>

#define SYSTICK_FREQ_HZ 1000
#define SYSTICK_TOP (SYS_CLOCK / SYSTICK_FREQ_HZ)

void configure_systick();
_Bool systick_has_fired();

#endif