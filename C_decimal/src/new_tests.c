#include "s21_decimal.h"
#include "test.h"

// два положительных числа, первое больше второго
START_TEST(basic_sub) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 532167 - 123456 = 408711;
  dec1.bits[0] = 532167;

  dec2.bits[0] = 123456;

  s21_decimal true_ans = {{0, 0, 0, 0}};
  true_ans.bits[0] = 408711;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  s21_decimal dec1_1 = {{0, 0, 0, 0}};
  s21_decimal dec2_2 = {{0, 0, 0, 0}};
  s21_decimal ans_1 = {{0, 0, 0, 0}};

  // 532167 - 123456 = 408711;
  dec1_1.bits[0] = 532167;
  dec2_2.bits[0] = 123456;
  s21_decimal true_ans_1 = {{0, 0, 0, 0}};

  true_ans_1.bits[0] = 408711;
  status = s21_sub(dec1_1, dec2_2, &ans_1);
  true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans_1, true_ans_1));
  ck_assert_int_eq(status, true_status);
}
END_TEST

// два положительных числа, второе больше первого
START_TEST(basic_sub_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 123456;
  dec2.bits[0] = 532167;
  // 123456 - 532167 = -408711;

  s21_decimal true_ans = {{0, 0, 0, 0}};
  true_ans.bits[0] = 408711;
  set_sign(&true_ans, 1);

  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  s21_decimal dec1_1 = {{0, 0, 0, 0}};
  s21_decimal dec2_1 = {{0, 0, 0, 0}};
  s21_decimal ans_1 = {{0, 0, 0, 0}};
  dec1_1.bits[0] = 123456;
  dec2_1.bits[0] = 532167;
  // 123456 - 532167 = -408711;
  s21_decimal true_ans_1 = {{0, 0, 0, 0}};

  true_ans_1.bits[0] = 408711;
  set_sign(&true_ans_1, 1);

  status = s21_sub(dec1_1, dec2_1, &ans_1);
  true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans_1, true_ans_1));
  ck_assert_int_eq(status, true_status);
}
END_TEST

// два отрицательных числа, первое по модулю больше второго
START_TEST(basic_sub_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // -532167 - (-123456) = -408711;
  dec1.bits[0] = 532167;
  set_sign(&dec1, 1);

  dec2.bits[0] = 123456;
  set_sign(&dec2, 1);

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 408711;
  set_sign(&true_ans, 1);
  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  s21_decimal dec1_1 = {{0, 0, 0, 0}};
  s21_decimal dec2_1 = {{0, 0, 0, 0}};
  s21_decimal ans_1 = {{0, 0, 0, 0}};

  // -532167 - (-123456) = -408711;
  dec1_1.bits[0] = 532167;
  set_sign(&dec1_1, 1);
  dec2_1.bits[0] = 123456;
  set_sign(&dec2_1, 1);
  s21_decimal true_ans_1 = {{0, 0, 0, 0}};

  true_ans_1.bits[0] = 408711;
  set_sign(&true_ans_1, 1);
  status = s21_sub(dec1_1, dec2_1, &ans_1);
  true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans_1, true_ans_1));
  ck_assert_int_eq(status, true_status);
}
END_TEST

// два отрицательных числа, второе по модулю больше первого
START_TEST(basic_sub_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // -61287 - (-234787) = 173500
  dec1.bits[0] = 61287;
  set_sign(&dec1, 1);

  dec2.bits[0] = 234787;
  set_sign(&dec2, 1);

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 173500;

  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  s21_decimal dec1_1 = {{0, 0, 0, 0}};
  s21_decimal dec2_1 = {{0, 0, 0, 0}};
  s21_decimal ans_1 = {{0, 0, 0, 0}};

  // -61287 - (-234787) = 173500
  dec1_1.bits[0] = 61287;
  set_sign(&dec1_1, 1);
  dec2_1.bits[0] = 234787;
  set_sign(&dec2_1, 1);
  s21_decimal true_ans_1 = {{0, 0, 0, 0}};

  true_ans_1.bits[0] = 173500;
  status = s21_sub(dec1_1, dec2_1, &ans_1);
  true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans_1, true_ans_1));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(sub_with_dot_0) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 532.167 - 0.000000000001236 = 532.166999999998764 =
  // 111 01100010 10100011 00010001 00100100 00101111 01101011 00101100

  dec1.bits[0] = 532167;
  dec1.bits[3] = 196608;  // 3 знака после запятой

  dec2.bits[0] = 1236;
  dec2.bits[3] = 983040;  // 15 знаков после запятой

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 607087404;
  true_ans.bits[1] = 123904785;
  true_ans.bits[3] = 983040;  // 18 знаков после запятой
  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(sub_with_dot_01) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 532167;
  dec1.bits[3] = 196608;  // 3 знака после запятой

  dec2.bits[0] = 0;
  dec2.bits[3] = 0;  // 15 знаков после запятой

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 532167;
  true_ans.bits[3] = 196608;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

