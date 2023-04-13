#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INT_SIZE 2147483647.0
#define MAX_UNSIGNED_INT_SIZE 4294967295.0
#define MAX_LONG_LONG_INT_SIZE 18446744073709551615.0
#define MAX_DECIMAL_SIZE 79228162514264337593543950335.0
#define MIN_DECIMAL_SIZE 1e-28
#define MAX_FLOAT_SIZE 340282346638528859811704183484516925440.0

#define S21_INF 1.0 / 0.0
#define S21_NEGATIVE_INF -1.0 / 0.0
#define S21_NaN 0.0 / 0.0

typedef struct {
  int bits[4];
} s21_decimal;
// void print_binary(s21_decimal inp);
int get_bit(s21_decimal src, int i);
void set_bit(s21_decimal *src, int i, int bit_value);
int get_sign(s21_decimal src);
void set_sign(s21_decimal *src, int sign);
void set_scale(s21_decimal *src, int scale);
int get_scale(s21_decimal src);
int shift_right(s21_decimal *dst, int number);
int shift_right_NE(s21_decimal *dst, int number);
int shift_left_NE(s21_decimal *dst, int number);
void revers_bits(s21_decimal *dec);
int upscale(s21_decimal *dst, int number);
int normalization(s21_decimal *dec_1, s21_decimal *dec_2);
s21_decimal add(s21_decimal dst, s21_decimal src, int *return_flag);
int upscale_for_div(s21_decimal *dst, int number);
void clean_dec(s21_decimal *dst);
s21_decimal div_for_trunc_and_mod(s21_decimal value_1, s21_decimal value_2,
                                  s21_decimal *div_result);
void make_dec(s21_decimal *value, char *str);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal first, s21_decimal second);
int s21_is_less_or_equal(s21_decimal first, s21_decimal second);
int s21_is_greater(s21_decimal first, s21_decimal second);
int s21_is_greater_or_equal(s21_decimal first, s21_decimal second);
int s21_is_equal(s21_decimal first, s21_decimal second);
int s21_is_not_equal(s21_decimal first, s21_decimal second);

int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);
int s21_div_10(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int logig_for_sub(s21_decimal *first, s21_decimal *second, int *b);
void s21_logic(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void bank_round(s21_decimal *dec_mod, s21_decimal *dec_five,
                s21_decimal *dec_one, s21_decimal *result, int *error);
#endif  //  SRC_S21_DECIMAL_H_
