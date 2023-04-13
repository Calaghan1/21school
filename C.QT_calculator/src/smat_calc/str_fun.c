#include "calc_core.h"
double str_to_double(char *str) {
  double result = 0;
  int count = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (str[i] != '.' && count == 0) {
      result *= 10;
      result += str[i] - '0';
    } else {
      count++;
      result *= 10;
      result += '0' - str[i];
    }
  }
  while (count > 0) {
    result /= 10;
    count++;
  }
  return result;
}

int double_to_str(double num, char *result) {
  int evenp = num;
  if (evenp == num) {
    sprintf(result, "%d", evenp);
  } else {
    sprintf(result, "%lf", num);
  }
  return 0;
}