#include "systick.h"
#include <stdint.h>
#include <stdbool.h>
#include <rp2040/m0plus.h>

#define SYSTICK_FREQ_HZ 1000
#define SYSTICK_TOP (SYS_CLOCK / SYSTICK_FREQ_HZ)

void configure_systick()
{
    // SET RVR to SYSTICK
    m0plus->syst_rvr=SYSTICK_TOP;
    // WRITE 0 to CVR TO FORCE IMMEDIATE RESET
    m0plus->syst_cvr = 0;
    // CONFIGURE CSR Clock Source and Enable
    m0plus->syst_csr = M0PLUS_SYST_CSR_ENABLE_MASK | M0PLUS_SYST_CSR_CLKSOURCE_MASK;
}
_Bool systick_has_fired()
{
    return m0plus->syst_csr & M0PLUS_SYST_CSR_COUNTFLAG_MASK;
}
