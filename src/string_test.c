#include "test.h"

START_TEST(mem_test) {
  char str1[50] = "abrakadabra";
  char str1_1[50] = "abrakadabra";
  char str2[] = "krekspeks";
  char str2_1[] = "krekspeks";
  char str3[100] = {0};
  char str3_1[100] = {0};

  // ck_assert_ptr_eq(memchr(str1, 68, 5), s21_memchr(str1, 68, 5));
  ck_assert_ptr_eq(memchr(str1, 98, 5), s21_memchr(str1, 98, 5));
  ck_assert_ptr_eq(memchr(str1, 'r', 50), s21_memchr(str1, 'r', 50));
  ck_assert_ptr_eq(memchr(str1, 0, 50), s21_memchr(str1, 0, 50));

  ck_assert_int_eq(memcmp(str1, str1_1, 7), s21_memcmp(str1, str1_1, 7));
  ck_assert_int_eq(memcmp(str1, str2, 3), s21_memcmp(str1, str2, 3));
  ck_assert_int_eq(memcmp(str1, str2, 0), s21_memcmp(str1, str2, 0));
  ck_assert_int_eq(memcmp(str1, str3, 3), s21_memcmp(str1, str3, 3));

  ck_assert_ptr_eq(memcpy(str3, str1, 4), s21_memcpy(str3, str1, 4));
  ck_assert_ptr_eq(memcpy(str1, str3, 4), s21_memcpy(str1, str3, 4));
  ck_assert_str_eq(memcpy(str2, str1, 5), s21_memcpy(str2_1, str1, 5));

  ck_assert_str_eq(memmove(str2, str1, 5), s21_memmove(str2, str1, 5));
  ck_assert_str_eq(memmove(str2, str1, 0), s21_memmove(str2, str1, 0));
  ck_assert_str_eq(memmove(str3, str1, 5), s21_memmove(str3_1, str1, 5));
  ck_assert_str_eq(memmove(str1, str1 + 3, 3),
                   s21_memmove(str1_1, str1_1 + 3, 3));

  ck_assert_str_eq(memset(str1, 88, 5), s21_memset(str1, 88, 5));
  ck_assert_str_eq(memset(str2, 88, 5), s21_memset(str2, 88, 5));
  ck_assert_str_eq(memset(str3, 88, 5), s21_memset(str3, 88, 5));
}
END_TEST

