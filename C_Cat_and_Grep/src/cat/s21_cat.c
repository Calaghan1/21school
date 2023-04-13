#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cat_funk.h"
int main(int argc, char **argv) {
  struct options op;
  int end_flag = 0;
  int flag_count = 0;
  fild_struct_with_zero(&op);
  parser(argc, argv, &op, &end_flag, &flag_count);
  if (!end_flag) {
    print_result(argc, argv, op, flag_count);
  }
  return 0;
}
