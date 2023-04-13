#include "test.h"

//СЛОЖЕНИЕ
START_TEST(test1) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  s21_decimal res;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "0");
  make_dec(&test_value_2, "0101011");
  make_dec(&res_comp, "0101011");
  s21_add(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1,
           "1111111111111111111111111111111111111111111111111111111111111111111"
           "11111111111111111111111111111");
  set_scale(&test_value_1, 28);
  make_dec(&test_value_2, "0");
  set_scale(&res_comp, 28);
  make_dec(&res_comp,
           "1111111111111111111111111111111111111111111111111111111111111111111"
           "11111111111111111111111111111");
  int result = s21_add(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
  ck_assert_int_eq(result, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "0101110001010");
  set_sign(&test_value_1, 1);
  make_dec(&test_value_2, "10101111100011");
  make_dec(&res_comp, "10000001011001");
  s21_add(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "0101110001010");
  make_dec(&test_value_2, "10101111100011");
  make_dec(&res_comp, "11011101101101");
  s21_add(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  make_dec(&res_comp, "1101110");
  set_scale(&test_value_1, 4);
  set_scale(&test_value_2, 3);
  set_scale(&res_comp, 4);
  s21_add(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
}

//СРАВНЕНИЕ РАВЕНСТВО
START_TEST(test2) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 3);

  int i = s21_is_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1111001110111011010");
  make_dec(&test_value_2, "1111001110111011010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 3);

  i = s21_is_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1111001110111011010");
  make_dec(&test_value_2, "1111001110111011010");
  set_scale(&test_value_1, 1);
  set_scale(&test_value_2, 3);

  i = s21_is_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);
}

//СРАВНЕНИЕ БОЛЬШЕ
START_TEST(test3) {
  int i = 0;
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 5);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "11101111110111011010101");
  make_dec(&test_value_2, "1101111110111011010101");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1101111110111011010101");
  make_dec(&test_value_2, "11101111110111011010101");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "0101");
  make_dec(&test_value_2, "11101111110111011010101");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);

  set_sign(&test_value_2, 1);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "11101111110111011010101");
  make_dec(&test_value_2, "10101");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);

  set_sign(&test_value_1, 1);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "11101111110111011010101");
  make_dec(&test_value_2, "10101");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);

  set_sign(&test_value_1, 1);
  set_sign(&test_value_2, 1);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1");
  make_dec(&test_value_2, "11101111110111011010101");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);

  set_sign(&test_value_1, 1);
  set_sign(&test_value_2, 1);
  i = s21_is_greater(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);
}

//СРАВНЕНИЕ БОЛЬШЕ ИЛИ РАВНО
START_TEST(test4) {
  int i = 0;
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 5);
  i = s21_is_greater_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 5);
  i = s21_is_greater_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 3);
  i = s21_is_greater_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1111011010101011011110101111010");
  make_dec(&test_value_2, "11110101011101101101110101101010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_greater_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1111011010101011011110101111010");
  make_dec(&test_value_2, "10101011101101101110101101010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_greater_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);
}

