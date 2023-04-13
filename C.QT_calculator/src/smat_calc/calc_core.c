#include "calc_core.h"

// int main() {
//     char str[256] = {'\0'};
//     scanf("%[^\n]s", &str);
//     char tmp[256] = {'\0'};
//     int status = find_token(str, tmp);
//     if (status) {
//         printf("%s\n", tmp);
//     } else {
//         printf("ERROR");
//     }
//     clean_str(str);
//     To_Polish(tmp, str);
//     printf("%s\n", str);
//     printf("%lf\n", calc_resutl(str));

//}
int find_token(char *str, char *result) {
  int sum_of_break = 0;
  char tmp[256] = {'\0'};
  int it = 0;
  int res_i = 0;
  int status = 1;
  int if_unary = 1;
  int prew_is_num = 0;
  int is_dot = 0;
  for (int i = 0; i < (int)strlen(str); i++) {
    if (it > 5) {
      status = 0;
    }
    tmp[it] = str[i];
    if (strcmp(tmp, "sin") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 's';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "cos") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'c';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "tan") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 't';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "acos") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'C';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "asin") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'S';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "atan") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'T';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "sqrt") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'Q';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "ln") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'l';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (strcmp(tmp, "log") == 0) {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      result[res_i] = 'L';
      res_i++;
      clean_str(tmp);
      it = 0;
      // } else if (it > 0) {
      //   it++;
    } else if (tmp[it] >= '0' && tmp[it] <= '9') {
      prew_is_num = 1;
      result[res_i] = str[i];
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '*') {
      prew_is_num = 0;
      if (i == 0) {
        status = 0;
      }
      result[res_i] = '*';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == 'x') {
      prew_is_num = 1;
      result[res_i] = 'x';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '/') {
      prew_is_num = 0;
      if (i == 0) {
        status = 0;
      }
      result[res_i] = '/';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '%') {
      prew_is_num = 0;
      if (i == 0) {
        status = 0;
      }
      result[res_i] = '%';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == ' ') {
      prew_is_num = 1;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '+') {
      prew_is_num = 0;
      if (i == 0) {
        status = 0;
      }
      result[res_i] = '+';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '-') {
      prew_is_num = 0;
      if (if_unary) {
        result[res_i] = '!';
      } else {
        result[res_i] = '-';
      }
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '(') {
      prew_is_num = 0;
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      sum_of_break++;
      result[res_i] = '(';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == ')') {
      if (i == 0) {
        status = 0;
      }
      sum_of_break--;
      prew_is_num = 1;
      result[res_i] = ')';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == 'x') {
      if (!if_unary) {
        result[res_i] = '*';
        res_i++;
      }
      prew_is_num = 1;
      result[res_i] = 'x';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '.') {
      if (is_dot) {
        status = 0;
      }
      is_dot = 1;
      result[res_i] = '.';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else if (tmp[it] == '^') {
      prew_is_num = 0;
      if (i == 0) {
        status = 0;
      }
      result[res_i] = '^';
      res_i++;
      clean_str(tmp);
      it = 0;
    } else {
      it++;
    }
    if (prew_is_num) {
      if_unary = 0;
    } else {
      is_dot = 0;
      if_unary = 1;
    }
  }
  if (sum_of_break) {
    status = 0;
  }
  if (if_unary) {
    status = 0;
  }
  return status;
}

