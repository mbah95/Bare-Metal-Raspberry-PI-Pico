#ifndef UCLIB
#define UCLIB
#include <stdint.h>

uint16_t rand();
void srand(uint32_t);
void hex_dump(uint32_t start, uint8_t bytes);
void print_string(char const *str);

#endif