//СРАВНЕНИЕ  МЕНЬШЕ
START_TEST(test5) {
  int i = 0;
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 5);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "101101");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  set_sign(&test_value_1, 1);
  set_sign(&test_value_2, 1);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_sign(&test_value_1, 1);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_sign(&test_value_2, 1);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "11111010");
  make_dec(&test_value_2, "11111010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 3);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "11111010");
  make_dec(&test_value_2, "11111010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 5);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111111010111110101011010");
  make_dec(&test_value_2, "111010101010101010101011111111100101111");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111010101010101010101011111111100101111");
  make_dec(&test_value_2, "111111010111110101011010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_less(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);
}

//МЕНЬШЕ ИЛИ РАВНО
START_TEST(test6) {
  int i = 0;
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 6);
  set_scale(&test_value_2, 5);
  i = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111101010010101011010");
  make_dec(&test_value_2, "111110101010011010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 5);
  i = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1111");
  make_dec(&test_value_2, "1111");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 5);
  i = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010010101011010");
  make_dec(&test_value_2, "111110101010011010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111110101010011010");
  make_dec(&test_value_2, "111110101010011010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 3);
  i = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111110101010011010");
  make_dec(&test_value_2, "111110101010011010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 5);
  i = s21_is_less_or_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);
}

//СРАВНЕНИЕ НЕ РАВНО
START_TEST(test7) {
  int i = 0;
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 5);
  set_scale(&test_value_2, 5);
  i = s21_is_not_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "1010");
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_1, 3);
  set_scale(&test_value_2, 5);
  i = s21_is_not_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111111001101111011110111011010");
  make_dec(&test_value_2, "111111001101111011110111011010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_not_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111111001101111011110111011010");
  make_dec(&test_value_2, "11111100110111111011110111011010");
  set_scale(&test_value_1, 0);
  set_scale(&test_value_2, 0);
  i = s21_is_not_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  make_dec(&test_value_1, "111111001101111011110111011010");
  make_dec(&test_value_2, "111111001101111011110111011010");
  set_scale(&test_value_1, 1);
  set_scale(&test_value_2, 0);
  i = s21_is_not_equal(test_value_1, test_value_2);
  ck_assert_int_eq(i, 1);
}

//ПЕРЕВОД ИЗ ИНТ В ДЕЦИМАЛ
START_TEST(test8) {
  int i = 123456789;
  s21_decimal test_value_1;
  clean_dec(&test_value_1);
  s21_from_int_to_decimal(i, &test_value_1);
  ck_assert_int_eq(i, test_value_1.bits[0]);
  i = 0;

  clean_dec(&test_value_1);
  s21_from_int_to_decimal(i, &test_value_1);
  ck_assert_int_eq(i, test_value_1.bits[0]);
  ck_assert_int_eq(0, get_sign(test_value_1));
  i = -1;

  clean_dec(&test_value_1);
  s21_from_int_to_decimal(i, &test_value_1);
  ck_assert_int_eq(-i, test_value_1.bits[0]);
  ck_assert_int_eq(1, get_sign(test_value_1));
}

//ПЕРЕВОД  ИЗ ФЛОАТ В ДЕЦИМАЛ
START_TEST(test9) {
  float i = 8.1234567;
  float ii;
  s21_decimal test_value_1;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&res_comp);
  s21_from_float_to_decimal(i, &test_value_1);
  s21_from_decimal_to_float(test_value_1, &ii);
  ck_assert_float_eq(i, ii);

  i = 0.1234567;
  clean_dec(&test_value_1);
  clean_dec(&res_comp);
  s21_from_float_to_decimal(i, &test_value_1);
  s21_from_decimal_to_float(test_value_1, &ii);
  ck_assert_float_eq(i, ii);
}

//ПЕРЕВОД ИЗ ДЕЦИМАЛ В ФЛОАТ
START_TEST(test10) {
  float i = 0;
  float ik = 8.11;
  s21_decimal test_value_1;
  clean_dec(&test_value_1);
  make_dec(&test_value_1, "1100101011");
  set_scale(&test_value_1, 2);
  s21_from_decimal_to_float(test_value_1, &i);
  ck_assert_float_eq(i, ik);
}

//ПЕРЕВОД  ИЗ ДЕЦИМАЛ В ИНТ
START_TEST(test11) {
  int i = 0;
  s21_decimal test_value_1;
  clean_dec(&test_value_1);
  make_dec(&test_value_1, "11001010111111110111011111011");
  s21_from_decimal_to_int(test_value_1, &i);
  ck_assert_float_eq(i, 425717499);

  clean_dec(&test_value_1);
  make_dec(&test_value_1, "0");
  s21_from_decimal_to_int(test_value_1, &i);
  ck_assert_float_eq(i, 0);
  clean_dec(&test_value_1);
  make_dec(&test_value_1, "11001010111111110111011111011");
  set_sign(&test_value_1, 1);
  s21_from_decimal_to_int(test_value_1, &i);
  ck_assert_float_eq(i, -425717499);
}