void clean_str(char *str) {
  int k = strlen(str);
  for (int i = 0; i < k; i++) {
    str[i] = '\0';
  }
}
int Priority(char s) {
  int result = 0;
  switch (s) {
    case '!':
      result = 5;
      break;
    case 's':
    case 'c':
    case 't':
    case 'C':
    case 'S':
    case 'T':
    case 'l':
    case 'L':
    case '^':
    case 'Q':
    case '%':
      result = 4;
      break;
    case '*':
    case '/':
      result = 3;
      break;
    case '+':
    case '-':
      result = 2;
      break;
    case '(':
      result = 1;
      break;
  }
  return result;
}
int To_Polish(char *str_1, char *str_2) {
  if (str_1 != NULL && str_2 != NULL) {
    char *ptr_1 = str_1;
    char temp;
    stack *s = NULL;
    stack **st = &s;
    int prior;
    double buf;
    char *ptr_2 = str_2;
    while (*ptr_1 != '\0') {
      if ((*ptr_1 > 47 && *ptr_1 < 58) || *ptr_1 == 'x') {
        while ((*ptr_1 > 47 && *ptr_1 < 58) || *ptr_1 == 'x' || *ptr_1 == '.') {
          *ptr_2 = *ptr_1;
          ptr_2++;
          ptr_1++;
        }
        *ptr_2 = ' ';
        ptr_2++;
        ptr_1--;
      } else if (*ptr_1 == '(') {
        Push(st, *ptr_1, 0);
      } else if (*ptr_1 == ')') {
        while ((*st)->s != '(') {
          Pop(st, &temp, &buf);
          *ptr_2 = temp;
          ptr_2++;
          *ptr_2 = ' ';
          ptr_2++;
        }
        Pop(st, &temp, &buf);
      } else if (*ptr_1 == '+' || *ptr_1 == '-' || *ptr_1 == '*' ||
                 *ptr_1 == '/' || *ptr_1 == '^' || *ptr_1 == '%') {
        prior = Priority(*ptr_1);
        while ((*st) && prior <= Priority((*st)->s)) {
          Pop(st, &temp, &buf);
          *ptr_2 = temp;
          ptr_2++;
          *ptr_2 = ' ';
          ptr_2++;
        }
        Push(st, *ptr_1, 0);
      } else if (*ptr_1 == 's' || *ptr_1 == 'c' || *ptr_1 == 't' ||
                 *ptr_1 == 'C' || *ptr_1 == 'S' || *ptr_1 == 'T' ||
                 *ptr_1 == 'l' || *ptr_1 == 'L' || *ptr_1 == 'Q' ||
                 *ptr_1 == '!') {
        Push(st, *ptr_1, 0);
      }
      ptr_1++;
    }
    if (*st) {
      while (*st) {
        Pop(st, &temp, &buf);
        *ptr_2 = temp;
        ptr_2++;
        *ptr_2 = ' ';
        ptr_2++;
      }
    }
    *ptr_2 = '\0';
  }
  return 0;
}

double calc_resutl(char *str, double x) {
  char tmp[256] = {'\0'};
  int it = 0;

  double buf = 0;
  double buf1 = 0;
  double result = 0;
  char z = 'z';
  stack *st = NULL;
  for (int i = 0; i < (int)strlen(str); i++) {
    while (str[i] != ' ') {
      if (str[i] == '.') {
      }
      tmp[it] = str[i];
      i++;
      it++;
    }
    it--;
    if (tmp[it] >= '0' && tmp[it] <= '9') {
      buf = atof(tmp);
      Push(&st, z, buf);

    } else {
      if (tmp[it] == 's') {
        Pop(&st, &z, &buf);
        buf = sin(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 'x') {
        Push(&st, z, x);
      } else if (tmp[it] == 'c') {
        Pop(&st, &z, &buf);
        buf = cos(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 't') {
        Pop(&st, &z, &buf);
        double s = sin(buf);
        double c = cos(buf);
        // if (fabs(s) < 1e-4) {
        //     s = 0;
        // }
        if (fabs(c) < 1e-4) {
          c = 0;
          buf = asin(5);
        } else {
          buf = s / c;
        }
        Push(&st, z, buf);
      } else if (tmp[it] == 'C') {
        Pop(&st, &z, &buf);
        buf = acos(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 'S') {
        Pop(&st, &z, &buf);
        buf = asin(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 'T') {
        Pop(&st, &z, &buf);
        buf = atan(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 'Q') {
        Pop(&st, &z, &buf);
        buf = sqrt(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 'l') {
        Pop(&st, &z, &buf);
        buf = log(buf);
        Push(&st, z, buf);
      } else if (tmp[it] == 'L') {
        Pop(&st, &z, &buf1);
        buf = log(buf1) / log(10);
        Push(&st, z, buf);
      } else if (tmp[it] == '+') {
        Pop(&st, &z, &buf);
        Pop(&st, &z, &buf1);
        buf = buf + buf1;
        Push(&st, z, buf);
      } else if (tmp[it] == '-') {
        Pop(&st, &z, &buf1);
        if (!Pop(&st, &z, &buf)) {
          Push(&st, z, buf1 * (-1));
        } else {
          buf = buf - buf1;
          Push(&st, z, buf);
        }
      } else if (tmp[it] == '!') {
        Pop(&st, &z, &buf);
        buf = buf * -1;
        Push(&st, z, buf);
      } else if (tmp[it] == '*') {
        Pop(&st, &z, &buf);
        Pop(&st, &z, &buf1);
        buf = buf * buf1;
        Push(&st, z, buf);
      } else if (tmp[it] == '/') {
        Pop(&st, &z, &buf1);
        Pop(&st, &z, &buf);
        buf = buf / buf1;
        Push(&st, z, buf);
      } else if (tmp[it] == '^') {
        Pop(&st, &z, &buf1);
        Pop(&st, &z, &buf);
        buf = pow(buf, buf1);
        Push(&st, z, buf);
      } else if (tmp[it] == '%') {
        Pop(&st, &z, &buf1);
        Pop(&st, &z, &buf);
        buf = fmod(buf, buf1);
        Push(&st, z, buf);
      }
    }
    it = 0;
    clean_str(tmp);
  }
  Pop(&st, &z, &result);
  return result;
}