// если знаки у чисел не совпадают, вычитание признается сложением
START_TEST(return_to_add) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // -2361234 - 48695 = -2361234 + (-48695) = 2409929
  dec1.bits[0] = 2361234;
  set_sign(&dec1, 1);

  dec2.bits[0] = 48695;

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 2409929;
  set_sign(&true_ans, 1);

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  s21_decimal dec1_1 = {{0, 0, 0, 0}};
  s21_decimal dec2_1 = {{0, 0, 0, 0}};
  s21_decimal ans_1 = {{0, 0, 0, 0}};

  // -2361234 - 48695 = -2361234 + (-48695) = 2409929
  dec1_1.bits[0] = 2361234;
  set_sign(&dec1_1, 1);
  dec2_1.bits[0] = 48695;

  s21_decimal true_ans_1 = {{0, 0, 0, 0}};

  true_ans_1.bits[0] = 2409929;
  set_sign(&true_ans_1, 1);
  status = s21_sub(dec1_1, dec2_1, &ans_1);
  true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans_1, true_ans_1));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(return_to_add_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 6347852 - (-723184) = 6347852 + 723184 = 7071036
  dec1.bits[0] = 6347852;

  dec2.bits[0] = 723184;
  set_sign(&dec2, 1);

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 7071036;

  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  s21_decimal dec1_1 = {{0, 0, 0, 0}};
  s21_decimal dec2_1 = {{0, 0, 0, 0}};
  s21_decimal ans_1 = {{0, 0, 0, 0}};

  // 6347852 - (-723184) = 6347852 + 723184 = 7071036
  dec1_1.bits[0] = 6347852;
  dec2_1.bits[0] = 723184;
  set_sign(&dec2_1, 1);
  s21_decimal true_ans_1 = {{0, 0, 0, 0}};

  true_ans_1.bits[0] = 7071036;
  status = s21_sub(dec1_1, dec2_1, &ans_1);
  true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans_1, true_ans_1));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_sub) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // пример из README
  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;

  dec2.bits[0] = 6;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = 65536;

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 4294967294;
  true_ans.bits[1] = 4294967295;
  true_ans.bits[2] = 4294967295;
  int status = s21_sub(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite* sub_suite() {
  Suite* s;
  TCase* tc_core;

  s = suite_create("sub_suite");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, basic_sub);
  tcase_add_test(tc_core, basic_sub_2);
  tcase_add_test(tc_core, basic_sub_3);
  tcase_add_test(tc_core, basic_sub_4);
  tcase_add_test(tc_core, sub_with_dot_0);
  tcase_add_test(tc_core, sub_with_dot_01);
  tcase_add_test(tc_core, return_to_add);
  tcase_add_test(tc_core, return_to_add_2);
  tcase_add_test(tc_core, big_values_sub);
  suite_add_tcase(s, tc_core);

  return s;
}