// ВЫЧИТАНИЕ
START_TEST(test12) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  s21_decimal res;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "101011");
  make_dec(&test_value_2, "101011");
  make_dec(&res_comp, "0");
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11111111111111111111111111111111");
  make_dec(&test_value_2, "10100000000000000000000000000000");
  make_dec(&res_comp, "01011111111111111111111111111111");
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1,
           "1111111111111111111111111111111111111111111111111111111111111111111"
           "11111111111111111111111111111");
  make_dec(&test_value_2,
           "1010000000000000000000000000000000000000000000000000000000000000000"
           "00000000000000000000000000000");
  make_dec(&res_comp,
           "0101111111111111111111111111111111111111111111111111111111111111111"
           "11111111111111111111111111111");
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1111110101010101010101010");
  make_dec(&test_value_2, "1010110101011011010110");
  make_dec(&res_comp, "1110011110101001111010100");
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1010110101011011010110");
  make_dec(&test_value_2, "1111110101010101010101010");
  make_dec(&res_comp, "1110011110101001111010100");
  set_sign(&res_comp, 1);
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1111110101010101010101010");
  make_dec(&test_value_2, "1010110101011011010110");
  set_sign(&test_value_1, 1);
  make_dec(&res_comp, "10001001100000000110000000");
  set_sign(&res_comp, 1);
  s21_sub(test_value_1, test_value_2, &res);

  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1111110101010101010101010");
  make_dec(&test_value_2, "1010110101011011010110");
  set_sign(&test_value_1, 1);
  make_dec(&res_comp, "10001001100000000110000000");
  set_sign(&res_comp, 1);
  s21_sub(test_value_1, test_value_2, &res);

  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "10");
  set_scale(&test_value_1, 0);
  make_dec(&test_value_2, "10");
  set_scale(&test_value_2, 1);

  make_dec(&res_comp, "10010");
  set_scale(&res_comp, 1);
  s21_sub(test_value_1, test_value_2, &res);

  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11101001");
  set_scale(&test_value_1, 2);
  make_dec(&test_value_2, "10");
  set_scale(&test_value_2, 0);
  make_dec(&res_comp, "100001");
  set_scale(&res_comp, 2);
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11101001");
  set_scale(&test_value_1, 2);
  make_dec(&test_value_2, "10");
  set_scale(&test_value_2, 0);
  make_dec(&res_comp, "100001");
  set_scale(&res_comp, 2);
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1,
           "11010101011101010101101001010111111111");  // 229199222.271
  set_scale(&test_value_1, 3);
  make_dec(&test_value_2, "1110101010101011010101011011");  // 2.46068571
  set_scale(&test_value_2, 8);
  make_dec(&res_comp,
           "101000101101101100011000010111111110101100001000000010"
           "1");  // 229199219.81031429
  set_scale(&res_comp, 8);
  s21_sub(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
}

