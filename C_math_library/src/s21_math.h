#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>
#define EPS 0.000000000000001
#define S21_PI 3.14159265358979323846264338327950288
#define S21_INF 1.0 / 0.0
#define S21_NaN 0.0 / 0.0

int s21_abs(int a);
long double s21_fabs(double b);
long double s21_ceil(double c);
long double s21_floor(double c);
long double s21_pow(double x, double y);
long double s21_log(double z);
long double s21_sqrt(double x);
long double s21_fmod(double x, double y);
long double s21_exp(double x);
long double s21_sin(double radians);
long double s21_cos(double radians);
long double s21_tan(double radians);
long double s21_asin(double radians);
long double s21_acos(double radians);
long double s21_atan(double radians);

#endif  //  SRC_S21_MATH_H_