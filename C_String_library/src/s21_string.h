#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_
#include <ctype.h>
#include <errno.h>
#include <math.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#define s21_NULL (void *)0
#ifdef __linux__
#define MAXERRORS 134
#define ERRORS                                                                 \
  {                                                                            \
    "Success", "Operation not permitted", "No such file or directory",         \
        "No such process", "Interrupted system call", "Input/output error",    \
        "No such device or address", "Argument list too long",                 \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource temporarily unavailable", "Cannot allocate memory",          \
        "Permission denied", "Bad address", "Block device required",           \
        "Device or resource busy", "File exists", "Invalid cross-device link", \
        "No such device", "Not a directory", "Is a directory",                 \
        "Invalid argument", "Too many open files in system",                   \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain",                     \
        "Numerical result out of range", "Resource deadlock avoided",          \
        "File name too long", "No locks available",                            \
        "Function not implemented", "Directory not empty",                     \
        "Too many levels of symbolic links", "Unknown error 41",               \
        "No message of desired type", "Identifier removed",                    \
        "Channel number out of range", "Level 2 not synchronized",             \
        "Level 3 halted", "Level 3 reset", "Link number out of range",         \
        "Protocol driver not attached", "No CSI structure available",          \
        "Level 2 halted", "Invalid exchange", "Invalid request descriptor",    \
        "Exchange full", "No anode", "Invalid request code", "Invalid slot",   \
        "Unknown error 58", "Bad font file format", "Device not a stream",     \
        "No data available", "Timer expired", "Out of streams resources",      \
        "Machine is not on the network", "Package not installed",              \
        "Object is remote", "Link has been severed", "Advertise error",        \
        "Srmount error", "Communication error on send", "Protocol error",      \
        "Multihop attempted", "RFS specific error", "Bad message",             \
        "Value too large for defined data type", "Name not unique on network", \
        "File descriptor in bad state", "Remote address changed",              \
        "Can not access a needed shared library",                              \
        "Accessing a corrupted shared library",                                \
        ".lib section in a.out corrupted",                                     \
        "Attempting to link in too many shared libraries",                     \
        "Cannot exec a shared library directly",                               \
        "Invalid or incomplete multibyte or wide character",                   \
        "Interrupted system call should be restarted", "Streams pipe error",   \
        "Too many users", "Socket operation on non-socket",                    \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol", "Address already in use",  \
        "Cannot assign requested address", "Network is down",                  \
        "Network is unreachable", "Network dropped connection on reset",       \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available",                                           \
        "Transport endpoint is already connected",                             \
        "Transport endpoint is not connected",                                 \
        "Cannot send after transport endpoint shutdown",                       \
        "Too many references: cannot splice", "Connection timed out",          \
        "Connection refused", "Host is down", "No route to host",              \
        "Operation already in progress", "Operation now in progress",          \
        "Stale file handle", "Structure needs cleaning",                       \
        "Not a XENIX named type file", "No XENIX semaphores available",        \
        "Is a named type file", "Remote I/O error", "Disk quota exceeded",     \
        "No medium found", "Wrong medium type", "Operation canceled",          \
        "Required key not available", "Key has expired",                       \
        "Key has been revoked", "Key was rejected by service", "Owner died",   \
        "State not recoverable", "Operation not possible due to RF-kill",      \
        "Memory page has hardware error"                                       \
  }
#elif __APPLE__
#define MAXERRORS 107
#define ERRORS                                                                 \
  {                                                                            \
    "Operation not permitted", "No such file or directory", "No such process", \
        "Interrupted system call", "Input/output error",                       \
        "Device not configured", "Argument list too long",                     \
        "Exec format error", "Bad file descriptor", "No child processes",      \
        "Resource deadlock avoided", "Cannot allocate memory",                 \
        "Permission denied", "Bad address", "Block device required",           \
        "Resource busy", "File exists", "Cross-device link",                   \
        "Operation not supported by device", "Not a directory",                \
        "Is a directory", "Invalid argument", "Too many open files in system", \
        "Too many open files", "Inappropriate ioctl for device",               \
        "Text file busy", "File too large", "No space left on device",         \
        "Illegal seek", "Read-only file system", "Too many links",             \
        "Broken pipe", "Numerical argument out of domain", "Result too large", \
        "Resource temporarily unavailable", "Operation now in progress",       \
        "Operation already in progress", "Socket operation on non-socket",     \
        "Destination address required", "Message too long",                    \
        "Protocol wrong type for socket", "Protocol not available",            \
        "Protocol not supported", "Socket type not supported",                 \
        "Operation not supported", "Protocol family not supported",            \
        "Address family not supported by protocol family",                     \
        "Address already in use", "Can't assign requested address",            \
        "Network is down", "Network is unreachable",                           \
        "Network dropped connection on reset",                                 \
        "Software caused connection abort", "Connection reset by peer",        \
        "No buffer space available", "Socket is already connected",            \
        "Socket is not connected", "Can't send after socket shutdown",         \
        "Too many references: can't splice", "Operation timed out",            \
        "Connection refused", "Too many levels of symbolic links",             \
        "File name too long", "Host is down", "No route to host",              \
        "Directory not empty", "Too many processes", "Too many users",         \
        "Disc quota exceeded", "Stale NFS file handle",                        \
        "Too many levels of remote in path", "RPC struct is bad",              \
        "RPC version wrong", "RPC prog. not avail", "Program version wrong",   \
        "Bad procedure for program", "No locks available",                     \
        "Function not implemented", "Inappropriate file type or format",       \
        "Authentication error", "Need authenticator", "Device power is off",   \
        "Device error", "Value too large to be stored in data type",           \
        "Bad executable (or shared library)", "Bad CPU type in executable",    \
        "Shared library version mismatch", "Malformed Mach-o file",            \
        "Operation canceled", "Identifier removed",                            \
        "No message of desired type", "Illegal byte sequence",                 \
        "Attribute not found", "Bad message", "EMULTIHOP (Reserved)",          \
        "No message available on STREAM", "ENOLINK (Reserved)",                \
        "No STREAM resources", "Not a STREAM", "Protocol error",               \
        "STREAM ioctl timeout", "Operation not supported on socket",           \
        "Policy not found", "State not recoverable", "Previous owner died",    \
        "Interface output queue is full"                                       \
  }