// УМНОЖЕНИЕ
START_TEST(test13) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  s21_decimal res;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11101010");
  make_dec(&test_value_2, "11110");
  make_dec(&res_comp, "1101101101100");
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1");
  make_dec(&test_value_2, "1");
  make_dec(&res_comp, "1");
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1000");
  make_dec(&test_value_2, "1010");
  make_dec(&res_comp, "1010000");
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "111101010101010101011");
  make_dec(&test_value_2, "0");
  make_dec(&res_comp, "0");
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "0");
  make_dec(&test_value_2, "101010101010101010101");
  make_dec(&res_comp, "0");
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1101010101");
  set_sign(&test_value_1, 1);
  make_dec(&test_value_2, "11010100101010101");
  make_dec(&res_comp, "101100010010011100000111001");
  set_sign(&res_comp, 1);
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11010101011101010101101001010");
  make_dec(&test_value_2, "11101010101010110101010110");
  set_sign(&test_value_2, 1);
  make_dec(&res_comp,
           "1100001110101100001000010011101100100101000110011011100");
  set_sign(&res_comp, 1);
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1010");
  set_scale(&test_value_1, 0);
  make_dec(&test_value_2, "1");
  set_scale(&test_value_2, 1);
  make_dec(&res_comp, "1010");
  set_scale(&res_comp, 1);
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1101001110001010100");
  set_scale(&test_value_1, 3);
  make_dec(&test_value_2, "100100111111010110111011");
  set_scale(&test_value_2, 4);
  make_dec(&res_comp, "111101001000011100101011001001010101011100");
  set_scale(&res_comp, 7);
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1101001110001010100");
  set_scale(&test_value_1, 3);
  set_sign(&test_value_1, 1);
  make_dec(&test_value_2, "100100111111010110111011");
  set_scale(&test_value_2, 4);
  make_dec(&res_comp, "111101001000011100101011001001010101011100");
  set_scale(&res_comp, 7);
  set_sign(&res_comp, 1);
  s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1101001110001010100");
  set_scale(&test_value_1, 3);
  set_sign(&test_value_2, 1);
  make_dec(&test_value_2, "100100111111010110111011");
  set_scale(&test_value_2, 4);
  make_dec(&res_comp, "111101001000011100101011001001010101011100");
  set_scale(&res_comp, 7);
  set_sign(&res_comp, 1);
  int j = s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
  ck_assert_int_eq(j, 0);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1,
           "1101001110001010100111010101110111110110110101010101010101010101011"
           "1111111111");
  set_scale(&test_value_1, 0);
  set_sign(&test_value_2, 0);
  make_dec(&test_value_2, "100100111111010110111011111111111111");
  set_scale(&test_value_2, 0);
  j = s21_mul(test_value_1, test_value_2, &res);
  ck_assert_int_eq(j, 1);
}

// ДЕЛЕНИЕ
START_TEST(test14) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  s21_decimal res;
  s21_decimal res_comp;

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "101");  // 5
  set_scale(&test_value_1, 0);
  make_dec(&test_value_2, "10");  // 2
  set_scale(&test_value_2, 0);
  make_dec(&res_comp, "11001");  // 25
  set_scale(&res_comp, 1);
  s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1100100");
  make_dec(&test_value_2, "1010");
  make_dec(&res_comp, "1010");
  s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1101000");
  make_dec(&test_value_2, "10");
  make_dec(&res_comp, "110100");
  s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1010");
  set_scale(&test_value_1, 0);
  make_dec(&test_value_2, "11001");
  set_scale(&test_value_2, 1);
  make_dec(&res_comp, "100");
  s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1011");
  set_scale(&test_value_1, 1);
  make_dec(&test_value_2, "1010");
  set_scale(&test_value_2, 2);
  make_dec(&res_comp, "1011");
  s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1010");
  set_scale(&test_value_1, 0);
  make_dec(&test_value_2, "11001");
  set_sign(&test_value_2, 1);
  set_scale(&test_value_2, 1);
  make_dec(&res_comp, "100");
  set_sign(&res_comp, 1);
  s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1,
           "1010101011010100101011011111110110101010101010110110101101111011010"
           "1011");
  set_scale(&test_value_1, 0);
  make_dec(&test_value_2, "0");
  int j = s21_div(test_value_1, test_value_2, &res);
  ck_assert_int_eq(j, 3);
}

