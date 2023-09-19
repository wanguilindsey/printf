#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024
#define FS_MINUS 1
#define FS_PLUS 2
#define FS_ZERO 4
#define FS_HASH 8
#define FS_SPACE 16
#define SZ_LONG 2
#define SZ_SHORT 1

/**
 * struct frmt - Struct
 * @frmt: The format.
 * @fnc: The function associated.
 */
struct frmt
{
	char frmt;
	int (*fnc)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct frmt frmt_m - Struct
 * @frmt: The format.
 * @frmt_m: The function associated.
 */
typedef struct frmt frmt_m;

int _printf(const char *format, ...);
int manage_print(const char *frmt, int *j,
va_list list, char buffer[], int flags, int width, int precision, int size);

int prt_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);
int prt_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int get_flags(const char *format, int *j);
int get_width(const char *format, int *j, va_list list);
int get_precision(const char *format, int *j, va_list list);
int get_size(const char *format, int *j);
int prt_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int prt_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int manage_wrt_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int wrt_number(int is_pstv, int indx, char buffer[],
	int flags, int width, int precision, int size);
int wrt_num(int indx, char bffr[], int flags, int width, int precision,
	int length, char pad, char xtra_d);
int wrt_pointer(char buffer[], int indx, int length,
	int width, int flags, char pad, char xtra_d, int pad_start);
int wrt_unsigned(int is_ngtv, int indx,
char buffer[], int flags, int width, int precision, int size);
int is_prtbl(char);
int appnd_hex_code(char, char[], int);
int is_dgt(char);

long int cnvrt_size_number(long int num, int size);
long int cnvrt_size_unsignd(unsigned long int num, int size);

#endif
