#include <uclib.h>
#include <stdint.h>

static uint32_t random_number_state;
uint16_t rand() // LCG based on ANSI C
{
    random_number_state = (1103515245 * random_number_state + 12345) & 0x7fffffff;
    return random_number_state >> 16;
}
void srand(uint32_t x)
{
    random_number_state = x;
}

void print_string(char const *str)
{
    while (*str && usbcdc_putchar(*str++))
        continue;
}

void hex_dump(uint32_t start, uint8_t bytes)
{
    int8_t i;
    if (bytes > 8)
    {
        bytes = 8;
    }

    for (i = bytes - 1; i >= 0; i--)
    {
        uint8_t hex_digit = (start >> 4 * i) & 0xf;
        usbcdc_putchar(hex_digit + ((hex_digit < 10) ? '0' : 'A' - 10));
    }
}