START_TEST(test15) {
  s21_decimal test_value_1;
  s21_decimal res;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11101011");
  set_scale(&test_value_1, 1);
  make_dec(&res_comp, "10111");
  set_scale(&res_comp, 0);
  s21_floor(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11101011");
  set_scale(&test_value_1, 1);
  set_sign(&test_value_1, 1);
  make_dec(&res_comp, "11000");
  set_sign(&res_comp, 1);
  set_scale(&res_comp, 0);
  s21_floor(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "11101011");
  set_scale(&test_value_1, 1);
  make_dec(&res_comp, "10111");
  set_scale(&res_comp, 0);
  s21_floor(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1100010101");
  set_scale(&test_value_1, 2);
  make_dec(&res_comp, "1000");
  set_scale(&res_comp, 0);
  s21_round(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1001011");
  set_scale(&test_value_1, 1);
  make_dec(&res_comp, "1000");
  set_scale(&res_comp, 0);
  s21_round(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "100101");
  set_scale(&test_value_1, 1);
  set_sign(&test_value_1, 1);
  make_dec(&res_comp, "100");
  set_scale(&res_comp, 0);
  set_sign(&res_comp, 1);
  s21_round(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "100101");
  set_scale(&test_value_1, 1);
  set_sign(&test_value_1, 1);
  make_dec(&res_comp, "11");
  set_scale(&res_comp, 0);
  set_sign(&res_comp, 1);
  s21_truncate(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "100101");
  set_scale(&test_value_1, 1);
  set_sign(&test_value_1, 1);
  make_dec(&res_comp, "100101");
  set_scale(&res_comp, 1);
  set_sign(&res_comp, 0);
  s21_negate(test_value_1, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
}

START_TEST(test16) {
  s21_decimal test_value_1;
  s21_decimal test_value_2;
  s21_decimal res;
  s21_decimal res_comp;
  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1100100");
  make_dec(&test_value_2, "10");
  make_dec(&res_comp, "0");
  s21_mod(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);

  clean_dec(&test_value_1);
  clean_dec(&test_value_2);
  clean_dec(&res);
  clean_dec(&res_comp);
  make_dec(&test_value_1, "1001001011000110001100100001001");
  make_dec(&test_value_2, "101000001");
  make_dec(&res_comp, "1101110");
  s21_mod(test_value_1, test_value_2, &res);
  ck_assert_int_eq(res.bits[0], res_comp.bits[0]);
  ck_assert_int_eq(res.bits[1], res_comp.bits[1]);
  ck_assert_int_eq(res.bits[2], res_comp.bits[2]);
  ck_assert_int_eq(res.bits[3], res_comp.bits[3]);
}

Suite *s21_decimal_test_1() {
  Suite *suite = suite_create("TEST 1");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test1);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_2() {
  Suite *suite = suite_create("TEST 2");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test2);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_3() {
  Suite *suite = suite_create("TEST 3");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test3);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_4() {
  Suite *suite = suite_create("TEST 4");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test4);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_5() {
  Suite *suite = suite_create("TEST 5");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test5);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_6() {
  Suite *suite = suite_create("TEST 6");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test6);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_7() {
  Suite *suite = suite_create("TEST 7");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test7);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_8() {
  Suite *suite = suite_create("TEST 8");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test8);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_9() {
  Suite *suite = suite_create("TEST 9");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test9);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_10() {
  Suite *suite = suite_create("TEST 10");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test10);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_11() {
  Suite *suite = suite_create("TEST 11");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test11);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_12() {
  Suite *suite = suite_create("TEST 12");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test12);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_13() {
  Suite *suite = suite_create("TEST 13");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test13);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
Suite *s21_decimal_test_14() {
  Suite *suite = suite_create("TEST 14");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test14);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_15() {
  Suite *suite = suite_create("TEST 15");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test15);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}

Suite *s21_decimal_test_16() {
  Suite *suite = suite_create("TEST 16");
  TCase *test_decimal_1 = tcase_create("all test");
  tcase_add_test(test_decimal_1, test16);
  suite_add_tcase(suite, test_decimal_1);
  return suite;
}