START_TEST(str_test) {
  char str1[50] = "abraka0\tdabra";
  char str1_1[50] = "abraka0\tdabra";
  char str2[50] = "krekspeks";
  char str2_1[50] = "krekspeks";
  char str3[100] = {0};
  char str3_1[100] = {0};
  char str4[5] = "";
  char str4_1[5] = "";
  char add1[100] = "Turky is an empire of god's nature";
  char add2[100] = "Turky is an empire of god's nature";
  char add3[15] = "nature";
  char add4[15] = "nature";

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));

  ck_assert_str_eq(strcat(str3, str2), s21_strcat(str3_1, str2));
  ck_assert_str_eq(strncat(str2, str1, 6), s21_strncat(str2_1, str1, 6));

  ck_assert_ptr_eq(strchr(str1, 'k'), s21_strchr(str1, 'k'));
  ck_assert_ptr_eq(strchr(str1, '\t'), s21_strchr(str1, '\t'));
  ck_assert_ptr_eq(strchr(str1, '\0'), s21_strchr(str1, '\0'));
  ck_assert_ptr_eq(strchr(str1, 0), s21_strchr(str1, 0));
  ck_assert_ptr_eq(strchr(str1, 56), s21_strchr(str1, 56));

  ck_assert_int_eq(strcmp(str1, str2), s21_strcmp(str1, str2));
  ck_assert_int_eq(strncmp(str1, str2, 8), s21_strncmp(str1, str2, 8));

  ck_assert_str_eq(strcpy(str3, str1), s21_strcpy(str3_1, str1));
  ck_assert_str_eq(strcpy(str3, "ABC"), s21_strcpy(str3_1, "ABC"));
  ck_assert_str_eq(strcpy(str3, ""), s21_strcpy(str3_1, ""));
  ck_assert_str_eq(strcpy(str3, str2), s21_strcpy(str3_1, str2));

  ck_assert_str_eq(strncpy(str1, str2, 8), s21_strncpy(str1_1, str2_1, 8));
  ck_assert_str_eq(strncpy(str1, str2, 50), s21_strncpy(str1_1, str2_1, 50));
  ck_assert_str_eq(strncpy(str1, str4, 50), s21_strncpy(str1_1, str4_1, 50));

  ck_assert_str_eq(strerror(21), s21_strerror(21));
  ck_assert_str_eq(strerror(69), s21_strerror(69));
  ck_assert_str_eq(strerror(0), s21_strerror(0));
  ck_assert_str_eq(strerror(1), s21_strerror(1));
  ck_assert_str_eq(strerror(-1), s21_strerror(-1));
  ck_assert_str_eq(strerror(200), s21_strerror(200));

  ck_assert_int_eq(strcspn(str1, str2), s21_strcspn(str1_1, str2_1));
  ck_assert_int_eq(strcspn(str1, str4), s21_strcspn(str1_1, str4_1));
  ck_assert_int_eq(strcspn(add1, add3), s21_strcspn(add2, add4));

  ck_assert_int_eq(strlen(str1), s21_strlen(str1_1));
  ck_assert_int_eq(strlen(str4), s21_strlen(str4_1));

  ck_assert_ptr_eq(strpbrk(str1, str2), s21_strpbrk(str1, str2_1));
  ck_assert_ptr_eq(strpbrk(str1, "QQQQQQQQQ98a"),
                   s21_strpbrk(str1, "QQQQQQQQQ98a"));
  ck_assert_ptr_eq(strpbrk(str1, str4), s21_strpbrk(str1, str4_1));
  ck_assert_ptr_eq(strpbrk(str1, "abcdef"), s21_strpbrk(str1, "abcdef"));
  ck_assert_ptr_eq(strpbrk(str1, "98a"), s21_strpbrk(str1, "98a"));

  ck_assert_ptr_eq(strrchr(str1, 'b'), s21_strrchr(str1_1, 'b'));
  ck_assert_ptr_eq(strrchr(str1, 'k'), s21_strrchr(str1_1, 'k'));
  ck_assert_ptr_eq(strrchr(str3, ' '), s21_strrchr(str3_1, ' '));
  ck_assert_ptr_eq(strrchr(str1, '\0'), s21_strrchr(str1, '\0'));

  ck_assert_int_eq(strspn(str1, str2), s21_strspn(str1_1, str2_1));
  ck_assert_int_eq(strspn(str1, str4), s21_strspn(str1_1, str4_1));
  ck_assert_int_eq(strspn(add1, add3), s21_strspn(add1, add3));

  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
  ck_assert_ptr_eq(strstr(str1, str2), s21_strstr(str1, str2));
  ck_assert_ptr_eq(strstr(str1, "ka"), s21_strstr(str1, "ka"));
  ck_assert_ptr_eq(strstr(str1, ""), s21_strstr(str1, ""));
  ck_assert_ptr_eq(strstr(str1, str4), s21_strstr(str1, str4));

  char tokstr[] =
      "bonga-janga.token,kreks-peks.libro/office-https://google.com-psy";
  char tokstr1[] =
      "bonga-janga.token,kreks-peks.libro/office-https://google.com-psy";
  char *token = strtok(tokstr, ".-/");
  char *token_s21 = s21_strtok(tokstr1, "./-");

  ck_assert_str_eq(token, token_s21);

  while (token != NULL) {
    ck_assert_str_eq(token, token_s21);

    token = strtok(NULL, ".-/");
    token_s21 = s21_strtok(s21_NULL, "./-");
  }
  char tokstr2[] =
      "bonga-janga.token,kreks-peks.libro/office-https://google.com-psy";
  char tokstr22[] =
      "bonga-janga.token,kreks-peks.libro/office-https://google.com-psy";

  token = strtok(tokstr2, "");
  token_s21 = s21_strtok(tokstr22, "");
  ck_assert_str_eq(token, token_s21);

  token = strtok(tokstr2, "a/");
  token_s21 = s21_strtok(tokstr22, "a/");
  ck_assert_str_eq(token, token_s21);

  while (token_s21 != s21_NULL) {
    ck_assert_str_eq(token, token_s21);
    token = strtok(s21_NULL, "/");
    token_s21 = s21_strtok(s21_NULL, "/");
  }

  char upper[50] = "kreks-peks123 abc";
  char lower[50] = "KREKS-PEKS123 ABC";

  ck_assert_str_eq(s21_to_upper(upper), "KREKS-PEKS123 ABC");
  ck_assert_str_eq(s21_to_lower(lower), "kreks-peks123 abc");

  char *test_1 = s21_insert(str3, str4, 5);
  ck_assert_str_eq(test_1, "krekspeksabraka");
  char *test_2 = s21_insert(str3, str2, 5);
  ck_assert_str_eq(test_2, "krekskrekspeksabrakapeksabraka");
  free(test_1);
  free(test_2);

  char abc1[] = "ABC";
  char abc2[] = "";
  char *test_8 = s21_insert(abc1, abc2, 0);
  ck_assert_str_eq(test_8, "ABC");
  char *test_9 = s21_insert(abc1, abc2, 0);
  ck_assert_str_eq(test_9, "ABC");
  free(test_8);
  free(test_9);

  char *str_trim = s21_trim("***destroyer***", "*d");
  ck_assert_str_eq(str_trim, "estroyer");
  free(str_trim);
  char *str_trim_1 = s21_trim("***destroyer***", "");
  ck_assert_str_eq(str_trim_1, "***destroyer***");
  free(str_trim_1);
}
END_TEST

