#include <check.h>

#include "../smat_calc/calc_core.h"
double calc(char *str, double x);
START_TEST(basic_test_1) {
  char str[256] = "sin(30)+cos(30)-3+2*(-2)*(30%2) + 3sin(13)";
  char buff[256];
  clean_str(buff);
  find_token(str, buff);
  clean_str(str);
  To_Polish(buff, str);
  double res = calc_resutl(str, 0);
  double real = sin(30) + cos(30) - 3 + 2 * (-2) * (30 % 2) + 3 * sin(13);
  ck_assert_double_eq(res, real);
}

START_TEST(basic_test_2) {
  char str[256] = "tan(20)*acos(0.3)-asin(atan(0.1))*sqrt(144)/ln(3)";
  char buff[256];
  clean_str(buff);
  find_token(str, buff);
  clean_str(str);
  To_Polish(buff, str);
  double res = calc_resutl(str, 0);
  double real = tan(20) * acos(0.3) - asin(atan(0.1)) * sqrt(144) / log(3);
  ck_assert_double_eq(res, real);
}

START_TEST(test_x) {
  char str[256] = "sin(x)+cos(30-x)/(x-3+2*(-2))*x";
  char buff[256];
  clean_str(buff);
  find_token(str, buff);
  clean_str(str);
  To_Polish(buff, str);
  double x = 3;
  double res = 0;
  double real = 0;
  for (; x < 10000; x += 10.31) {
    res = calc_resutl(str, x);
    real = sin(x) + cos(30 - x) / (x - 3 + 2 * (-2)) *x;
    ck_assert_double_eq(res, real);
  }
}

