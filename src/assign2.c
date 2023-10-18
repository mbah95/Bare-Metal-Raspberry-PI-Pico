#include "usbcdc.h"
#include <uclib.h>

int main()
{
    char c;
    configure_usbcdc();
    while (1)
    {
        if (usbcdc_getchar(&c))
        {
            hex_dump(0x2000000A, 16);
        }
    }

    return 0;
}
