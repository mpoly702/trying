#include "main.h"
void init_pmtrs(pmtrs_t *pmtrs)
{
    pmtrs->usg = 0;
    pmtrs->flg_pls = 0;
    pmtrs->flg_sp = 0;
    pmtrs->flg_htag = 0;
    pmtrs->flg_z = 0;
    pmtrs->flg_ms = 0;
    pmtrs->width = 0;
    pmtrs->precision = 4294967295U; // Equivalent to UINT_MAX
    pmtrs->modi_h = 0;
    pmtrs->modi_l = 0;
}

/**
 * print_per - Print a '%' character
 * @args: Argument pointer
 * @pmtrs: Parameters structure
 *
 * Return: The number of characters printed (always 1)
 */
int print_per(va_list args, pmtrs_t *pmtrs)
{
    (void)args;
    (void)pmtrs;

    char percent = '%';
    _putchar(percent);

    return 1;
}
