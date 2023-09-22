#include <stdarg.h>
#include <unistd.h>

#define SIZE_BUF 1024
#define STR_NIL "(nil)"

typedef struct pmtrs_t {
    int usg;
    int flg_pls;
    int flg_sp;
    int flg_htag;
    int flg_z;
    int flg_ms;
    int width;
    unsigned int precision;
    int modi_h;
    int modi_l;
} pmtrs_t;

int _putchar(char c);
int _puts(char *str);
char *transform(long int num, int base, int flags, pmtrs_t *pmtrs);

int print_integer(va_list args, pmtrs_t *pmtrs);
int print_char(va_list args, pmtrs_t *pmtrs);
int print_string(va_list args, pmtrs_t *pmtrs);
int print_percent(va_list args, pmtrs_t *pmtrs);
int print_hexadecimal(va_list args, pmtrs_t *pmtrs);
int print_octal(va_list args, pmtrs_t *pmtrs);
int print_unsigned(va_list args, pmtrs_t *pmtrs);
int print_binary(va_list args, pmtrs_t *pmtrs);
int print_pointer(va_list args, pmtrs_t *pmtrs);
int print_special_string(va_list args, pmtrs_t *pmtrs);
int print_reverse(va_list args, pmtrs_t *pmtrs);
int print_rot13(va_list args, pmtrs_t *pmtrs);

void init_pmtrs(pmtrs_t *pmtrs, va_list args);
int custom_printf(const char *format, ...);
int get_flags(const char *s, pmtrs_t *pmtrs);
int get_modifiers(const char *s, pmtrs_t *pmtrs);
const char *get_width(const char *s, pmtrs_t *pmtrs, va_list args);
const char *get_precision(const char *s, pmtrs_t *pmtrs, va_list args);
int process_specifier(char specifier, va_list args, pmtrs_t *pmtrs);
int (*get_handler(char specifier))(va_list args, pmtrs_t *pmtrs);

#endif





