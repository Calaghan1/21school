#ifndef CALC_CORE_H_
#define CALC_CORE_H_
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"
#define OK 1
#define MEM_ERROR 0

int find_token(char *str, char *result);
void clean_str(char *str);
int Priority(char s);
int To_Polish(char *str_1, char *str_2);
double str_to_double(char *str);
double calc_resutl(char *str, double x);
int double_to_str(double num, char *result);

#endif  //  SRC_STACK_H_