START_TEST(basic_add) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 123456;
  dec2.bits[0] = 532167;
  // 123456 + 532167 = 655623
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 655623;
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_add_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 38321;
  dec2.bits[0] = 13282;
  set_sign(&dec1, 1);
  set_sign(&dec2, 1);
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 51603;
  set_sign(&true_ans, 1);
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_add) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4238529012;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 0;
  dec2.bits[0] = 56438283;
  dec2.bits[1] = 4294967295;
  dec2.bits[2] = 4294967294;
  // 4238529012 + 56438283 = 4294967295 (максимальный int)
  // 4294967295 + 4294967295 = 8589934590 =
  // 2^33 - 2 = 1 11111111 11111111 11111111 11111110
  // единица переносится в следующий бит
  // 4294967294 + 1 = 4294967295
  // практически максимальный децимал
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 4294967295;
  true_ans.bits[1] = 4294967294;
  true_ans.bits[2] = 4294967295;
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_overflow) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4238529012;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 56438283;
  dec2.bits[1] = 4294967295;
  dec2.bits[2] = 4294967294;
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 1;  // произошло переполнение
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_add_dot) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 613478.421 + 2634871.723814 = 3248350.144814
  // 613478.421
  dec1.bits[0] = 613478421;
  dec1.bits[3] = 196608;  // точка после третьего знака
  // 2634871.723814 10 01100101  01111010 10010111 11010111 00100110
  dec2.bits[0] = 2056771366;
  dec2.bits[1] = 613;
  dec2.bits[3] = 393216;  // точка после шестого знака
  // 3248350.144814 10 11110100  01010000 11000001 10101001 00101110
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 1354869038;
  true_ans.bits[1] = 756;
  true_ans.bits[3] = 393216;  // точка после шестого знака
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_add_dot_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 613478.421 + 2634871.723814 = 3248350.144814
  // 613478.421
  dec1.bits[0] = 613478421;
  dec1.bits[3] = 196608;  // точка после третьего знака
  // 2634871.723814 10 01100101  01111010 10010111 11010111 00100110
  dec2.bits[0] = 0;
  dec2.bits[3] = 393216;  // точка после шестого знака
  // 3248350.144814 10 11110100  01010000 11000001 10101001 00101110
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 613478421;
  true_ans.bits[3] = 196608;  // точка после шестого знака
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_dot_overflow) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  // 11111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111111 =
  // 2^96 - 1 = 79228162514264337593543950335
  // 79228162514264337593543950335
  dec1.bits[3] = 196608;  // точка после третьего знака
  dec2.bits[0] = 1;
  dec2.bits[3] = 196608;  // точка после третьего знака
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 2576980378;
  true_ans.bits[1] = 2576980377;
  true_ans.bits[2] = 429496729;
  true_ans.bits[3] = 131072;
  // 79228162514264337593543950.335 + 0.01 = 79228162514264337593543950.336 =
  // 2^96 = 1 00000000 00000000 00000000 00000000
  // переполнение
  // 79228162514264337593543950.335 = 79228162514264337593543950.34
  // 79228162514264337593543950.34 =
  //  11001 10011001 10011001 10011001
  // 10011001 10011001 10011001 10011001
  // 10011001 10011001 10011001 10011010

  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(return_to_sub) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 23784103 + (-721398) = 23784103 - 721398 = 23062705
  dec1.bits[0] = 23784103;
  dec2.bits[0] = 721398;
  set_sign(&dec2, 1);
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 23062705;
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(return_to_sub_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // -74563556 + 24567653 = 24567653 - 74563556 = -49995903
  dec1.bits[0] = 74563556;
  set_sign(&dec1, 1);
  dec2.bits[0] = 24567653;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 49995903;
  set_sign(&true_ans, 1);
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_add_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967294;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = 1835008;  // точка на 28 месте
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 4294967294;
  true_ans.bits[1] = 4294967295;
  true_ans.bits[2] = 4294967295;
  // число не изменилось
  int status = s21_add(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(add_zero) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};

  dec1.bits[0] = 723947;
  dec1.bits[1] = 839204;
  dec1.bits[2] = 8239;
  dec2.bits[3] = 1835008;
  s21_decimal ans = {{0, 0, 0, 0}};

  int status = s21_add(dec1, dec2, &ans);
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 723947;
  true_ans.bits[1] = 839204;
  true_ans.bits[2] = 8239;
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite* add_suite() {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_add");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, basic_add);
  tcase_add_test(tc_core, basic_add_2);
  tcase_add_test(tc_core, big_values_add);
  tcase_add_test(tc_core, big_values_add_2);
  tcase_add_test(tc_core, big_values_overflow);
  tcase_add_test(tc_core, basic_add_dot);
  tcase_add_test(tc_core, basic_add_dot_2);
  tcase_add_test(tc_core, big_values_dot_overflow);
  tcase_add_test(tc_core, return_to_sub);
  tcase_add_test(tc_core, return_to_sub_2);
  tcase_add_test(tc_core, add_zero);
  suite_add_tcase(s, tc_core);
  return s;
}

START_TEST(short_div) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 65536;
  dec2.bits[0] = 2;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 32768;

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);

  dec1.bits[0] = 65536;
  dec2.bits[0] = 2;
  true_ans.bits[0] = 32768;
  set_sign(&dec1, 1);
  set_sign(&true_ans, 1);

  status = s21_div(dec1, dec2, &ans);

  true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 9;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 6;
  dec2.bits[3] = 65536;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 15;
  true_ans.bits[3] = 65536;

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 14;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 9;
  dec2.bits[3] = 65536;
  // 14/9 = 1.5555555555 5555555555 55555555
  // 00110010 01000011 01000001 00000100
  // 01100000 10101011 01011001 00001000
  // 11000011 10001110 00111000 11100100
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 3280877796;
  true_ans.bits[1] = 1621842184;
  true_ans.bits[2] = 843268356;
  true_ans.bits[3] = 1835008;

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_div_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 14;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 9;
  dec2.bits[3] = 65536 + 2147483648;
  // 14/(-9) = -1.5555555555 5555555555 55555556
  // 00110010 01000011 01000001 00000100
  // 01100000 10101011 01011001 00001000
  // 11000011 10001110 00111000 11100100
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};
  // 15555555555555555555555555556
  // 15555555555555555555555555555
  // 1555555555555555555555555556
  // 15555555555555555555555555550
  // 15555555555555555555555555550
  // 15555555555555555555555555551
  // 1555555555555555555555555550
  // 1555555555555555555555555551
  true_ans.bits[0] = 3280877796;
  true_ans.bits[1] = 1621842184;
  true_ans.bits[2] = 843268356;
  true_ans.bits[3] = 1835008 + 2147483648;

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(div_by_zero) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 2814903;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 0;
  dec2.bits[3] = 65536 + 2147483648;
  int status = s21_div(dec1, dec2, &ans);

  int true_status = 3;  // не надо делить на ноль
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(div_zero) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 0;
  dec1.bits[3] = 65536;
  dec2.bits[0] = 4578783;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 0;
  true_ans.bits[1] = 0;
  true_ans.bits[2] = 0;
  true_ans.bits[3] = 0;

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(result_too_big) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967294;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 1;
  dec2.bits[3] = 1179648;
  int status = s21_div(dec1, dec2, &ans);

  int true_status = 1;
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(result_too_small) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec2.bits[0] = 4294967294;
  dec2.bits[1] = 4294967295;
  dec2.bits[2] = 4294967295;
  dec1.bits[0] = 1;
  dec1.bits[3] = 1179648;

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 2;
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec1.bits[3] = 1179648;
  dec2.bits[0] = 1;
  dec2.bits[3] = 1179648;

  int status = s21_div(dec1, dec2, &ans);
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 4294967295;
  true_ans.bits[1] = 4294967295;
  true_ans.bits[2] = 4294967295;
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 4294967295;
  dec2.bits[1] = 4294967295;
  dec2.bits[2] = 4294967295;

  int status = s21_div(dec1, dec2, &ans);

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 1;
  true_ans.bits[1] = 0;
  true_ans.bits[2] = 0;
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // -278576982813512.8359044835908 / 7123984713482.41253 =
  // -39.104096094745301845239149102
  // -278576982813512.8359044835908
  // 00001001 00000000 01010101 10110100
  // 11111100 01000101 01100100 00011110
  // 01110111 00000010 11101010 01000100
  // 10000000 00001101 00000000 00000000
  dec1.bits[0] = 1996679748;
  dec1.bits[1] = 4232406046;
  dec1.bits[2] = 151016884;
  dec1.bits[3] = 2148335616;
  // 7123984713482.41253
  // 00000000 00000000 00000000 00000000
  // 00001001 11100010 11110010 10100010
  // 10011111 00111110 01000011 01100101
  // 00000000 00000101 00000000 00000000
  dec2.bits[0] = 2671657829;
  dec2.bits[1] = 165868194;
  dec2.bits[2] = 0;
  dec2.bits[3] = 327680;
  // -39.104096094745301845239149102
  // 01111110 01011010 00100110 01110000
  // 11110011 01000010 11100010 00010000
  // 00001010 10100100 00110010 00101110
  // 10000000 00011011 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 178532910;
  true_ans.bits[1] = 4081246736;
  true_ans.bits[2] = 2119837296;
  true_ans.bits[3] = 2149253120;

  int status = s21_div(dec1, dec2, &ans);
  int true_status = 0;

  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(big_values_div_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 7813912341.293481290382 / 1236128761234.217489792347 =
  // 0.0063212770273961190138049477
  // 7813912341.293481290382
  // 00000000 00000000 00000001 10100111
  // 10010111 11010001 01000010 10000110
  // 01000110 11010011 01101010 10001110
  // 00000000 00001100 00000000 00000000
  dec1.bits[0] = 1188260494;
  dec1.bits[1] = 2547073670;
  dec1.bits[2] = 423;
  dec1.bits[3] = 786432;
  // 1236128761234.217489792347
  // 00000000 00000001 00000101 11000010
  // 10101100 10100110 11001011 10100111
  // 01100010 11011001 11111101 01011011
  // 00000000 00001100 00000000 00000000
  dec2.bits[0] = 1658453339;
  dec2.bits[1] = 2896612263;
  dec2.bits[2] = 67010;
  dec2.bits[3] = 786432;
  // 0.0063212770273961190138049477
  // 00000000 00110100 01001001 11010011
  // 00100100 10011011 00101100 11110100
  // 10110010 10110011 11110011 11000101
  // 00000000 00011100 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 2998137797;
  true_ans.bits[1] = 614149364;
  true_ans.bits[2] = 3426771;
  true_ans.bits[3] = 1835008;
  // 632127702739611901380494771 ans
  // 63212770273961190138049477 true

  int status = s21_div(dec1, dec2, &ans);

  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
// 63212770273961190138049477
// 632127702739611901380494770
Suite* div_suite() {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_div");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, short_div);
  tcase_add_test(tc_core, basic_div);
  tcase_add_test(tc_core, basic_div_2);
  tcase_add_test(tc_core, basic_div_3);
  tcase_add_test(tc_core, div_by_zero);
  tcase_add_test(tc_core, div_zero);
  tcase_add_test(tc_core, result_too_small);
  tcase_add_test(tc_core, result_too_big);
  tcase_add_test(tc_core, big_values_div);
  tcase_add_test(tc_core, big_values_div_2);
  tcase_add_test(tc_core, big_values_div_3);
  tcase_add_test(tc_core, big_values_div_4);
  suite_add_tcase(s, tc_core);
  return s;
}
END_TEST

START_TEST(basic_mod) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 10;
  dec2.bits[0] = 4;
  // 10 % 4 = 2

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 2;
  int status = s21_mod(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mod_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 164471392.8219 % -2829034.112383 = 387414.303686
  // 164471392.8219
  // 00000000 00000000 00000001 01111110
  // 11110000 10010110 11100110 00011011
  // 00000000 00000100 00000000 00000000
  dec1.bits[0] = 4036421147;
  dec1.bits[1] = 382;
  dec1.bits[3] = 262144;
  // -2829034.112383
  // 00000000 00000000 00000010 10010010
  // 10101111 10010010 11000101 01111111
  // 10000000 00000110 00000000 00000000
  dec2.bits[0] = 2945631615;
  dec2.bits[1] = 658;
  dec2.bits[3] = 2147876864;
  // 387414.303686
  // 00000000 00000000 00000000 01011010
  // 00110011 10110001 00100011 11000110
  // 00000000 00000110 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 867247046;
  true_ans.bits[1] = 90;
  true_ans.bits[3] = 393216;
  int status = s21_mod(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mod_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // -1624980713402947.82193 % 85460968.29048340298 = -53115272.67168058004
  // -1624980713402947.82193
  // 00000000 00000000 00000000 00001000
  // 11001111 00011101 00011110 11101110
  // 10101100 01011010 10111100 11110001
  // 10000000 00000101 00000000 00000000
  dec1.bits[0] = 2891627761;
  dec1.bits[1] = 3474792174;
  dec1.bits[2] = 8;
  dec1.bits[3] = 2147811328;
  // 85460968.29048340298
  // 01110110 10011001 11010101 11001001
  // 01101111 10000100 10111111 01001010
  // 00000000 00001011 00000000 00000000
  dec2.bits[0] = 1870970698;
  dec2.bits[1] = 1989793225;
  dec2.bits[3] = 720896;
  // -53115272.67168058004
  // 01001001 10110110 01010101 11101000
  // 01100110 01011010 01111010 10010100
  // 10000000 00001011 00000000 00000000

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 1717205652;
  true_ans.bits[1] = 1236686312;
  true_ans.bits[3] = 720896 + 2147483648;
  int status = s21_mod(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(readme_mod) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 1;
  dec2.bits[3] = 196608;

  s21_decimal true_ans = {{0, 0, 0, 0}};
  int status = s21_mod(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));

  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(division_on_zero) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 4294967295;
  dec2.bits[0] = 0;
  dec2.bits[3] = 196608;

  int status = s21_mod(dec1, dec2, &ans);

  int true_status = 3;  // операция прошла успешно
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(division_zero) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 0;
  dec1.bits[3] = 196608;
  dec2.bits[0] = 217948;
  dec2.bits[3] = 196608;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  int status = s21_mod(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite* mod_suite() {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_mod");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, basic_mod);
  tcase_add_test(tc_core, basic_mod_2);
  tcase_add_test(tc_core, basic_mod_3);
  tcase_add_test(tc_core, readme_mod);
  tcase_add_test(tc_core, division_on_zero);
  tcase_add_test(tc_core, division_zero);
  suite_add_tcase(s, tc_core);
  return s;
}
END_TEST

START_TEST(basic_mul) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 1256;
  dec2.bits[0] = 1000;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 1256000;

  int status = s21_mul(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(basic_mul_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 125236476 * (-364287140) = -45622037665718640
  //     10100010 00010101 00000000
  // 01100100 11111110 10100001 01110000
  dec1.bits[0] = 125236476;
  dec1.bits[3] = 393216;  // точка после шестого знака
  dec2.bits[0] = 364287140;
  // отрицательное число и точка после третьего знака
  dec2.bits[3] = 2147483648 + 196608;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 1694409072;
  true_ans.bits[1] = 10622208;
  true_ans.bits[3] = 589824 + 2147483648;
  // отрицательное число с точкой после девятого знака

  int status = s21_mul(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(mul_with_overflow) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[2] = 4294967295;
  // 11111111 11111111 11111111 11111111
  // 00000000 00000000 00000000 00000000
  // 00000000 00000000 00000000 00000000

  dec2.bits[0] = 2;

  int status = s21_mul(dec1, dec2, &ans);
  int true_status = 1;
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(mul_that_still_fits) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 4294967295;
  dec1.bits[1] = 4294967295;
  dec1.bits[2] = 2147483647;
  // 01111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111111
  dec2.bits[0] = 2;
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 4294967294;
  true_ans.bits[1] = 4294967295;
  true_ans.bits[2] = 4294967295;
  // 11111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111111
  // 11111111 11111111 11111111 11111110

  int status = s21_mul(dec1, dec2, &ans);

  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(mul_with_overflow_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 0.18743623487636123781 * 0.000000046246921 =
  // 0.00000000866834874686452293246128301
  // 0.0000000086683487468645229325
  dec1.bits[0] = 137900165;
  dec1.bits[1] = 69122625;
  dec1.bits[2] = 1;
  dec1.bits[3] = 1310720;  // 20 знаков после запятой
  // 00000000 00000000 00000000 00000001
  // 00000100 00011110 10111010 01000001
  // 00001000 00111000 00110000 10000101
  // 00000000 00010100 00000000 00000000
  dec2.bits[0] = 46246921;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = 983040;
  // 00000000 00000000 00000000 00000000
  // 00000000 00000000 00000000 00000000
  // 00000010 11000001 10101100 00001001
  // 00000000 00001111 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 2090836749;
  true_ans.bits[1] = 3002702997;
  true_ans.bits[2] = 4;
  true_ans.bits[3] = 1835008;
  //  00000000 00000000 00000000 00000100
  //  10110010 11111001 10011100 10010101
  //  01111100 10011111 10100011 00001101
  //  00000000 00011100 00000000 00000000

  //  866834874686446568756
  //  86683487468645229325
  //  84654343775843443493
  //  86683487468645229324612830
  int status = s21_mul(dec1, dec2, &ans);
  int true_status = 0;

  ck_assert_int_eq(status, true_status);
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
}
END_TEST

START_TEST(mul_with_overflow_3) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 0.18743623487636123781 * 0.0000000000000001 =
  // 0.00000000000018743623487636123781
  // 0.0000000000001874362348763612
  dec1.bits[0] = 137900165;
  dec1.bits[1] = 69122625;
  dec1.bits[2] = 1;
  dec1.bits[3] = 1310720;  // 20 знаков после запятой
  // 00000000 00000000 00000000 00000001
  // 00000100 00011110 10111010 01000001
  // 00001000 00111000 00110000 10000101
  // 00000000 00010100 00000000 00000000
  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = 1048576;  // 16 знаков после запятой
  // 00000000 00000000 00000000 00000000
  // 00000000 00000000 00000000 00000000
  // 00000000 00000000 00000000 00000001
  // 00000000 00001011 00000000 00000000
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 2752641148;
  true_ans.bits[1] = 43;
  true_ans.bits[2] = 0;
  true_ans.bits[3] = 1835008;
  // 00000000 00000000 00000000 00000000
  // 00000000 00000000 00000000 00101011
  // 10100100 00010001 11111000 01111100
  // 00000000 00011100 00000000 00000000
  int status = s21_mul(dec1, dec2, &ans);
  int true_status = 0;
  ck_assert_int_eq(status, true_status);
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
}
END_TEST

START_TEST(mul_with_overflow_4) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 5;
  dec1.bits[1] = 0;
  dec1.bits[2] = 0;
  dec1.bits[3] = 3670016;  // 20 знаков после запятой

  dec2.bits[0] = 1;
  dec2.bits[1] = 0;
  dec2.bits[2] = 0;
  dec2.bits[3] = 3670016;  // 16 знаков после запятой

  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 0;
  true_ans.bits[1] = 0;
  true_ans.bits[2] = 0;
  true_ans.bits[3] = 3670016;

  int status = s21_mul(dec1, dec2, &ans);
  int true_status = 2;
  ck_assert_int_eq(status, true_status);
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));

  s21_decimal dec1_ = {{0, 0, 0, 0}};
  s21_decimal dec2_ = {{1, 0, 0, 0}};
  s21_decimal ans_ = {{0, 0, 0, 0}};
  s21_decimal true_ans_ = {{0, 0, 0, 0}};

  set_scale(&dec1_, 2);
  set_scale(&dec2_, 1);
  set_scale(&true_ans_, 3);

  set_sign(&dec1_, 1);
  // set_sign(&dec2_, 1);
  // set_sign(&true_ans_, 1);

  int status_ = s21_mul(dec1_, dec2_, &ans_);
  int true_status_ = 0;

  ck_assert_int_eq(status_, true_status_);
  ck_assert_int_eq(1, s21_is_equal(ans_, true_ans_));
}
END_TEST

Suite* mul_suite() {
  Suite* s;
  TCase* tc_core;
  s = suite_create("s21_mul");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, basic_mul);
  tcase_add_test(tc_core, basic_mul_2);
  tcase_add_test(tc_core, mul_with_overflow);
  tcase_add_test(tc_core, mul_that_still_fits);
  tcase_add_test(tc_core, mul_with_overflow_2);
  tcase_add_test(tc_core, mul_with_overflow_3);
  tcase_add_test(tc_core, mul_with_overflow_4);
  suite_add_tcase(s, tc_core);
  return s;
}

START_TEST(sub_with_dot) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  // 532.167 - 0.000000000001236 = 532.166999999998764 =
  // 111 01100010 10100011 00010001 00100100 00101111 01101011 00101100
  dec1.bits[0] = 532167;
  dec1.bits[3] = 196608;  // 3 знака после запятой
  dec2.bits[0] = 1236;
  dec2.bits[3] = 983040;  // 15 знаков после запятой
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 607087404;
  true_ans.bits[1] = 123904785;
  true_ans.bits[3] = 983040;  // 18 знаков после запятой
  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(sub_with_dot_2) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{0, 0, 0, 0}};
  s21_decimal ans = {{0, 0, 0, 0}};

  dec1.bits[0] = 532167;
  dec1.bits[3] = 196608;  // 3 знака после запятой
  dec2.bits[0] = 0;
  dec2.bits[3] = 0;  // 15 знаков после запятой
  s21_decimal true_ans = {{0, 0, 0, 0}};

  true_ans.bits[0] = 532167;
  true_ans.bits[3] = 196608;
  int status = s21_sub(dec1, dec2, &ans);
  int true_status = 0;  // операция прошла успешно
  ck_assert_int_eq(1, s21_is_equal(ans, true_ans));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite* sub_suite_1() {
  Suite* s;
  TCase* tc_core;
  s = suite_create("sub_suite");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, sub_with_dot);
  tcase_add_test(tc_core, sub_with_dot_2);
  suite_add_tcase(s, tc_core);
  return s;
}
END_TEST
