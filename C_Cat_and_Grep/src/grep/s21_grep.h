#ifndef s21_grepfun
#define s21_grepfun
#include <stdio.h>
struct flags {
  int e;
  int i;
  int v;
  int c;
  int l;
  int n;
  int h;
  int s;
  int f;
  int o;
};
void count_patterns(int *count, char **argv, int argc);
void parser(int argc, char **argv, struct flags *fl, char *array_of_patterns[],
            int *count_of_patterns, char *array_of_files[], int *count_of_files,
            int array_of_patternfile[], int *count_of_patternfile);
void print_result(char **argv, char *array_of_patterns[],
                  int *count_of_patterns, char *array_of_files[],
                  int *count_of_files, struct flags *fl,
                  int array_of_patternfile[], int *count_of_patternfile);
int find_flags(char c, struct flags *fl);
int get_patterns_file(char *str, int cflags, char *str2);
#endif  // s21_grepfun