// SPRINTF TESTS
START_TEST(sprintf_test) {
  // ГЛАВНЫЕ ОБЯЗАТЕЛЬНЫЕ ФЛАГИ

  char str_sprintf[2000] = {'\0'};
  char str_s21_sprintf[2000] = {'\0'};
  char symbol = 'K';
  char string_for_sprintf[] = "ABCDEF";
  int a_int = 50, b_int = -50, c_int = 0;
  unsigned int a_un_int = 50, b_un_int = 0;
  float a_float = 0.9999999, b_float = -0.9999999, c_float = 0,
        d_float = 0.123456;
  long double l_db =
      3.40987654567899876543456789876543467898765432478987654345678987654356787654098765432345689098765434567898765434567890987654345678956789765456789654567876543567876543456787654345678765432345678765434567895434789876567887654876548765434568765456789876545678909879876543888;
  short int sh_it = 134;
  long int lon_it = 123123123;
  int resultt1 = sprintf(
      str_sprintf, "%%  %s %.0f %.0f %f %f %-c %d %d %d %i %u %u %hd %ld %Lf\n",
      string_for_sprintf, a_float, b_float, c_float, d_float, symbol, a_int,
      b_int, c_int, a_int, a_un_int, b_un_int, sh_it, lon_it, l_db);

  int resultt2 = s21_sprintf(
      str_s21_sprintf,
      "%%  %s %.0f %.0f %f %f %-c %d %d %d %i %u %u %hd %ld %Lf\n",
      string_for_sprintf, a_float, b_float, c_float, d_float, symbol, a_int,
      b_int, c_int, a_int, a_un_int, b_un_int, sh_it, lon_it, l_db);

  ck_assert_str_eq(str_sprintf, str_s21_sprintf);
  ck_assert_int_eq(resultt1, resultt2);

  resultt1 = sprintf(str_sprintf,
                     "%%5 %5s %5f %5f %5f %5f %5c %5d %5d %5d %5i %5u %5u",
                     string_for_sprintf, a_float, b_float, c_float, d_float,
                     symbol, a_int, b_int, c_int, a_int, a_un_int, b_un_int);

  resultt2 = s21_sprintf(
      str_s21_sprintf, "%%5 %5s %5f %5f %5f %5f %5c %5d %5d %5d %5i %5u %5u",
      string_for_sprintf, a_float, b_float, c_float, d_float, symbol, a_int,
      b_int, c_int, a_int, a_un_int, b_un_int);

  ck_assert_str_eq(str_sprintf, str_s21_sprintf);
  ck_assert_int_eq(resultt1, resultt2);

  char rs1[1000] = {'\0'};
  char rs2[1000] = {'\0'};

  resultt1 = sprintf(rs1, "%%+ %+f %+f %+f %+f %+d %+d %+d %+i", a_float,
                     b_float, c_float, d_float, a_int, b_int, c_int, a_int);

  resultt2 = s21_sprintf(rs2, "%%+ %+f %+f %+f %+f %+d %+d %+d %+i", a_float,
                         b_float, c_float, d_float, a_int, b_int, c_int, a_int);

  ck_assert_str_eq(rs1, rs2);
  ck_assert_int_eq(resultt1, resultt2);

  resultt1 = sprintf(rs1, "%%- %-f %-f %-f %-f %-d %-d %-d %-i", a_float,
                     b_float, c_float, d_float, a_int, b_int, c_int, a_int);

  resultt2 = s21_sprintf(rs2, "%%- %-f %-f %-f %-f %-d %-d %-d %-i", a_float,
                         b_float, c_float, d_float, a_int, b_int, c_int, a_int);

  ck_assert_str_eq(str_sprintf, str_s21_sprintf);
  ck_assert_int_eq(resultt1, resultt2);

  char qwert8[1000] = {'\0'};
  char qwert9[1000] = {'\0'};

  resultt1 = sprintf(qwert8, "%% ' ' % f % f % f % d % d % d", a_float, b_float,
                     c_float, a_int, b_int, c_int);

  resultt2 = s21_sprintf(qwert9, "%% ' ' % f % f % f % d % d % d", a_float,
                         b_float, c_float, a_int, b_int, c_int);

  ck_assert_str_eq(qwert8, qwert9);
  ck_assert_int_eq(resultt1, resultt2);

  char qwert1[1000] = {'\0'};
  char qwert2[1000] = {'\0'};

  resultt1 = sprintf(
      qwert1, "%%.5 %.5s %.0f %.5f %.5f %.5f %c %.5d %.5d %.5i %.5u %.0f",
      string_for_sprintf, a_float, b_float, c_float, d_float, symbol, a_int,
      b_int, c_int, a_un_int, a_float);

  resultt2 = s21_sprintf(
      qwert2, "%%.5 %.5s %.0f %.5f %.5f %.5f %c %.5d %.5d %.5i %.5u %.0f",
      string_for_sprintf, a_float, b_float, c_float, d_float, symbol, a_int,
      b_int, c_int, a_un_int, a_float);

  ck_assert_str_eq(qwert1, qwert2);
  ck_assert_int_eq(resultt1, resultt2);

  char qwert12[1000] = {'\0'};
  char qwert22[1000] = {'\0'};

  long int a_li = 9999999, b_li = -9999999, c_li = 0;
  double a_lf = 123456.123456, b_lf = 123456.123456, c_lf = 0.0;

  resultt1 = sprintf(qwert12, "%ld %ld %ld %lf %lf %lf", a_li, b_li, c_li, a_lf,
                     b_lf, c_lf);

  resultt2 = s21_sprintf(qwert22, "%ld %ld %ld %lf %lf %lf", a_li, b_li, c_li,
                         a_lf, b_lf, c_lf);

  ck_assert_str_eq(str_sprintf, str_s21_sprintf);
  ck_assert_int_eq(resultt1, resultt2);

  // PART 3
  char stroka[80] = "%g %E qwe%G %e qwer%g  ";
  float g_int = 123;

  resultt1 = 0;
  resultt2 = 0;

  resultt1 = sprintf(qwert12, stroka, g_int, g_int, g_int, g_int, g_int);

  resultt2 = s21_sprintf(qwert22, stroka, g_int, g_int, g_int, g_int, g_int);
  ck_assert_str_eq(str_sprintf, str_s21_sprintf);
  ck_assert_int_eq(resultt1, resultt2);

  long int number9999 = 9999;

  char stroka9[80] = "%-0g %-0E qwe%-5G %e qwer%-5g %Ld ";
  resultt1 =
      sprintf(qwert12, stroka9, g_int, g_int, g_int, g_int, g_int, number9999);

  resultt2 = s21_sprintf(qwert22, stroka9, g_int, g_int, g_int, g_int, g_int,
                         number9999);
  ck_assert_str_eq(str_sprintf, str_s21_sprintf);
  ck_assert_int_eq(resultt1, resultt2);

  // basic check
  char str_result[100] = {'\0'};
  char real_str_result[100] = {'\0'};
  char *format = "%f %f %f %f";
  float n1 = 100000.0;
  float n2 = 9.999999;
  float n3 = -3.14;
  float n4 = 0.000001;
  int result = s21_sprintf(str_result, format, n1, n2, n3, n4);
  int real_result = sprintf(real_str_result, format, n1, n2, n3, n4);
  ck_assert_str_eq(str_result, real_str_result);
  ck_assert_int_eq(result, real_result);

  // precision
  char str_result_p[100] = {'\0'};
  char real_str_result_p[100] = {'\0'};
  char *format_p = "%.9f %.0f %.11f %.22f %.*f";
  float n5 = -0.000001;
  int result_p = s21_sprintf(str_result_p, format_p, n1, n2, n3, n4, 15, n5);
  int real_result_p =
      sprintf(real_str_result_p, format_p, n1, n2, n3, n4, 15, n5);
  ck_assert_str_eq(str_result_p, real_str_result_p);
  ck_assert_int_eq(result_p, real_result_p);

  // width, zero flag, align, hash
  char str_result_w[200] = {'\0'};
  char real_str_result_w[200] = {'\0'};
  char *format_w = "%#-17.9f %#-08.0f %010.11f %.1f %#*.*f";
  int result_w = s21_sprintf(str_result_w, format_w, n1, n2, n3, n4, 8, 0, n5);
  int real_result_w =
      sprintf(real_str_result_w, format_w, n1, n2, n3, n4, 8, 0, n5);
  ck_assert_str_eq(str_result_w, real_str_result_w);
  ck_assert_int_eq(result_w, real_result_w);

  // sign flags
  char str_result_s[200] = {'\0'};
  char real_str_result_s[200] = {'\0'};
  char *format_s = "%+17.9f %#08.0f %+-010.11f %+.1f % +#*.*f";
  int result_s = s21_sprintf(str_result_s, format_s, n1, n2, n3, n4, 8, 0, n5);
  int real_result_s =
      sprintf(real_str_result_s, format_s, n1, n2, n3, n4, 8, 0, n5);
  ck_assert_str_eq(str_result_s, real_str_result_s);
  ck_assert_int_eq(result_s, real_result_s);

  // long double
  char str_result_L[200] = {'\0'};
  char real_str_result_L[200] = {'\0'};
  long double n6 = 999999999.99999999999999999999;
  long double n7 = 0.00000000000000000001;
  long double n8 = -0.00000000000000001;
  char *format_L = "%30.25Lf %30.30Lf %30.20Lf";
  int result_L = s21_sprintf(str_result_L, format_L, n6, n7, n8);
  int real_result_L = sprintf(real_str_result_L, format_L, n6, n7, n8);
  ck_assert_str_eq(str_result_L, real_str_result_L);
  ck_assert_int_eq(result_L, real_result_L);
}
END_TEST

