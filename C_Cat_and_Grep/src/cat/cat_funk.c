#include "cat_funk.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parser(int argc, char **argv, struct options *op, int *end_flag,
            int *file_count) {
  for (int i = 1; i < argc; i++) {
    if ((strcmp(argv[i], "-b") == 0) ||
        (strcmp(argv[i], "--number-nonblank") == 0)) {
      op->b = 1;
    } else if ((strcmp(argv[i], "-e") == 0)) {
      op->e = 1;
      op->v = 1;
    } else if ((strcmp(argv[i], "-E") == 0)) {
      op->e = 1;
    } else if ((strcmp(argv[i], "-n") == 0) ||
               (strcmp(argv[i], "--number") == 0)) {
      op->n = 1;
    } else if ((strcmp(argv[i], "-s") == 0) ||
               (strcmp(argv[i], "--squeeze-blank") == 0)) {
      op->s = 1;
    } else if (strcmp(argv[i], "-t") == 0) {
      op->t = 1;
      op->v = 1;
    } else if (strcmp(argv[i], "-T") == 0) {
      op->t = 1;
    } else if (strcmp(argv[i], "-v") == 0) {
      op->v = 1;
    } else if (argv[i][0] == '-') {
      if ((int)strlen(argv[i]) > 2) {
        for (int j = 1; j < (int)strlen(argv[i]); j++) {
          if (find_option(op, argv[i][j]) == 0) {
            printf("unknown option - %s", argv[i]);
            *end_flag = 1;
            break;
          }
        }
      } else {
        printf("unknown option - %s", argv[i]);
        *end_flag = 1;
        break;
      }
    } else {
      *file_count = i;
      break;
    }
  }
  rules_for_options(op);
}
void fild_struct_with_zero(struct options *op) {
  op->b = 0;
  op->e = 0;
  op->n = 0;
  op->s = 0;
  op->t = 0;
  op->v = 0;
}
void print_result(int argc, char **argv, struct options op, int file_count) {
  char c;
  char c1 = '\n';
  FILE *fp;
  int line_count = 1;
  int count_s = 0;
  int count_c = 0;
  int end_flag = 0;
  for (int i = file_count; i < argc; i++) {
    fp = fopen(argv[i], "r");
    if (fp != NULL) {
      while (!end_flag) {
        c = getc(fp);
        if (c == EOF) {
          end_flag = 1;
        } else {
          if (c != '\n') {
            count_c += 1;
            count_s = 0;
          } else {
            count_c = 0;
          }
          if (op.b && count_c == 1) {
            printf("%6d\t", line_count);
            line_count += 1;
          }
          if (op.s == 1 && c1 == '\n' && c == '\n') {
            if (count_s == 0) {
              count_s += 1;
            } else {
              continue;
            }
          }
          if (op.n == 1 && c1 == '\n') {
            printf("%6d\t", line_count);
            line_count++;
          }
          c1 = c;
          if (op.e && c == '\n') {
            printf("$");
          }
          if (op.t && c == '\t') {
            printf("^I");
            continue;
          }
          if (op.v == 1) {
            int b = c;
            translate(&b);
            c = b;
          }
          printf("%c", c);
        }
      }
    } else {
      printf("%s no such file", argv[i]);
    }
    c = 'a';
    c1 = '\n';
    fclose(fp);
    end_flag = 0;
    line_count = 1;
  }
}
void rules_for_options(struct options *op) {
  if (op->b == 1) {
    op->n = 0;
  }
  if (op->e == 1 || op->t == 1) {
    op->v = 1;
  }
}
int find_option(struct options *op, char c) {
  int flag = 0;
  switch (c) {
    case 'b':
      op->b = 1;
      flag = 1;
      break;
    case 'n':
      op->n = 1;
      flag = 1;
      break;
    case 'e':
      op->e = 1;
      flag = 1;
      break;
    case 's':
      op->s = 1;
      flag = 1;
      break;
    case 't':
      op->t = 1;
      flag = 1;
      break;
  }
  return flag;
}
void print_char(char c, struct options op, int count_for_n) {
  if (op.e == 1 && c == '\n') {
    printf("$");
  }
  printf("%c", c);
  if (op.n == 1 && c == '\n') {
    printf("%d ", count_for_n);
  }
}
void fr(FILE *fp, char *c, struct options op, int *count_for_n) {
  if (op.n == 1) {
    *count_for_n += 1;
    printf("%d ", *count_for_n);
  }
  if (op.s == 1) {
    char c1;
    while ((c1 = fgetc(fp)) == '\n') {
    }
    if (op.e == 1) {
      printf("$");
    }
    printf("\n");
    *c = c1;
  }
}

void translate(int *charbuf) {
  if (*charbuf == 9 || *charbuf == 10) {
  } else if (*charbuf < 32) {
    printf("^");
    *charbuf += 64;

  } else if (*charbuf == 127) {
    printf("^?");

  } else if (*charbuf > 127) {
    *charbuf = *charbuf % 128;
    if (*charbuf < 32) {
      printf("M-^");
      *charbuf += 64;

    } else if (*charbuf == 127) {
      printf("M-^?");

    } else {
      printf("M-");
    }
  }
}
