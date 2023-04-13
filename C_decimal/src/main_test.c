#include "s21_decimal.h"
#include "test.h"

int main() {
  int no_failed = 0;
  setlocale(LC_ALL, "en_US.UTF-8");

  Suite *suite = s21_decimal_test_1("TEST");
  SRunner *test_decimal_1 = srunner_create(suite);
  srunner_set_fork_status(test_decimal_1, CK_NOFORK);
  srunner_run_all(test_decimal_1, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_1);
  srunner_free(test_decimal_1);

  Suite *suite1 = s21_decimal_test_2("TEST");
  SRunner *test_decimal_2 = srunner_create(suite1);
  srunner_set_fork_status(test_decimal_2, CK_NOFORK);
  srunner_run_all(test_decimal_2, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_2);
  srunner_free(test_decimal_2);

  Suite *suite2 = s21_decimal_test_3("TEST");
  SRunner *test_decimal_3 = srunner_create(suite2);
  srunner_set_fork_status(test_decimal_3, CK_NOFORK);
  srunner_run_all(test_decimal_3, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_3);
  srunner_free(test_decimal_3);

  Suite *suite3 = s21_decimal_test_4("TEST");
  SRunner *test_decimal_4 = srunner_create(suite3);
  srunner_set_fork_status(test_decimal_4, CK_NOFORK);
  srunner_run_all(test_decimal_4, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_4);
  srunner_free(test_decimal_4);

  Suite *suite4 = s21_decimal_test_5("TEST");
  SRunner *test_decimal_5 = srunner_create(suite4);
  srunner_set_fork_status(test_decimal_5, CK_NOFORK);
  srunner_run_all(test_decimal_5, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_5);
  srunner_free(test_decimal_5);

  Suite *suite5 = s21_decimal_test_6("TEST");
  SRunner *test_decimal_6 = srunner_create(suite5);
  srunner_set_fork_status(test_decimal_6, CK_NOFORK);
  srunner_run_all(test_decimal_6, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_6);
  srunner_free(test_decimal_6);

  Suite *suite6 = s21_decimal_test_7("TEST");
  SRunner *test_decimal_7 = srunner_create(suite6);
  srunner_set_fork_status(test_decimal_7, CK_NOFORK);
  srunner_run_all(test_decimal_7, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_7);
  srunner_free(test_decimal_7);

  Suite *suite7 = s21_decimal_test_8("TEST");
  SRunner *test_decimal_8 = srunner_create(suite7);
  srunner_set_fork_status(test_decimal_8, CK_NOFORK);
  srunner_run_all(test_decimal_8, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_8);
  srunner_free(test_decimal_8);

  Suite *suite8 = s21_decimal_test_9("TEST");
  SRunner *test_decimal_9 = srunner_create(suite8);
  srunner_set_fork_status(test_decimal_9, CK_NOFORK);
  srunner_run_all(test_decimal_9, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_9);
  srunner_free(test_decimal_9);

  Suite *suite9 = s21_decimal_test_10("TEST");
  SRunner *test_decimal_10 = srunner_create(suite9);
  srunner_set_fork_status(test_decimal_10, CK_NOFORK);
  srunner_run_all(test_decimal_10, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_10);
  srunner_free(test_decimal_10);

  Suite *suite10 = s21_decimal_test_11("TEST");
  SRunner *test_decimal_11 = srunner_create(suite10);
  srunner_set_fork_status(test_decimal_11, CK_NOFORK);
  srunner_run_all(test_decimal_11, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_11);
  srunner_free(test_decimal_11);

  Suite *suite12 = s21_decimal_test_12("TEST");
  SRunner *test_decimal_12 = srunner_create(suite12);
  srunner_set_fork_status(test_decimal_12, CK_NOFORK);
  srunner_run_all(test_decimal_12, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_12);
  srunner_free(test_decimal_12);

  Suite *suite13 = s21_decimal_test_13("TEST");
  SRunner *test_decimal_13 = srunner_create(suite13);
  srunner_set_fork_status(test_decimal_13, CK_NOFORK);
  srunner_run_all(test_decimal_13, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_13);
  srunner_free(test_decimal_13);

  Suite *suite14 = s21_decimal_test_14("TEST");
  SRunner *test_decimal_14 = srunner_create(suite14);
  srunner_set_fork_status(test_decimal_14, CK_NOFORK);
  srunner_run_all(test_decimal_14, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_14);
  srunner_free(test_decimal_14);

  Suite *suite15 = s21_decimal_test_15("TEST");
  SRunner *test_decimal_15 = srunner_create(suite15);
  srunner_set_fork_status(test_decimal_15, CK_NOFORK);
  srunner_run_all(test_decimal_15, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_15);
  srunner_free(test_decimal_15);

  Suite *suite16 = s21_decimal_test_16("TEST");
  SRunner *test_decimal_16 = srunner_create(suite16);
  srunner_set_fork_status(test_decimal_16, CK_NOFORK);
  srunner_run_all(test_decimal_16, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_16);
  srunner_free(test_decimal_16);

  Suite *suite19 = mul_suite("TEST");
  SRunner *test_decimal_19 = srunner_create(suite19);
  srunner_set_fork_status(test_decimal_19, CK_NOFORK);
  srunner_run_all(test_decimal_19, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_19);
  srunner_free(test_decimal_19);

  Suite *suite17 = div_suite("TEST");
  SRunner *test_decimal_17 = srunner_create(suite17);
  srunner_set_fork_status(test_decimal_17, CK_NOFORK);
  srunner_run_all(test_decimal_17, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_17);
  srunner_free(test_decimal_17);

  Suite *suite18 = mod_suite("TEST");
  SRunner *test_decimal_18 = srunner_create(suite18);
  srunner_set_fork_status(test_decimal_18, CK_NOFORK);
  srunner_run_all(test_decimal_18, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_18);
  srunner_free(test_decimal_18);

  Suite *suite20 = sub_suite_1("TEST");
  SRunner *test_decimal_20 = srunner_create(suite20);
  srunner_set_fork_status(test_decimal_20, CK_NOFORK);
  srunner_run_all(test_decimal_20, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_20);
  srunner_free(test_decimal_20);

  Suite *suite21 = sub_suite("TEST");
  SRunner *test_decimal_21 = srunner_create(suite21);
  srunner_set_fork_status(test_decimal_21, CK_NOFORK);
  srunner_run_all(test_decimal_21, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_21);
  srunner_free(test_decimal_21);

  Suite *suite22 = add_suite("TEST");
  SRunner *test_decimal_22 = srunner_create(suite22);
  srunner_set_fork_status(test_decimal_22, CK_NOFORK);
  srunner_run_all(test_decimal_22, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_decimal_22);
  srunner_free(test_decimal_22);

  return (no_failed < 4) ? EXIT_SUCCESS : EXIT_FAILURE;
}
