#include "test.h"

START_TEST(test1) {
  ck_assert_ldouble_eq_tol(s21_abs(-123456789), abs(-123456789), 1e-6);
  ck_assert_ldouble_eq_tol(s21_abs(0), abs(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_abs(12345), abs(12345), 1e-6);
  ck_assert_ldouble_eq_tol(s21_abs(-1234567), abs(-1234567), 1e-6);
}
END_TEST

START_TEST(test2) {
  ck_assert_ldouble_eq_tol(s21_fabs(-123.123456), fabs(-123.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(1234567.09876), fabs(1234567.09876), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(-1234567891234567.123456),
                           fabs(-1234567891234567.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fabs(0.01), fabs(0.01), 1e-6);
  ck_assert_ldouble_infinite(s21_fabs(S21_INF));
  ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabs(0.0), 1e-6);
}
END_TEST

START_TEST(test3) {
  ck_assert_ldouble_eq_tol(s21_ceil(0.5), ceil(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-0.5), ceil(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(123456789.84256), ceil(123456789.84256),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(-123456789.34256), ceil(-123456789.34256),
                           1e-6);
  ck_assert_ldouble_eq_tol(s21_ceil(0), ceil(0), 1e-6);
  ck_assert_ldouble_infinite(s21_ceil(S21_INF));
}
END_TEST

START_TEST(test4) {
  ck_assert_ldouble_eq_tol(s21_pow(0.5, 2), pow(0.5, 2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(5, 5), pow(5, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(2, 3.123456), pow(2, 3.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(12, 3.12), pow(12, 3.12), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.55, 3), pow(0.55, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0.55, 3), pow(-0.55, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 3), pow(0, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0, 0), pow(0, 0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, 3), pow(1, 3), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -5), pow(1, -5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(0.5, S21_INF), pow(0.5, S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, S21_INF), pow(1, S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1, -S21_INF), pow(1, -S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(1.1, -S21_INF), pow(1.1, -S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-1.1, 2), pow(-1.1, 2), 1e-6);
  ck_assert_ldouble_infinite(s21_pow(0.5, -S21_INF));
  ck_assert_ldouble_eq_tol(s21_pow(-0.5, -25), pow(-0.5, -25), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-0.5, S21_INF), pow(0.5, S21_INF), 1e-6);
  ck_assert_ldouble_eq_tol(s21_pow(-1, S21_INF), pow(-1, S21_INF), 1e-6);
  ck_assert_ldouble_infinite(s21_pow(-1.1, S21_INF));
  ck_assert_ldouble_infinite(s21_pow(-0.5, -S21_INF));
}
END_TEST

START_TEST(test5) {
  ck_assert_ldouble_eq_tol(s21_sqrt(64), sqrt(64), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(2), sqrt(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(12.345), sqrt(12.345), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sqrt(991.908), sqrt(991.908), 1e-6);
  ck_assert_ldouble_nan(s21_sqrt(-99));
  ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrt(0), 1e-6);
  ck_assert_ldouble_infinite(s21_sqrt(S21_INF));
}
END_TEST

START_TEST(test6) {
  ck_assert_ldouble_eq_tol(s21_fmod(0.5, 5), fmod(0.5, 5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(34, 7), fmod(34, 7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(-7, 20), fmod(-7, 20), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(20, 7), fmod(20, 7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_fmod(0, 7), fmod(0, 7), 1e-6);
  ck_assert_ldouble_nan(s21_fmod(20, 0));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, 12));
  ck_assert_ldouble_eq_tol(s21_fmod(20, S21_INF), fmod(20, S21_INF), 1e-6);
}
END_TEST

START_TEST(test7) {
  ck_assert_ldouble_eq_tol(s21_exp(0.5), exp(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(7), exp(7), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.8), exp(0.8), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0.51235), exp(0.51235), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(0), exp(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_exp(-S21_INF), exp(-S21_INF), 1e-6);
  ck_assert_ldouble_infinite(s21_exp(S21_INF));
}
END_TEST

START_TEST(test8) {
  ck_assert_ldouble_eq_tol(s21_sin(0.5), sin(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(-0.5), sin(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(6.8), sin(6.8), 1e-6);
  ck_assert_ldouble_eq_tol(s21_sin(2.712345), sin(2.712345), 1e-6);
  ck_assert_ldouble_nan(s21_sin(S21_INF));
}
END_TEST

START_TEST(test9) {
  ck_assert_ldouble_eq_tol(s21_tan(0.5), tan(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(0), tan(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(1234.890), tan(1234.890), 1e-6);
  ck_assert_ldouble_eq_tol(s21_tan(-654321.2134), tan(-654321.2134), 1e-6);
  ck_assert_ldouble_nan(s21_tan(S21_INF));
}
END_TEST

START_TEST(test10) {
  ck_assert_ldouble_eq_tol(s21_acos(0.123456), acos(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(1), acos(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(-0.45555), acos(-0.45555), 1e-6);
  ck_assert_ldouble_eq_tol(s21_acos(0.45555), acos(0.45555), 1e-6);
  ck_assert_ldouble_nan(s21_acos(-1.5));
  ck_assert_ldouble_eq_tol(s21_acos(0), acos(0), 1e-6);
}
END_TEST

START_TEST(test11) {
  ck_assert_ldouble_eq_tol(s21_asin(0.123456), asin(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(0.999), asin(0.999), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(-0.97), asin(-0.97), 1e-6);
  ck_assert_ldouble_eq_tol(s21_asin(1), asin(1), 1e-6);
  ck_assert_ldouble_nan(s21_asin(-1.5));
  ck_assert_ldouble_eq_tol(s21_asin(0), asin(0), 1e-6);
}
END_TEST

START_TEST(test12) {
  ck_assert_ldouble_eq_tol(s21_atan(0.123456), atan(0.123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(1), atan(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(-1), atan(-1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(0.666), atan(0.666), 1e-6);
  ck_assert_ldouble_eq_tol(s21_atan(S21_INF), atan(S21_INF), 1e-6);
}
END_TEST

START_TEST(test13) {
  ck_assert_ldouble_eq_tol(s21_log(1), log(1), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(0.4), log(0.4), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(2), log(2), 1e-6);
  ck_assert_ldouble_eq_tol(s21_log(1251), log(1251), 1e-6);
  ck_assert_ldouble_nan(s21_log(-1));
  ck_assert_ldouble_infinite(s21_log(0));
  ck_assert_ldouble_infinite(s21_log(S21_INF));
}
END_TEST

START_TEST(test14) {
  ck_assert_ldouble_eq_tol(s21_cos(3.14), cos(3.14), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(-123456), cos(-123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(123456), cos(123456), 1e-6);
  ck_assert_ldouble_eq_tol(s21_cos(0), cos(0), 1e-6);
  ck_assert_ldouble_nan(s21_cos(S21_INF));
}
END_TEST

START_TEST(test15) {
  ck_assert_ldouble_eq_tol(s21_floor(0.5), floor(0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(0.99), floor(0.99), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(-0.5), floor(-0.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(123456.5), floor(123456.5), 1e-6);
  ck_assert_ldouble_eq_tol(s21_floor(0), floor(0), 1e-6);
  ck_assert_ldouble_infinite(s21_floor(S21_INF));
}
END_TEST

Suite *s21_math_test_1() {
  Suite *s = suite_create("First half");
  TCase *test_math_1;
  test_math_1 = tcase_create("All test");
  tcase_add_test(test_math_1, test1);
  tcase_add_test(test_math_1, test2);
  tcase_add_test(test_math_1, test3);
  tcase_add_test(test_math_1, test4);
  tcase_add_test(test_math_1, test5);
  tcase_add_test(test_math_1, test6);
  tcase_add_test(test_math_1, test7);
  tcase_add_test(test_math_1, test8);
  tcase_add_test(test_math_1, test9);
  tcase_add_test(test_math_1, test10);
  suite_add_tcase(s, test_math_1);
  return s;
}

Suite *s21_math_test_2() {
  Suite *ss = suite_create("Second half");
  TCase *test_math_2;
  test_math_2 = tcase_create("All test");
  tcase_add_test(test_math_2, test11);
  tcase_add_test(test_math_2, test12);
  tcase_add_test(test_math_2, test13);
  tcase_add_test(test_math_2, test14);
  tcase_add_test(test_math_2, test15);
  suite_add_tcase(ss, test_math_2);

  return ss;
}
