#include "s21_math.h"
#include "test.h"

int main() {
  setlocale(LC_ALL, "en_US.UTF-8");
  int no_failed = 0;

  Suite *s = s21_math_test_1("TEST");
  SRunner *test_math_1;
  test_math_1 = srunner_create(s);
  srunner_set_fork_status(test_math_1, CK_NOFORK);
  srunner_run_all(test_math_1, CK_NORMAL);
  no_failed = srunner_ntests_failed(test_math_1);
  srunner_free(test_math_1);

  ///////
  Suite *sec = s21_math_test_2("TEST");
  SRunner *test_math_2;
  test_math_2 = srunner_create(sec);
  srunner_set_fork_status(test_math_2, CK_NOFORK);
  srunner_run_all(test_math_2, CK_NORMAL);
  no_failed = srunner_ntests_failed(test_math_2);
  srunner_free(test_math_2);

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