#endif
typedef unsigned long int s21_size_t;

struct option {
  int exist_c;
  int prev_space;
  int on_next_to_read;
  int count;
  int exclusion;
  int width;
  int length;
  int stoppage;
};

struct flags {
  int flag_for_plus;
  int flag_for_fl;
  int flag_for_grid;
  int flag_for_star;
  int flag_for_shift;
  int flag_for_min;
  int flag_for_zero;
  int flag_for_e;
  int flag_for_L;
  int flag_for_space;
  int flag_for_l;
  int flag_for_sh;
};

void *s21_memchr(const void *str, int c, s21_size_t n);
int s21_memcmp(const void *str1, const void *str2, s21_size_t n);
void *s21_memcpy(void *dest, const void *src, s21_size_t n);
void *s21_memmove(void *dest, const void *src, s21_size_t n);

void *s21_memset(void *str, int c, s21_size_t n);
char *s21_strchr(const char *str, int c);
char *s21_strcat(char *dest, const char *src);
char *s21_strncat(char *dest, const char *src, s21_size_t n);

int s21_strcmp(const char *str1, const char *str2);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strcpy(char *dest, const char *src);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);

s21_size_t s21_strcspn(const char *str1, const char *str2);
s21_size_t s21_strlen(const char *str);
char *s21_strpbrk(const char *str1, const char *str2);
char *s21_strerror(int errnum);

char *s21_strrchr(const char *string, int n);
s21_size_t s21_strspn(const char *str1, const char *str2);
char *s21_strstr(const char *haystack, const char *needle);
char *s21_strtok(char *str, const char *delim);

//Дополнительные функции
void *s21_to_upper(const char *str);
void *s21_to_lower(const char *str);
void *s21_insert(const char *src, const char *str, s21_size_t start_index);
void *s21_trim(const char *src, const char *trim_chars);

int s21_sscanf(const char *buff, const char *format, ...);
void int_buff_reader(const char *buff, va_list variable, int *pointer_to_string,
                     struct option *opt, const char *format, const int *i,
                     char type);
void float_buff_reader(const char *buff, va_list variable,
                       int *pointer_to_string, struct option *opt,
                       const char *format, const int *i, char type);
void integer_func(const char *buff, va_list variable, int *pointer_to_string,
                  struct option *opt, char type);
void integer_type_choice(long long int answer, va_list variable,
                         struct option *opt, char type);
void mode1_func(const char *buff, va_list variable, int *pointer_to_string,
                struct option *opt);
void mode2_func(const char *buff, va_list variable, int *pointer_to_string,
                struct option *opt);
void long_symbol(const char *buff, va_list variable, int *pointer_to_string,
                 struct option *opt);
void long_string(const char *buff, va_list variable, int *pointer_to_string,
                 struct option *opt);
void Octal_func(const char *buff, va_list variable, int *pointer_to_string,
                struct option *opt, char type);
void octal_type_choice(va_list variable, struct option *opt, char type,
                       long long int answer);
void Hex_func(const char *buff, va_list variable, int *pointer_to_string,
              struct option *opt, char type);
void Hex_type_choice(long long res, va_list variable, struct option *opt,
                     char type);
void float_reader(const char *buff, va_list variable, int *pointer_to_string,
                  struct option *opt, char type);
void float_type_choice(long double answer, va_list variable, struct option *opt,
                       char type);
void num_of_scanned_symbols(va_list variable, const int *pointer_to_string,
                            struct option *opt);
int **p_adress(const char *buff, va_list variable, int *pointer_to_string,
               struct option *opt);
void lenght_width(const char *format, struct option *opt, int *i);
int Hex_letters(char symb);

double scientific_notation(const char *buff, char aft_e[], const int *start,
                           const int *i, int *after_e, struct option *opt,
                           int sign);

void do_funk_d(char *res, int *index, long long int number, int width,
               int accuracy, struct flags fl);
void do_funk_f(char *res, int *index, long double number, int width,
               int accuracy, struct flags *fl);
int s21_sprintf(char *ptrult, char *format, ...);
void do_funk_g(char *res, int *index, long double number, int width,
               int accuracy, int dec, struct flags *fl);

void put_monitsa(char *res, int *index, double montisa, int count_for_zero,
                 int accuracy);
int get_str_from_long_int(char *str, long long int dec, int count);
void get_hex_from_dec(char *ptrult, int *index, long long int dec, int ans,
                      int ans_for_space, int decr, struct flags fl);
void eigh_to_dec(char *ptrult, int *index, long long int dec, int ans,
                 int ans_for_space, struct flags fl);
void get_lengh_and_dots(const char *format, int *ans, int *ans_for_dot, int *i,
                        va_list *ap);
void double_to_sci(char *ptrult, int *index, long double num, int ans,
                   int ans_for_space, int dec, struct flags *fl);
int float_to_int(double num, double *evenp, int flag_for_g, int *ans_for_dot,
                 int *ans, int *count_for_zero);
int digits_in_int(long long int number);
int get_e_from_double(long double *number);
int delete_all_last_zero_in_montisa(char *str, int *index, struct flags fl);
void chek_for_space(char *res, int *index, int *width, struct flags fl);

#endif  //  SRC_S21_STRING_H_
