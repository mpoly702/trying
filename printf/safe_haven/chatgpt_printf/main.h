#ifndef _PRINTF_H_
#define _PRINTF_H_

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <stddef.h>

#define SIZE_BUF 1024
#define FREE_BUF -1

#define BUF_FIELD 50

#define STR_NIL "(null)"

#define INIT_PMTRS {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define LOWER_CASE	1
#define USG_CONVT	2

/**
 * struct parameters - parameters struct
 *
 * @usg: flag if unsigned value
 *
 * @flg_pls: on if plus_flag specified
 * @flg_sp: on if hashtag_flag specified
 * @flg_htag: on if _flag specified
 * @flg_z: on if _flag specified
 * @flg_ms: on if _flag specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 * @modi_h: on for modi_h is specified
 * @modi_l: on for modi_l is specified
 *
 */

typedef struct pmeter
{
	unsigned int usg		: 1;

	unsigned int flg_pls		: 1;
	unsigned int flg_sp		: 1;
	unsigned int flg_htag		: 1;
	unsigned int flg_z		: 1;
	unsigned int flg_ms		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int modi_h		: 1;
	unsigned int modi_l		: 1;
} pmtrs_t;

/**
 * struct specifier - Struct token
 *
 * @indicator: format token
 * @f: function pointer
 */
typedef struct indicator
{
	char *indicator;
	int (*f)(va_list, pmtrs_t *);
} ind_t;

int print_ch(va_list args, pmtrs_t *pmtrs);
int print_integer(va_list args, pmtrs_t *pmtrs);
int print_str1(va_list args, pmtrs_t *pmtrs);
int print_per(va_list args, pmtrs_t *pmtrs);
int print_SOS(va_list args);
int (*specifier_get(char *s))(va_list args, pmtrs_t *pmtrs);
int func_get_pr(char *s, va_list args, pmtrs_t *pmtrs);
int flg_get(char *s, pmtrs_t *pmtrs);
int modi_get(char *s, pmtrs_t *pmtrs);
char *width_get(char *s, pmtrs_t *pmtrs, va_list args);
int hexa_print(va_list args, pmtrs_t *pmtrs);
int HEXA_print(va_list args, pmtrs_t *pmtrs);
int binary_out(va_list args, pmtrs_t *pmtrs);
int octal_out(va_list args, pmtrs_t *pmtrs);
void init_pmtrs(pmtrs_t *pmtrs);
char *prec_get(char *p, pmtrs_t *pmtrs, va_list args);
int _puts(char *str);
int _putchar(int c);
int _Adigit(int c);
int _strlen(char *s);
int print_num(char *str, pmtrs_t *pmtrs);
int print_shift(char *s, pmtrs_t *pmtrs);
int print_left(char *s, pmtrs_t *pmtrs);
int _printf(const char *format, ...);
int print_w(char *begin, char *end, char *except);
int rev_str(va_list args, pmtrs_t *pmtrs);
int print_root(va_list args, pmtrs_t *pmtrs);
char *transform(long int x, int y, int flgs, pmtrs_t *pmtrs);
int usg_print(va_list args, pmtrs_t *pmtrs);
int print_locate(va_list args, pmtrs_t *pmtrs);
void transform_hexa(char *hexa, int value);

#endif
