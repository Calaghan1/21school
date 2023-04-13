#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_grep.h"
void count_patterns(int *count, char **argv, int argc) {
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-e") == 0 || strlen(argv[i]) > 2) {
      count++;
    }
    count++;
  }
}
void parser(int argc, char **argv, struct flags *fl, char *array_of_patterns[],
            int *count_of_patterns, char *array_of_files[], int *count_of_files,
            int array_of_patternfile[], int *count_of_patternfile) {
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == '-') {
      if (strcmp(argv[i], "-e") == 0) {
        if (i == argc - 1) {
          printf("option requires an argument -- e");
        } else {
          array_of_patterns[*count_of_patterns] = argv[i + 1];
          *count_of_patterns += 1;
          fl->e = 1;
        }
      } else if (argv[i][0] == '-' && argv[i][1] == 'e' &&
                 strlen(argv[i]) > 2) {
        fl->e = 1;
        char *str = malloc((strlen(argv[i]) - 2) * sizeof(char));
        for (int j = 2; j < (int)strlen(argv[i]); j++) {
          str[j - 2] = argv[i][j];
          array_of_patterns[*count_of_patterns] = str;
          *count_of_patterns += 1;
        }
      } else if (strcmp(argv[i], "-i") == 0) {
        fl->i = 1;
      } else if (strcmp(argv[i], "-f") == 0) {
        fl->f = 1;
        if (i != argc - 1) {
          array_of_patternfile[*count_of_patternfile] = i + 1;
          *count_of_patternfile += 1;
        }
      } else if (strcmp(argv[i], "-v") == 0) {
        fl->v = 1;
      } else if (strcmp(argv[i], "-c") == 0) {
        fl->c = 1;
      } else if (strcmp(argv[i], "-h") == 0) {
        fl->h = 1;
      } else if (strcmp(argv[i], "-l") == 0) {
        fl->l = 1;
      } else if (strcmp(argv[i], "-s") == 0) {
        fl->s = 1;
      } else if (strcmp(argv[i], "-o") == 0) {
        fl->o = 1;
      } else if (strcmp(argv[i], "-n") == 0) {
        fl->n = 1;
      } else if (argv[i][0] == '-' && strlen(argv[i]) > 2 &&
                 argv[i][1] != 'e') {
        for (int j = 1; j < (int)strlen(argv[i]); j++) {
          if (find_flags(argv[i][j], fl) == 0) {
            if (fl->s != 1) {
              printf("invalid option -- %c", argv[i][j]);
            }
            j = (int)strlen(argv[i]);
          }
        }
      } else {
        if (fl->s != 1) {
          printf("invalid option - %s\n", argv[i]);
        }
      }
    }
  }
  if (fl->e == 0 && fl->f == 0) {
    int flag = 0;
    int i = 1;
    while (flag == 0 && i < argc) {
      if (argv[i][0] != '-') {
        array_of_patterns[*count_of_patterns] = argv[i];
        *count_of_patterns += 1;
        flag = 1;
      }
      i++;
    }
    while (i < argc) {
      if (argv[i][0] != '-') {
        array_of_files[*count_of_files] = argv[i];
        *count_of_files += 1;
      }
      i++;
    }
  }
  if (fl->e == 1 || fl->f == 1) {
    int i = 1;
    while (i < argc) {
      if (strcmp(argv[i], "-e") == 0) {
        i += 2;
      } else if (argv[i][0] != '-' && (strcmp(argv[i - 1], "-f"))) {
        array_of_files[*count_of_files] = argv[i];
        *count_of_files += 1;
        i++;
      } else {
        i++;
      }
    }
  }
}
void print_result(char **argv, char *array_of_patterns[],
                  int *count_of_patterns, char *array_of_files[],
                  int *count_of_files, struct flags *fl,
                  int array_of_patternfile[], int *count_of_patternfile) {
  int status = 265;
  size_t nmatch = 1;
  regmatch_t pmatch[1];
  regex_t reg[*count_of_patterns];
  int cflags = REG_EXTENDED;
  if (fl->i == 0) {
    cflags = REG_EXTENDED;
  } else {
    cflags = REG_ICASE;
  }

  for (int i = 0; i < *count_of_patterns; i++) {
    regcomp(&reg[i], array_of_patterns[i], cflags);
  }

  FILE *fp;
  size_t count = 0;
  int i = 0;
  int k = 0;
  char *str = NULL;
  int count_for_c = 0;
  int flag_for_l = 0;
  int count_for_lines = 0;

  for (int j = 0; j < *count_of_files; j++) {
    fp = fopen(array_of_files[j], "r");
    if (fp != NULL) {
      while ((getline(&str, &count, fp)) != EOF) {
        count_for_lines++;
        while (status != 0 && i < *count_of_patterns) {
          status = regexec(&reg[i], str, nmatch, pmatch, 0);
          i++;
        }
        if (fl->f) {
          while (status != 0 && k < *count_of_patternfile) {
            status =
                get_patterns_file(argv[array_of_patternfile[k]], cflags, str);
            k++;
          }
        }
        if (status == REG_NOMATCH && fl->v == 1) {
          if (fl->c == 1) {
            if (fl->l == 1) {
              flag_for_l = 1;
            }
            count_for_c++;
          } else if (fl->l == 1) {
            flag_for_l = 1;
          } else {
            if (fl->n == 1) {
              if (fl->h == 0 && *count_of_files > 1) {
                printf("%s:", array_of_files[j]);
              }
              printf("%d:", count_for_lines);
              printf("%s", str);
            } else if (fl->h == 0 && *count_of_files > 1) {
              printf("%s:", array_of_files[j]);
              printf("%s", str);
            } else {
              printf("%s", str);
            }
          }
        } else if (status == 0 && fl->v == 0) {
          if (fl->c == 1) {
            if (fl->l == 1) {
              flag_for_l = 1;
            }
            count_for_c++;
          } else if (fl->l == 1) {
            flag_for_l = 1;
          } else {
            if (fl->n == 1) {
              if (fl->h == 0 && *count_of_files > 1) {
                printf("%s:", array_of_files[j]);
              }
              printf("%d:", count_for_lines);
              printf("%s", str);
            } else if (fl->h == 0 && *count_of_files > 1) {
              printf("%s:", array_of_files[j]);
              printf("%s", str);
            } else {
              printf("%s", str);
            }
          }
        }
        status = 2;
        i = 0;
        k = 0;
        free(str);
        str = NULL;
      }
      free(str);
      str = NULL;
      if (fl->c == 1 && fl->l == 0) {
        if (*count_of_files > 1) {
          if (fl->h == 1) {
            printf("%d\n", count_for_c);
          } else {
            printf("%s:%d\n", array_of_files[j], count_for_c);
          }
        } else if (*count_of_files == 1) {
          printf("%d\n", count_for_c);
        }
      }
      if (fl->l == 1) {
        if (fl->c == 1) {
          if (*count_of_files > 1 && fl->h == 0) {
            printf("%s:", array_of_files[j]);
          }
          if (flag_for_l == 1) {
            printf("1\n");
            printf("%s\n", array_of_files[j]);
          } else {
            printf("0\n");
          }
        } else if (flag_for_l == 1) {
          printf("%s\n", array_of_files[j]);
        }
      }
      fclose(fp);
    } else if (fl->s != 1) {
      printf("%s: No such file or directory\n", array_of_files[j]);
    }
    flag_for_l = 0;
    count_for_c = 0;
    count_for_lines = 0;
  }
  for (int i = 0; i < *count_of_patterns; i++) {
    regfree(&reg[i]);
  }
}
int find_flags(char c, struct flags *fl) {
  int flag = 0;
  switch (c) {
    case 'e':
      fl->e = 1;
      flag = 1;
      break;
    case 'i':
      fl->i = 1;
      flag = 1;
      break;
    case 'v':
      fl->v = 1;
      flag = 1;
      break;
    case 'c':
      fl->c = 1;
      flag = 1;
      break;
    case 'l':
      fl->l = 1;
      flag = 1;
      break;
    case 'n':
      fl->n = 1;
      flag = 1;
      break;
    case 'h':
      fl->h = 1;
      flag = 1;
      break;
    case 's':
      fl->s = 1;
      flag = 1;
      break;
    case 'f':
      fl->f = 1;
      flag = 1;
      break;
    case 'o':
      fl->o = 1;
      flag = 1;
  }
  return flag;
}
int get_patterns_file(char *str, int cflags, char *str2) {
  FILE *fp;
  int status = 256;
  size_t count = 0;
  char *str1 = NULL;
  size_t nmatch = 1;
  regmatch_t pmatch[1];
  regex_t reg;
  fp = fopen(str, "r");
  if (fp != NULL) {
    while (status != 0 && getline(&str1, &count, fp) != EOF) {
      if (str1[strlen(str1) - 1] == '\n' && strlen(str1) > 1) {
        str1[strlen(str1) - 1] = '\0';
      }
      regcomp(&reg, str1, cflags);
      status = regexec(&reg, str2, nmatch, pmatch, 0);
      regfree(&reg);
      free(str1);
      str1 = NULL;
    }
    free(str1);
    str1 = NULL;
    fclose(fp);
    return status;
  } else {
    return status;
  }
}