// SPRINTF FLAG e E
START_TEST(test_s21_sprintf_e_E) {
  char str_result[100] = {'\0'};
  char real_str_result[100] = {'\0'};
  char *format = "%e %e %E %E";
  float n1 = -0.001;  /// -0.000001
  float n2 = 0.9999;
  float n3 = 10000.0;
  float n4 = 314.15;
  int result = s21_sprintf(str_result, format, n1, n2, n3, n4);
  int real_result = sprintf(real_str_result, format, n1, n2, n3, n4);
  ck_assert_str_eq(str_result, real_str_result);
  ck_assert_int_eq(result, real_result);

  char str_result_zero_p[100] = {'\0'};
  char real_str_result_zero_p[100] = {'\0'};
  char *format_zero_p = "%#.0e %.0e %.0E %#.0E %.0E";
  int result_zero_p =
      s21_sprintf(str_result_zero_p, format_zero_p, n1, n2, n3, n4, n1);
  int real_result_zero_p =
      sprintf(real_str_result_zero_p, format_zero_p, n1, n2, n3, n4, n1);
  ck_assert_str_eq(str_result_zero_p, real_str_result_zero_p);
  ck_assert_int_eq(result_zero_p, real_result_zero_p);

  char str_result_p[100] = {'\0'};
  char real_str_result_p[100] = {'\0'};
  char *format_p = "%.10e %.1e %.6E %.8E %.*E";
  int result_p = s21_sprintf(str_result_p, format_p, n1, n2, n3, n4, 1, n1);
  int real_result_p =
      sprintf(real_str_result_p, format_p, n1, n2, n3, n4, 1, n1);
  ck_assert_str_eq(str_result_p, real_str_result_p);
  ck_assert_int_eq(result_p, real_result_p);

  char str_result_w[100] = {'\0'};
  char real_str_result_w[100] = {'\0'};
  char *format_w = "%15.10e %10.1e %1.6E %10.8E %*.*E";
  int result_w = s21_sprintf(str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
  int real_result_w =
      sprintf(real_str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
  ck_assert_str_eq(str_result_w, real_str_result_w);
  ck_assert_int_eq(result_w, real_result_w);

  char str_result_L[200] = {'\0'};
  char real_str_result_L[200] = {'\0'};
  long double n1l = -0.000001;
  long double n2l = 0.999;
  long double n3l = 10000.0;
  long double n4l = 314.15;
  char *format_L = "%15.10Le %10.1Le %1.6LE %10.8LE %*.*LE";
  int result_L =
      s21_sprintf(str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l);
  int real_result_L =
      sprintf(real_str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l);
  ck_assert_str_eq(str_result_L, real_str_result_L);
  ck_assert_int_eq(result_L, real_result_L);
}
// END_TEST

// SPRINTF FLAG g G
START_TEST(test_s21_sprintf_g_G) {
  char str_result[100] = {'\0'};
  char real_str_result[100] = {'\0'};
  char *format = "%+g % g %G %G";
  float n1 = 0.221;
  float n2 = 1.999;
  float n3 = 10000.0;
  float n4 = 314.15;
  float n5 = -0.0001;
  int result = s21_sprintf(str_result, format, n1, n2, n3, n4);
  int real_result = sprintf(real_str_result, format, n1, n2, n3, n4);
  ck_assert_str_eq(str_result, real_str_result);
  ck_assert_int_eq(result, real_result);

  char str_result_zero_p[100] = {'\0'};
  char real_str_result_zero_p[100] = {'\0'};
  char *format_zero_p = "%#.0g %#.0g %#.0G %#.0G %#.0G";
  int result_zero_p =
      s21_sprintf(str_result_zero_p, format_zero_p, n1, n2, n3, n4, n5);
  int real_result_zero_p =
      sprintf(real_str_result_zero_p, format_zero_p, n1, n2, n3, n4, n5);
  ck_assert_str_eq(str_result_zero_p, real_str_result_zero_p);
  ck_assert_int_eq(result_zero_p, real_result_zero_p);

  char str_result_p[100] = {'\0'};
  char real_str_result_p[100] = {'\0'};
  char *format_p = "%.10g %.1g %.6G %.8G %.*G";
  int result_p = s21_sprintf(str_result_p, format_p, n1, n2, n3, n4, 1, n1);
  int real_result_p =
      sprintf(real_str_result_p, format_p, n1, n2, n3, n4, 1, n1);
  ck_assert_str_eq(str_result_p, real_str_result_p);
  ck_assert_int_eq(result_p, real_result_p);

  char str_result_w[100] = {'\0'};
  char real_str_result_w[100] = {'\0'};
  char *format_w = "%15.10g %10.1g %1.6G %10.8G %*.*G";
  int result_w = s21_sprintf(str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
  int real_result_w =
      sprintf(real_str_result_w, format_w, n1, n2, n3, n4, 12, 1, n1);
  ck_assert_str_eq(str_result_w, real_str_result_w);
  ck_assert_int_eq(result_w, real_result_w);

  char str_result_L[200] = {'\0'};
  char real_str_result_L[200] = {'\0'};
  void *padr = &str_result_L;
  long double n1l = -0.3243;
  long double n2l = 0.999;
  long double n3l = 10000.0;
  long double n4l = 314.15;
  char *format_L = "%15.10Lg %10.1Lg %1.6LG %10.8LG %*.*LG %p";
  int result_L =
      s21_sprintf(str_result_L, format_L, n1l, n2l, n3l, n4l, 12, 1, n1l, padr);
  int real_result_L = sprintf(real_str_result_L, format_L, n1l, n2l, n3l, n4l,
                              12, 1, n1l, padr);
  ck_assert_str_eq(str_result_L, real_str_result_L);
  ck_assert_int_eq(result_L, real_result_L);

  char str_result_L1[200] = {'\0'};
  char real_str_result_L1[200] = {'\0'};
  unsigned short n1l1 = 0x4f;
  unsigned int n2l1 = +0007654;
  unsigned long n3l1 = 07654323456707;
  unsigned long n4l1 = 0xfac123ed;
  char *format_L1 = "%lu %hu %-ho %-15.10hx %10.20o %-0lx %10.8lo %*.*hX";
  int result_L1 = s21_sprintf(str_result_L1, format_L1, n3l1, n1l1, n1l1, n1l1,
                              n2l1, n3l1, n4l1, 12, 1, n1l1);
  int real_result_L1 = sprintf(real_str_result_L1, format_L1, n3l1, n1l1, n1l1,
                               n1l1, n2l1, n3l1, n4l1, 12, 1, n1l1);
  ck_assert_str_eq(str_result_L1, real_str_result_L1);
  ck_assert_int_eq(result_L1, real_result_L1);
}
END_TEST

// SSCANF TESTS
START_TEST(test_s21_sscanf) {
  char str_result[100] = {'\0'};
  char str_result_ss[100] = {'\0'};
  long double check = 0;
  long double check_ss = 0;
  int count = 0;
  int count_ss = 0;
  int int_res = -1;
  int int_res_ss = -1;
  int_res_ss =
      s21_sscanf("boba_biba_bang 456895345482131 bang bang dad in the HOUSE!!",
                 "%8s%5Lf%n", str_result_ss, &check_ss, &count_ss);
  int_res =
      sscanf("boba_biba_bang_bang 456895345482131 bang dad in the HOUSE!!",
             "%8s%5Lf%n", str_result, &check, &count);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_str_eq(str_result, str_result_ss);
  ck_assert_ldouble_eq(check, check_ss);
  ck_assert_int_eq(count, count_ss);

  char str_result_p[10] = {'\0'};
  char str_result_ss_p[10] = {'\0'};
  int_res_ss =
      s21_sscanf("boba_biba_bang 456895345482131 bang bang dad in the HOUSE!!",
                 "%8s%5Lf%n", str_result_ss, &check_ss, &count_ss);
  int_res =
      sscanf("boba_biba_bang_bang 456895345482131 bang dad in the HOUSE!!",
             "%8s%5Lf%n", str_result, &check, &count);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_str_eq(str_result_p, str_result_ss_p);

  unsigned int n1 = -1;
  unsigned int n2 = -1;
  int n3 = -1;
  int n4 = -1;
  unsigned int n1_s = -1;
  unsigned int n2_s = -1;
  int n3_s = -1;
  int n4_s = -1;
  int_res_ss = s21_sscanf("456 0x8A21B A1658 0xf340045768576", "%o %x %i%i",
                          &n1, &n2, &n3, &n4);
  int_res = sscanf("456 0x8A21B A1658 0xf340045768576", "%o %X %i%i", &n1_s,
                   &n2_s, &n3_s, &n4_s);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_int_eq(n3, n3_s);
  ck_assert_int_eq(n4, n4_s);
  ck_assert_uint_eq(n1, n1_s);
  ck_assert_uint_eq(n2, n2_s);

  short unsigned int m = -1;
  short unsigned int m2 = -1;
  short int m3 = -1;
  short int m4 = -1;
  short unsigned int m1_s = -1;
  short unsigned int m2_s = -1;
  short int m3_s = -1;
  short int m4_s = -1;

  int_res_ss = s21_sscanf("456 0x8A21B A1658 0xf340045768576", "%ho %hX %hi%hi",
                          &m, &m2, &m3, &m4);
  int_res = sscanf("456 0x8A21B A1658 0xf340045768576", "%ho %hX %hi%hi", &m1_s,
                   &m2_s, &m3_s, &m4_s);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_int_eq(m3, m3_s);
  ck_assert_int_eq(m4, m4_s);
  ck_assert_uint_eq(m, m1_s);
  ck_assert_uint_eq(m2, m2_s);

  long unsigned int b = -1;
  long unsigned int b2 = -1;
  long int b3 = -1;
  long int b4 = -1;
  long unsigned int b1_s = -1;
  long unsigned int b2_s = -1;
  long int b3_s = -1;
  long int b4_s = -1;
  long int decimal = -1;
  long int decimal_s = -1;
  int_res_ss = s21_sscanf(
      "   -076897644554    -0xfaced567   0xdec98760    "
      "076895322   -987654321   ",
      "%6lo %lX %li %li %9ld", &b, &b2, &b3, &b4, &decimal);
  int_res = sscanf(
      "   -076897644554    -0xfaced567   0xdec98760    076895322   "
      "-987654321   ",
      "%6lo %lX %li %li %9ld", &b1_s, &b2_s, &b3_s, &b4_s, &decimal_s);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_int_eq(b3, b3_s);
  ck_assert_int_eq(b4, b4_s);
  ck_assert_uint_eq(b, b1_s);
  ck_assert_uint_eq(b2, b2_s);
  ck_assert_int_eq(decimal, decimal_s);

  int a = -1;
  int a2 = -1;
  int a3 = -1;
  int a1_s = -1;
  int a2_s = -1;
  int a3_s = -1;

  int_res_ss = s21_sscanf(
      "   -076897644554    -0xfaced567   0xdec98760    "
      "076895322   -987654321   ",
      "%*o %*X %i %i %d", &a, &a2, &a3);
  int_res = sscanf(
      "   -076897644554    -0xfaced567   0xdec98760    076895322  "
      " -987654321   ",
      "%*o %*X %i %i %d", &a1_s, &a2_s, &a3_s);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_int_eq(a3, a3_s);
  ck_assert_uint_eq(a, a1_s);
  ck_assert_uint_eq(a2, a2_s);

  long double z = -1;
  float z2 = -1;
  float z3 = -1;
  long double z4 = -1;
  long double z1_s = -1;
  float z2_s = -1;
  float z3_s = -1;
  long double z4_s = -1;

  int symb_c = -1;
  int symb_c_s = -1;
  int_res_ss =
      s21_sscanf("    -3964.123456789   +0.987654   0000543    -.09876543  ",
                 "%Lf %f %f %Lf %n", &z, &z2, &z3, &z4, &symb_c);
  int_res = sscanf("    -3964.123456789   +0.987654   0000543    -.09876543  ",
                   "%Lf %f %f %Lf %n", &z1_s, &z2_s, &z3_s, &z4_s, &symb_c_s);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_int_eq(z3, z3_s);
  ck_assert_int_eq(z4, z4_s);
  ck_assert_uint_eq(z, z1_s);
  ck_assert_uint_eq(z2, z2_s);
  ck_assert_int_eq(symb_c, symb_c_s);
}
END_TEST

// SSCANF TESTS
START_TEST(test_s21_sscanf_2) {
  char str_result[100] = {'\0'};
  char str_result_ss[100] = {'\0'};
  int res = -1;
  int res_ss = -1;
  void *ptr = NULL;
  void *ptr_ss = NULL;
  char res_o = '\0';
  char res_o_ss = '\0';
  res = sscanf("5 0x18fe kjhgkwhgkjag", "%c %p %12s", &res_o, &ptr, str_result);
  res_ss = s21_sscanf("5 0x18fe kjhgkwhgkjag", "%c %p %12s", &res_o_ss, &ptr_ss,
                      str_result_ss);
  ck_assert_int_eq(res, res_ss);
  ck_assert_int_eq(res_o, res_o_ss);
  ck_assert_ptr_eq(ptr, ptr_ss);
  ck_assert_str_eq(str_result, str_result_ss);
  char str_result_2[100] = {'\0'};
  char str_result_ss_2[100] = {'\0'};
  res = sscanf("5 0x18fe kjhgkwhgkjag\t", "%% %14s ", str_result_2);
  res_ss = s21_sscanf("5 0x18fe kjhgkwhgkjag\t", "%% %14s", str_result_ss_2);
  ck_assert_int_eq(res, res_ss);
  ck_assert_str_eq(str_result, str_result_ss);

  wchar_t str_result_3[100] = {'\0'};
  wchar_t str_result_ss_3[100] = {'\0'};
  wchar_t chr = '\0';
  wchar_t chr_ss = '\0';

  res = sscanf("5 0x18fe kjhgkwhgkjag", "%lc %8ls", &chr, str_result_3);
  res_ss =
      s21_sscanf("5 0x18fekjhgkwhgkjag", "%lc %8ls", &chr_ss, str_result_ss_3);
  ck_assert_int_eq(res, res_ss);
  ck_assert_int_eq(chr, chr_ss);
  ck_assert_str_eq((char *)str_result_3, (char *)str_result_ss_3);

  unsigned short p = -1;
  long double p2 = -1;
  float p3 = -1;
  long unsigned int p4 = -1;
  short int dec = -1;

  short int dec_s = -1;
  unsigned short p1_s = -1;
  long double p2_s = -1;
  float p3_s = -1;
  long unsigned int p4_s = -1;
  float g = -1;
  float g_s = -1;
  char symb_c2 = -1;
  char symb_c_s2 = -1;
  int int_res_ss = s21_sscanf(
      "    39699786f   -0.987654   10000543    0.9876543 4521 56 544",
      " %hu %c %4Lg %E %lu %hd %g %% ", &p, &symb_c2, &p2, &p3, &p4, &dec, &g);
  int int_res =
      sscanf("    39699786f   -0.987654   10000543   0.9876543 4521 56 544",
             " %hu %c %4Lg %E %lu %hd %g %% ", &p1_s, &symb_c_s2, &p2_s, &p3_s,
             &p4_s, &dec_s, &g_s);
  ck_assert_int_eq(int_res, int_res_ss);
  ck_assert_double_eq(p3, p3_s);
  ck_assert_uint_eq(p4, p4_s);
  ck_assert_uint_eq(p, p1_s);
  ck_assert_double_eq(p2, p2_s);
  ck_assert_int_eq(symb_c2, symb_c_s2);
  ck_assert_int_eq(dec_s, dec);
  ck_assert_double_eq(g, g_s);

  long double e0 = -1;
  float f0 = -1;
  unsigned int u0 = -1;
  char c0 = '\0';
  char string_[70] = "Born to rule shall not bow to the sheep";
  long double g0 = -1;
  short int hd0 = -1;
  long double ee = -1;
  long double eee = -1;

  long double eee_ = -1;
  long double ee_ = -1;
  long double e_ = -1;
  float f_ = -1;  //
  unsigned int u_ = -1;
  char c_ = '\0';
  char string_2[70] = "Born to rule shall not bow to the sheep";
  long double g_ = -1;
  short int hd_ = -1;
  int_res_ss = s21_sscanf(
      "99999999 No_man_will_enter_the_palace_alive6606e-000010  32e+000001 "
      "-0000.   123450.-3.123554",
      "%u %34s %4hd %Lg %c %f %Lf %Lf %Lf", &u0, string_, &hd0, &g0, &c0, &f0,
      &e0, &ee, &eee);
  int_res = sscanf(
      "99999999 No_man_will_enter_the_palace_alive6606e-000010  32e+000001 "
      "-0000.   123450.-3.123554",
      "%u %34s %4hd %Lg %c %f %Lf %Lf %Lf", &u_, string_2, &hd_, &g_, &c_, &f_,
      &e_, &ee_, &eee_);
  ck_assert_int_eq(int_res_ss, int_res);
  ck_assert_uint_eq(u0, u_);
  ck_assert_str_eq(string_, string_2);
  ck_assert_int_eq(hd0, hd_);
  ck_assert_ldouble_eq_tol(g0, g_, 1e-6);
  ck_assert_int_eq(c0, c_);
  ck_assert_double_eq(f0, f_);
  ck_assert_ldouble_eq_tol(e0, e_, 1e-6);
  ck_assert_ldouble_eq_tol(ee, ee_, 1e-6);
  ck_assert_ldouble_eq_tol(eee, eee_, 1e-6);

  short int u00 = -1;
  char string_0[70] = "Born to rule shall not bow to the sheep";
  unsigned int g00 = -1;
  int hd00 = -1;
  long int ee0 = -1;
  short int eee0 = -1;
  float E = -1;

  float E1 = -1;
  short int eee_1 = -1;
  long int ee_1 = -1;
  short int u_1 = -1;
  char string_21[70] = "Born to rule shall not bow to the sheep";
  unsigned int g_1 = -1;
  int hd_1 = -1;

  int_res_ss = s21_sscanf(
      "8e-000001   0x99999fecd No_man_will_enter_the_palace_alive0666004545 "
      "+0564 +facedb -0000.   123450.-3.123554",
      "%f %hi %34s %5i %li %hi %5x", &E, &u00, string_0, &hd00, &ee0, &eee0,
      &g00);
  int_res = sscanf(
      "8e-000001   0x99999fecd No_man_will_enter_the_palace_alive0666004545 "
      "+0564 +facedb -0000.   123450.-3.123554",
      "%f %hi %34s %5i %li %hi %5x", &E1, &u_1, string_21, &hd_1, &ee_1, &eee_1,
      &g_1);
  ck_assert_int_eq(int_res_ss, int_res);
  ck_assert_uint_eq(u00, u_1);
  ck_assert_float_eq_tol(E, E1, 1e-6);
  ck_assert_str_eq(string_0, string_21);
  ck_assert_int_eq(hd00, hd_1);
  ck_assert_uint_eq(g00, g_1);
  ck_assert_int_eq(ee0, ee_1);
  ck_assert_int_eq(eee0, eee_1);

  char stringO[70] = "WE are united";
  char stringM[70] = "WE are united";

  char M_s1 = '\0';
  char M_o1 = '\0';

  char M_s2 = '\0';
  char M_o2 = '\0';

  char M_s3 = '\0';
  char M_o3 = '\0';

  char M_s4 = '\0';
  char M_o4 = '\0';

  int Gerka = -1;
  int Gerko = -1;

  int N_M = -1;
  int N_O = -1;

  float f_m = -1;
  float f_o = -1;

  char *pointM = NULL;
  char *pointO = NULL;

  int N_1 = -1;
  int N_2 = -1;

  int arr = s21_sscanf("H Sosososo 987654323.087 0x56f   ",
                       "%c%c%c%s%c %d %f%n %p %n", &M_s1, &M_s2, &M_s3, stringM,
                       &M_s4, &Gerka, &f_m, &N_M, &pointM, &N_1);
  int arr1 = sscanf("H Sosososo 987654323.087 0x56f   ",
                    "%c%c%c%s%c %d %f%n %p %n", &M_o1, &M_o2, &M_o3, stringO,
                    &M_o4, &Gerko, &f_o, &N_O, &pointO, &N_2);
  ck_assert_int_eq(arr, arr1);
  ck_assert_int_eq(M_s1, M_o1);
  ck_assert_int_eq(M_s2, M_o2);
  ck_assert_int_eq(M_s3, M_o3);
  ck_assert_int_eq(M_s4, M_o4);
  ck_assert_str_eq(stringM, stringO);
  ck_assert_int_eq(Gerka, Gerko);
  ck_assert_float_eq(f_o, f_m);
  ck_assert_int_eq(N_O, N_M);
  ck_assert_int_eq(N_1, N_2);
  ck_assert_ptr_eq(pointO, pointM);

  char M_D1 = '\0';
  char M_W1 = '\0';

  char M_D2 = '\0';
  char M_W2 = '\0';

  char M_D3 = '\0';
  char M_W3 = '\0';

  char M_D4 = '\0';
  char M_W4 = '\0';

  char solm[50] = "RiverPlate";
  char solo[50] = "RiverPlate";

  char M_D5 = '\0';
  char M_W5 = '\0';

  int arrr = s21_sscanf("F GDoM3g  55", "%c%c%4s%c %c %c", &M_D1, &M_D2, solm,
                        &M_D3, &M_D4, &M_D5);
  int arrr1 = sscanf("F GDoM3g  55", "%c%c%4s%c %c %c", &M_W1, &M_W2, solo,
                     &M_W3, &M_W4, &M_W5);
  ck_assert_int_eq(arrr, arrr1);

  ck_assert_int_eq(M_D1, M_W1);
  ck_assert_int_eq(M_D2, M_W2);

  ck_assert_str_eq(solm, solo);
  ck_assert_int_eq(M_W3, M_D3);
  ck_assert_int_eq(M_W4, M_D4);
  ck_assert_int_eq(M_D5, M_W5);
}
END_TEST

Suite *s21_string_test_1() {
  Suite *s = suite_create("First half");
  TCase *test_string_1;
  test_string_1 = tcase_create("All test");
  tcase_add_test(test_string_1, mem_test);
  suite_add_tcase(s, test_string_1);
  return s;
}
Suite *s21_string_test_2() {
  Suite *ss = suite_create("Second half");
  TCase *test_string_2;
  test_string_2 = tcase_create("All test");
  tcase_add_test(test_string_2, str_test);
  suite_add_tcase(ss, test_string_2);
  return ss;
}
Suite *s21_string_test_3() {
  Suite *sp = suite_create("Third half");
  TCase *test_string_3;
  test_string_3 = tcase_create("All test");
  tcase_add_test(test_string_3, sprintf_test);
  suite_add_tcase(sp, test_string_3);
  return sp;
}
Suite *s21_string_test_4() {
  Suite *spe = suite_create("Fourth half");
  TCase *test_string_4;
  test_string_4 = tcase_create("All test");
  tcase_add_test(test_string_4, test_s21_sprintf_e_E);
  suite_add_tcase(spe, test_string_4);
  return spe;
}
Suite *s21_string_test_5() {
  Suite *spg = suite_create("First half");
  TCase *test_string_5;
  test_string_5 = tcase_create("All test");
  tcase_add_test(test_string_5, test_s21_sprintf_g_G);
  suite_add_tcase(spg, test_string_5);
  return spg;
}
Suite *s21_string_test_6() {
  Suite *ssc = suite_create("Sixth half");
  TCase *test_string_6;
  test_string_6 = tcase_create("All test");
  tcase_add_test(test_string_6, test_s21_sscanf);
  suite_add_tcase(ssc, test_string_6);
  return ssc;
}
Suite *s21_string_test_7() {
  Suite *ssc2 = suite_create("Seventh half");
  TCase *test_string_7;
  test_string_7 = tcase_create("All test");
  tcase_add_test(test_string_7, test_s21_sscanf_2);
  suite_add_tcase(ssc2, test_string_7);
  return ssc2;
}
