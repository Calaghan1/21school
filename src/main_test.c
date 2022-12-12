#include <check.h>

#include "./s21_string.h"
#include "./test.h"

int main() {
  setlocale(LC_ALL, "en_US.UTF-8");
  int no_failed = 0;

  Suite *first = s21_string_test_1("TEST");
  SRunner *test_string_1;
  test_string_1 = srunner_create(first);
  srunner_set_fork_status(test_string_1, CK_NOFORK);
  srunner_run_all(test_string_1, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_1);
  srunner_free(test_string_1);
  //---------------------------------------
  Suite *sec = s21_string_test_2("TEST");
  SRunner *test_string_2;
  test_string_2 = srunner_create(sec);
  srunner_set_fork_status(test_string_2, CK_NOFORK);
  srunner_run_all(test_string_2, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_2);
  srunner_free(test_string_2);
  // ---------------------------------------
  Suite *third = s21_string_test_3("TEST");
  SRunner *test_string_3;
  test_string_3 = srunner_create(third);
  srunner_set_fork_status(test_string_3, CK_NOFORK);
  srunner_run_all(test_string_3, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_3);
  srunner_free(test_string_3);
  // ---------------------------------------/
  Suite *fourth = s21_string_test_4("TEST");
  SRunner *test_string_4;
  test_string_4 = srunner_create(fourth);
  srunner_set_fork_status(test_string_4, CK_NOFORK);
  srunner_run_all(test_string_4, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_4);
  srunner_free(test_string_4);
  // ---------------------------------------
  Suite *fith = s21_string_test_5("TEST");
  SRunner *test_string_5;
  test_string_5 = srunner_create(fith);
  srunner_set_fork_status(test_string_5, CK_NOFORK);
  srunner_run_all(test_string_5, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_5);
  srunner_free(test_string_5);
  // ---------------------------------------
  Suite *sixth = s21_string_test_6("TEST");
  SRunner *test_string_6;
  test_string_6 = srunner_create(sixth);
  srunner_set_fork_status(test_string_6, CK_NOFORK);
  srunner_run_all(test_string_6, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_6);
  srunner_free(test_string_6);
  // ---------------------------------------
  Suite *seventh = s21_string_test_7("TEST");
  SRunner *test_string_7;
  test_string_7 = srunner_create(seventh);
  srunner_set_fork_status(test_string_7, CK_NOFORK);
  srunner_run_all(test_string_7, CK_NORMAL);
  no_failed += srunner_ntests_failed(test_string_7);
  srunner_free(test_string_7);

  return (no_failed < 3) ? EXIT_SUCCESS : EXIT_FAILURE;
}
