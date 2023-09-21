#include "main.h"

/**
* init_pmtrs - clearsthe field in struct and resets the buf
* @pmtrs: tis is the struct of the parameter
* @args: argument pointer
*
* Return: void
*/

void init_pmtrs(pmtrs_t *pmtrs, va_list args)
{
pmtrs->usg = 0;

pmtrs->flg_pls = 0;
pmtrs->flag_sp = 0;
pmtrs->flg_htag = 0;
pmtrs->flg_z = 0;
pmtrs->flg_ms = 0;

pmtrs->width = 0;
pmtrs->precision = UINT_MAX;

pmtrs->modi_h = 0;
params->modi_l = 0;
(void)args;
}
