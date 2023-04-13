#ifndef cat_funk
#define cat_funk
#include <stdio.h>
struct options {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
};

void option_n(FILE *file_path);
void option_e(FILE *file_path);
void option_b(FILE *file_path);
void option_s(FILE *file_path);
void Out_put(FILE *file_path);
void parser(int argc, char **argv, struct options *op, int *end_flag,
            int *flag_count);
void fild_struct_with_zero(struct options *op);
void print_result(int argc, char **argv, struct options op, int file_count);
void rules_for_options(struct options *op);
int find_option(struct options *op, char c);
void fr(FILE *fp, char *c, struct options op, int *count_for_n);
void print_char(char c, struct options op, int count_for_n);
void translate(int *charbuf);
#endif  // cat_funk
