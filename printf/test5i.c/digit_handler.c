#include "main.h"

/**
 * init_pmtrs - makes our life easier by resetting the buf
 * @pmtrs: parameter struct
 * @args: pointer to the argument
 *
 *
 * Return: void
 */

void init_pmtrs(pmtrs_t *pmtrs, va_list args)
{
	pmtrs->usg = 0;
	pmtrs->flg_pls = 0;
	pmtrs->flg_sp = 0;
	pmtrs->flg_htag = 0;
	pmtrs->flg_z = 0;
	pmtrs->flg_ms = 0;
	pmtrs->width = 0;
	pmtrs->precision = UINT_MAX;
	pmtrs->modi_h = 0;
	pmtrs->modi_l = 0;
	(void)args;
}