START_TEST(error_test) {
  char str[256] = "3*";
  char buff[256];
  clean_str(buff);
  ck_assert_int_eq(0, find_token(str, buff));

  char str1[256] = "3-";
  char buff1[256];
  clean_str(buff1);
  ck_assert_int_eq(0, find_token(str1, buff1));

  char str2[256] = "3+";
  char buff2[256];
  clean_str(buff2);
  ck_assert_int_eq(0, find_token(str2, buff2));

  char str3[256] = "3/";
  char buff3[256];
  clean_str(buff3);
  ck_assert_int_eq(0, find_token(str3, buff3));

  char str4[256] = "/3";
  char buff4[256];
  clean_str(buff4);
  ck_assert_int_eq(0, find_token(str4, buff4));

  char str5[256] = "*3";
  char buff5[256];
  clean_str(buff5);
  ck_assert_int_eq(0, find_token(str5, buff5));

  char str6[256] = "+3";
  char buff6[256];
  clean_str(buff6);
  ck_assert_int_eq(0, find_token(str6, buff6));

  char str7[256] = "-3";
  char buff7[256];
  clean_str(buff7);
  ck_assert_int_eq(1, find_token(str7, buff7));

  char str8[256] = "^3";
  char buff8[256];
  clean_str(buff8);
  ck_assert_int_eq(0, find_token(str8, buff8));

  char str9[256] = "3^";
  char buff9[256];
  clean_str(buff9);
  ck_assert_int_eq(0, find_token(str9, buff9));

  int error = 0;
  char example1[150] = { "-((sin(cos(48)^(2)))/(tan(2)^(2)))+3*-6" };
  char qe[256];
  find_token(example1, qe);
  double res1 = calc(example1, 0);
  ck_assert_ldouble_eq_tol( -((sin(pow(cos(48),(2))))/(pow(tan(2),(2)))) + 3 *-6, res1, 1e-6);
  ck_assert_int_eq(0, error);

  // char example[150] = { "-(-(-((sin(cos(48)^(2)))/(tan(2)^(2))) + 3 * -6))" };
  // double res = calc(example, 0);
  // ck_assert_ldouble_eq_tol(-18.0834475532, res, 1e-6);
  // ck_assert_int_eq(0, error);

}
START_TEST(shitty_tests) {
   char example[150] = { "-(-(-((sin(cos(48)^(2)))/(tan(2)^(2)))+3*-6))" };
int error = 0;
 double res = calc(example, 0);
 ck_assert_ldouble_eq_tol(-18.0834475532, res, 1e-6);
 ck_assert_int_eq(0, error);

char example1[150] = { "-(-(((sin(cos(48)^(2)))/(tan(2)^(2)))+3*-6))" };
 res = calc(example1, 0);
ck_assert_ldouble_eq_tol(-17.9165524, res, 1e-6);
ck_assert_int_eq(0, error);

char example2[150] = {"2%((sin(cos(48)^(2)))/(tan(2)^2))"};
res = calc(example2, 0);
ck_assert_ldouble_eq_tol(0.0807062756, res, 1e-4);
ck_assert_int_eq(0, error);

char example3[150] = { "((sin(95)+cos(96))^(2))/(log(sqrt(tan(1))))"};
res = calc(example3, 0);
ck_assert_ldouble_eq_tol(2.6282352071, res, 1e-4);
ck_assert_int_eq(0, error);

char example4[150] = { "sqrt(2%((sin(cos(48)^(2)))/(tan(2)^(2))))" };
res = calc(example4, 0);
ck_assert_ldouble_eq_tol(0.2840884995, res, 1e-6);
ck_assert_int_eq(0, error);

char example5[150] = { "(5-10)*777+(25-sin(10))" };
res = calc(example5, 0);
ck_assert_ldouble_eq_tol(-3859.45597889, res, 1e-6);
ck_assert_int_eq(0, error);

char example6[150] = { "-(100*(-1))+0.000001-0.00001" };
res = calc(example6, 0);
ck_assert_ldouble_eq_tol(99.999991, res, 1e-6);
ck_assert_int_eq(0, error);

char example7[150] = { "atan(acos(asin(sin(cos(tan(log(5)))))))" };
res = calc(example7, 0);
ck_assert_ldouble_eq_tol( 0.69897000433, res, 1e-6);
ck_assert_int_eq(0, error);


char example8[150] = { "-ln(444^111)" };
res = calc(example8, 0);
ck_assert_ldouble_eq_tol(-676.63652643, res, 1e-6);
ck_assert_int_eq(0, error);

char example9[150] = { "77777777+77777*77777/200000000000000" };
res = calc(example9, 0);
ck_assert_ldouble_eq_tol(77777777, res, 1e-4);
ck_assert_int_eq(0, error);

char example10[150] = { "-(100^(-100)+tan(2)*(-5))" };
res = calc(example10, 0);
ck_assert_ldouble_eq_tol(-10.9251993163, res, 1e-6);
ck_assert_int_eq(0, error);

char example11[150] = { "-(cos(555)*asin(0.5))-777.098765*sqrt(256)" };
res = calc(example11, 0);
ck_assert_ldouble_eq_tol(-12433.3251353, res, 1e-6);
ck_assert_int_eq(0, error);

char example12[150] = { "(1/1/1/(-(sin(-(cos(-1/-ln(log(3))))))))" };
res = calc(example12, 0);
ck_assert_ldouble_eq_tol(4.63078860872, res, 1e-6);
ck_assert_int_eq(0, error);
}

int main() {
  Suite *s1 = suite_create("Calc_tests");
  TCase *tc1_1 = tcase_create("Calc_tests ");
  SRunner *sr = srunner_create(s1);
  int result;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, basic_test_1);
  tcase_add_test(tc1_1, basic_test_2);
  tcase_add_test(tc1_1, test_x);
  tcase_add_test(tc1_1, error_test);
  tcase_add_test(tc1_1, shitty_tests);

  srunner_run_all(sr, CK_ENV);
  result = srunner_ntests_failed(sr);
  srunner_free(sr);
  return result == 0 ? 0 : 1;
}

double calc(char *str, double x) {
  char str1[256];
  find_token(str, str1);
  clean_str(str);
  To_Polish(str1, str);
  return calc_resutl(str, x);
}