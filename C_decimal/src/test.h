#ifndef SRC_S21_TEST_H_
#define SRC_S21_TEST_H_

#include <check.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

#include "s21_decimal.h"

Suite *s21_decimal_test_1();
Suite *s21_decimal_test_2();
Suite *s21_decimal_test_3();
Suite *s21_decimal_test_4();
Suite *s21_decimal_test_5();
Suite *s21_decimal_test_6();
Suite *s21_decimal_test_7();
Suite *s21_decimal_test_8();
Suite *s21_decimal_test_9();
Suite *s21_decimal_test_10();
Suite *s21_decimal_test_11();
Suite *s21_decimal_test_12();
Suite *s21_decimal_test_13();
Suite *s21_decimal_test_14();
Suite *s21_decimal_test_15();
Suite *s21_decimal_test_16();

Suite *sub_suite();
Suite *add_suite();
Suite *mul_suite();
Suite *div_suite();
Suite *mod_suite();

Suite *sub_suite_1();

#endif  // SRC_S21_TEST_H_
