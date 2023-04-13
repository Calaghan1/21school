#include "s21_string.h"
#include "string.h"

void lenght_width(const char* format, struct option* opt, int* i) {
  int ans = 0;
  if ((format[*i] >= '0' && format[*i] <= '9') || format[*i] == '.') {
    int l = *i;
    while (format[l] >= '0' && format[l] <= '9') {
      l++;
    }
    while (format[*i] >= '0' && format[*i] <= '9') {
      ans *= 10;
      ans += format[*i] - '0';
      *i += 1;
    }
  }
  opt->width = ans;
}
int s21_sscanf(const char* buff, const char* format, ...) {
  struct option opt = {0};
  va_list variable;
  int index = 0;
  char type;
  int* pointer_to_string = &index;
  va_start(variable, format);

  for (int i = 0; (format[i] != '\0' && opt.stoppage == 0); i++) {
    if (format[i] == '%') {
      //  смотрим, не ложный ли %
      i++;
      while (format[i] == ' ' || format[i] == '%') {
        if (format[i] == '%') {
          opt.stoppage = 1;
        }
        i++;
      }
      if (opt.stoppage == 1) {
        break;
      }

      if (format[i] == '*') {
        opt.exclusion = 1;
        i++;
      }
      // проверяем есть ли число для спецификатора
      lenght_width(format, &opt, &i);

      if (format[i] == 'd') {
        type = '0';
        integer_func(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'c') {
        if (opt.prev_space == -1) {
          opt.prev_space = 1;
        } else if ((i - 1) == 0) {
          opt.prev_space = 0;
        } else {
          if ((format[i - 1] == '*' && format[i - 2] == '%' &&
               format[i - 3] == ' ') ||
              (format[i - 2] == ' ')) {
            opt.prev_space = 1;
          } else {
            opt.prev_space = 0;
          }
        }
        mode1_func(buff, variable, pointer_to_string, &opt);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'i') {
        type = '0';
        int_buff_reader(buff, variable, pointer_to_string, &opt, format, &i,
                        type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 's') {
        mode2_func(buff, variable, pointer_to_string, &opt);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'o') {
        type = 'o';
        Octal_func(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'x' || format[i] == 'X') {
        type = 'x';
        Hex_func(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'p') {
        p_adress(buff, variable, pointer_to_string, &opt);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'f') {
        type = '0';
        float_reader(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'e' || format[i] == 'E') {
        type = '0';
        float_reader(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'g' || format[i] == 'G') {
        type = '0';
        float_reader(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'u') {
        type = 'u';
        integer_func(buff, variable, pointer_to_string, &opt, type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'n') {
        if ((i - 1) == 0) {
          opt.prev_space = 0;
        } else {
          if ((format[i - 1] == '*' && format[i - 2] == '%' &&
               format[i - 3] == ' ') ||
              (format[i - 2] == ' ')) {
            opt.prev_space = 1;
          } else {
            opt.prev_space = 0;
          }
        }
        num_of_scanned_symbols(variable, pointer_to_string, &opt);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'h') {
        i += 1;
        type = 'h';
        int_buff_reader(buff, variable, pointer_to_string, &opt, format, &i,
                        type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'l') {
        i += 1;
        type = 'l';
        int_buff_reader(buff, variable, pointer_to_string, &opt, format, &i,
                        type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      } else if (format[i] == 'L') {
        i += 1;
        type = 'L';
        float_buff_reader(buff, variable, pointer_to_string, &opt, format, &i,
                          type);
        if (opt.exclusion == 0) {
        } else {
          opt.exclusion = 0;
        }
        if (opt.stoppage == 1) {
          break;
        }
      }
    }
  }
  va_end(variable);

  return opt.count;
}

int** p_adress(const char* buff, va_list variable, int* pointer_to_string,
               struct option* opt) {
  int** sh = (int**)va_arg(variable, int*);
  while (buff[*pointer_to_string] == ' ') {
    *pointer_to_string += 1;
  }
  if (((buff[*pointer_to_string] >= '0' && buff[*pointer_to_string] <= '9') ||
       (buff[*pointer_to_string] >= 'a' && buff[*pointer_to_string] <= 'f') ||
       (buff[*pointer_to_string] >= 'A' && buff[*pointer_to_string] <= 'F'))) {
    char array[100] = {'\0'};
    int x_count = 0;
    for (int i = 0;
         ((buff[*pointer_to_string] >= '0' &&
           buff[*pointer_to_string] <= '9') ||
          (buff[*pointer_to_string] >= 'a' &&
           buff[*pointer_to_string] <= 'f') ||
          (buff[*pointer_to_string] >= 'A' &&
           buff[*pointer_to_string] <= 'F') ||
          (buff[*pointer_to_string] == 'x' || buff[*pointer_to_string] == 'X'));
         i++) {
      if (buff[*pointer_to_string] == 'x' || buff[*pointer_to_string] == 'X') {
        x_count += 1;
      }
      if (x_count > 1) {
        break;
      }
      if (opt->width > 0) {
        if (opt->width == i) {
          if (array[i - 1] == 'x' || array[i - 1] == 'X') {
            array[i] = '\0';
            *pointer_to_string -= 1;
          }
          break;
        }
      }
      array[i] = buff[*pointer_to_string];
      *pointer_to_string += 1;
    }
    if (opt->exclusion == 0) {
      *sh = (int*)strtoll(array, s21_NULL, 16);
    }
    opt->count += 1;
    opt->on_next_to_read = *pointer_to_string;
    while (buff[*pointer_to_string] == ' ') {
      *pointer_to_string += 1;
    }
  } else {
    *sh = NULL;
    opt->stoppage = 1;
  }
  return sh;
}
void num_of_scanned_symbols(va_list variable, const int* pointer_to_string,
                            struct option* opt) {
  if (opt->exclusion == 0) {
    if (opt->prev_space == 1) {
      opt->prev_space = -1;
      int* sh = (int*)va_arg(variable, int*);
      *sh = *pointer_to_string;
    } else {
      int* sh = (int*)va_arg(variable, int*);
      *sh = opt->on_next_to_read;
    }
  }
}
int Hex_letters(char symb) {
  int res = -1;
  if (symb == 'a' || symb == 'A') {
    res = 10;
  }
  if (symb == 'b' || symb == 'B') {
    res = 11;
  }
  if (symb == 'c' || symb == 'C') {
    res = 12;
  }
  if (symb == 'd' || symb == 'D') {
    res = 13;
  }
  if (symb == 'e' || symb == 'E') {
    res = 14;
  }
  if (symb == 'f' || symb == 'F') {
    res = 15;
  }

  return res;
}

void float_buff_reader(const char* buff, va_list variable,
                       int* pointer_to_string, struct option* opt,
                       const char* format, const int* i, char type) {
  if (format[*i] == 'f' || format[*i] == 'g' || format[*i] == 'G' ||
      format[*i] == 'E' || format[*i] == 'e') {
    float_reader(buff, variable, pointer_to_string, opt, type);
  } else {
    opt->stoppage = 1;
  }
}

void float_reader(const char* buff, va_list variable, int* pointer_to_string,
                  struct option* opt, char type) {
  int sign = 0;
  int space_counter = 0;
  int minus = 0;
  int plus = 0;
  int i = 0;

  while (buff[*pointer_to_string] == ' ') {
    *pointer_to_string += 1;
  }
  space_counter = *pointer_to_string;
  int start = *pointer_to_string;

  if (buff[start] == '-') {
    sign = 1;
    minus = 1;
    i++;
    start += 1;
  }
  if (buff[start] == '+') {
    sign = 1;
    start += 1;
    i++;
    plus = 1;
  }
  if (opt->width > 0) {
    if (opt->width <= i) {
      opt->stoppage = 1;
    }
  }
  if ((buff[start] >= '0' && buff[start] <= '9') ||
      ((buff[start] == '.') &&
       (buff[start + 1] >= '0' && buff[start + 1] <= '9'))) {
    int sign_count = 0;
    int dot_count = 0;
    int break_ = 0;
    int dot_in_the_beginng = 0;
    char array[100] = "";
    for (i = 0;
         (buff[start] >= '0' && buff[start] <= '9') || (buff[start] == '.');
         i++, start++) {
      if (opt->stoppage == 1) {
        break;
      }
      if (buff[start] == '.') {
        dot_count += 1;
        if (minus == 0) {
          if (start == space_counter) {
            dot_in_the_beginng = 1;
          }
        } else {
          if (start == space_counter + 1) {
            dot_in_the_beginng = 1;
          }
        }
        if (plus == 1) {
          if (start == space_counter + 1) {
            dot_in_the_beginng = 1;
          }
        }
      }
      if (buff[start] == '-' || buff[start] == '+') {
        sign_count += 1;
      }
      if (dot_count > 1 || sign_count > 1) {
        break;
      }
      if (opt->width > 0) {
        if ((minus == 1 || plus == 1) && (opt->width - 1 == i)) {
          break_ = 1;
          break;
        }
        if (opt->width == i) {
          break_ = 1;
          break;
        }
      }
      array[i] = buff[start];  // cppcheck
    }
    array[i] = '\0';
    if (opt->width > 0) {
      if ((minus == 1 || plus == 1) && (opt->width - 1 < i + 1)) {
        break_ = 1;
      }
      if (opt->width < i + 1) {
        break_ = 1;
      }
    }

    if (opt->stoppage != 1) {
      int flag_e = 0;
      long double E = 0;
      int after_e = 0;

      if (break_ != 1) {
        if (buff[start] == 'e' || buff[start] == 'E') {
          flag_e = 1;
          char aft_e[20] = {'\0'};
          E = scientific_notation(buff, aft_e, &start, &i, &after_e, opt, sign);
        }
      }

      int num = 0;
      long double fn;
      long double answer = 0;
      if (dot_in_the_beginng == 0) {
        int y = 0;
        int something = 0;
        while (array[something] != '\0' && array[something] != '.') {
          something += 1;
        }
        for (y = 0; array[y] != '.' && array[y] != '\0'; y++) {
          num = (array[y] - '0') * pow(10, something - y - 1);
          answer += num;
        }
        num = 1;
        if (minus == 1 || plus == 1) {
          start -= 1;
        }
        if (array[y] == '.') {
          y += 1;
        }
        if (array[y] != '\0') {
          for (; y < start - space_counter; y++) {
            fn = (double)(array[y] - '0') / (double)pow(10, num);
            num += 1;
            answer += fn;
          }
        }
      } else {
        if (minus == 1 || plus == 1) {
          start -= 1;
        }
        num = 1;
        if (minus || plus) {
          start++;
        }
        for (int i2 = 1; i2 < i; i2++) {
          fn = (double)(array[i2] - '0') / (double)pow(10, num);
          num += 1;
          answer += fn;
        }
      }
      if (minus == 1) {
        answer *= -1;
      }
      if ((minus == 1 || plus == 1) && dot_in_the_beginng == 0) {
        start += 1;
      }
      opt->on_next_to_read = start;
      while (buff[start] == ' ') {
        start += 1;
      }
      *pointer_to_string = start;
      if (flag_e == 1) {
        *pointer_to_string = after_e;
        answer = answer * E;
      }
      float_type_choice(answer, variable, opt, type);
    }
  } else {
    opt->stoppage = 1;
  }
}

double scientific_notation(const char* buff, char aft_e[], const int* start,
                           const int* i, int* after_e, struct option* opt,
                           int sign) {
  *after_e = *start + 1;
  int break_ = 0;
  int sign_q = 0;
  int s_c = 1 + sign;
  int minus = 1;
  int c = 0;
  int result = 0;
  double res = 0;

  if (buff[*after_e] == '-') {
    minus *= -1;
    s_c++;
    *after_e += 1;
    sign_q += 1;
  }

  if (buff[*after_e] == '+') {
    s_c++;
    *after_e += 1;
    sign_q += 1;
  }
  if (opt->width > 0) {
    if (opt->width <= (s_c + *i)) {
      break_ = 1;
    }
  }
  if (sign_q < 2 && break_ != 1) {
    while (buff[*after_e] >= '0' && buff[*after_e] <= '9') {
      if (opt->width > 0) {
        if (opt->width <= (s_c + *i)) {
          break;
        }
      }
      aft_e[c] = buff[*after_e];
      c += 1;
      *after_e += 1;
      s_c++;
    }

    for (int c1 = 0; c1 < c; c1++) {
      result *= 10;
      result += (aft_e[c1] - 48);
    }
  }
  res = pow(10, result * minus);
  if (c == 0) {
    res = 1;
    *after_e = *start;
  }
  if (res == 0) {
    res = 1;
  }
  return res;
}

void float_type_choice(long double answer, va_list variable, struct option* opt,
                       char type) {
  if (type == '0') {
    if (opt->exclusion == 0) {
      float* sh = (float*)va_arg(variable, float*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'L') {
    if (opt->exclusion == 0) {
      long double* sh = (long double*)va_arg(variable, long double*);
      *sh = answer;
      opt->count += 1;
    }
  }
}

void int_buff_reader(const char* buff, va_list variable, int* pointer_to_string,
                     struct option* opt, const char* format, const int* i,
                     char type) {
  int flag = 0;
  if (format[*i] == 'u') {
    if (type == 'h') {
      type = 'H';
    }
    if (type == 'l') {
      type = 'L';
    }
    integer_func(buff, variable, pointer_to_string, opt, type);
  }
  if (format[*i] == 'x' || format[*i] == 'X') {
    if (type == 'h') {
      type = 'H';
    }
    if (type == 'l') {
      type = 'L';
    }
    Hex_func(buff, variable, pointer_to_string, opt, type);
  }
  if (format[*i] == 'o') {
    if (type == 'h') {
      type = 'H';
    }
    if (type == 'l') {
      type = 'L';
    }
    Octal_func(buff, variable, pointer_to_string, opt, type);
  }
  if (format[*i] == 'd') {
    integer_func(buff, variable, pointer_to_string, opt, type);
  } else if (format[*i] == 'i') {
    while (buff[*pointer_to_string] == ' ') {
      *pointer_to_string += 1;
    }
    if (buff[*pointer_to_string] == '-' || buff[*pointer_to_string] == '+') {
      *pointer_to_string += 1;
      flag = 1;
    }
    if (buff[*pointer_to_string] == '0' &&
        (buff[*pointer_to_string + 1] != 'x' &&
         buff[*pointer_to_string + 1] != 'X')) {
      if (flag == 1) {
        *pointer_to_string -= 1;
      }
      Octal_func(buff, variable, pointer_to_string, opt, type);
    } else if (buff[*pointer_to_string] == '0' &&
               (buff[*pointer_to_string + 1] == 'x' ||
                buff[*pointer_to_string + 1] == 'X')) {
      if (flag == 1) {
        *pointer_to_string -= 1;
      }
      Hex_func(buff, variable, pointer_to_string, opt, type);
    } else {
      if (flag == 1) {
        *pointer_to_string -= 1;
      }
      integer_func(buff, variable, pointer_to_string, opt, type);
    }
  } else if (format[*i] == 'c') {
    if (opt->prev_space == -1) {
      opt->prev_space = 1;
    } else if ((*i - 2) == 0) {
      opt->prev_space = 0;
    } else {
      if ((format[*i - 2] == '*' && format[*i - 3] == '%' &&
           format[*i - 4] == ' ') ||
          (format[*i - 3] == ' ')) {
        opt->prev_space = 1;
      } else {
        opt->prev_space = 0;
      }
    }
    long_symbol(buff, variable, pointer_to_string, opt);
  } else if (format[*i] == 's') {
    long_string(buff, variable, pointer_to_string, opt);
  }
}

void integer_func(const char* buff, va_list variable, int* pointer_to_string,
                  struct option* opt, char type) {
  char array[50];
  int i = *pointer_to_string;
  int minus = 0;
  for (int y = 0; y < 50; y++) {
    array[y] = '\0';
  }

  while (buff[i] == ' ') {
    i++;
  }
  if (buff[i] == '-') {
    minus = 1;
    i += 1;
  }
  if ((buff[i] >= '0' && buff[i] <= '9') ||
      ((buff[i] == '+') && (buff[i + 1] >= '0' && buff[i + 1] <= '9'))) {
    int i1 = 0;
    int sign_count = 0;
    for (; (buff[i] >= '0' && buff[i] <= '9'); i++) {
      if (buff[i] == '+' || buff[i] == '-') {
        sign_count += 1;
      }
      if (sign_count > 1) {
        break;
      }
      if (buff[i] >= '0' && buff[i] <= '9') {
        sign_count = 1;
      }
      if (opt->width > 0) {
        array[i1] = buff[i];
        i1++;
        if (opt->width == i1) {
          i += 1;
          break;
        }
      } else {
        array[i1] = buff[i];
        i1++;
      }
    }
    array[i1] = '\0';
    long long int answer = 0;
    opt->on_next_to_read = i;
    for (int y = 0, num = 0; y < i1; y++) {
      num = (array[y] - 48) * pow(10, i1 - 1 - y);
      answer += num;
    }
    if (minus == 1) {
      answer *= -1;
    }
    integer_type_choice(answer, variable, opt, type);
    while (buff[i] == ' ') {
      i += 1;
    }
    *pointer_to_string = i;
  } else {
    opt->stoppage = 1;
  }
}

void integer_type_choice(long long int answer, va_list variable,
                         struct option* opt, char type) {
  if (type == '0') {
    if (opt->exclusion == 0) {
      int* sh = (int*)va_arg(variable, int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'u') {
    if (opt->exclusion == 0) {
      unsigned int* sh = (unsigned int*)va_arg(variable, unsigned int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'h') {
    if (opt->exclusion == 0) {
      short int* sh = (short int*)va_arg(variable, short int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'H') {
    if (opt->exclusion == 0) {
      unsigned short int* sh =
          (unsigned short int*)va_arg(variable, unsigned short int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'L') {
    if (opt->exclusion == 0) {
      unsigned long int* sh =
          (unsigned long int*)va_arg(variable, unsigned long int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'l') {
    if (opt->exclusion == 0) {
      long int* sh = (long int*)va_arg(variable, long int*);
      *sh = answer;
      opt->count += 1;
    }
  }
}

void mode1_func(const char* buff, va_list variable, int* pointer_to_string,
                struct option* opt) {
  if (opt->prev_space == 1) {
    while (buff[*pointer_to_string] == ' ') {
      *pointer_to_string += 1;
    }
  }
  if (buff[*pointer_to_string] != '\0') {
    if (opt->exclusion == 0) {
      if (opt->prev_space == 1) {
        char* sh = (char*)va_arg(variable, char*);
        *sh = buff[*pointer_to_string];
        *pointer_to_string += 1;
      } else {
        char* sh = (char*)va_arg(variable, char*);
        *sh = buff[opt->on_next_to_read];
        opt->on_next_to_read += 1;
      }
      opt->count += 1;
    }
    if (opt->prev_space == 0) {
      *pointer_to_string = opt->on_next_to_read;
    } else {
      opt->on_next_to_read = *pointer_to_string;
    }
  }
}

void mode2_func(const char* buff, va_list variable, int* pointer_to_string,
                struct option* opt) {
  char array1[1000];
  for (int y = 0; y < 1000; y++) {
    array1[y] = '\0';
  }
  int i_1 = *pointer_to_string;
  while (buff[i_1] == ' ') {
    i_1++;
  }
  if (buff[i_1] != '\0') {
    int i2 = 0;

    for (; buff[i_1] != ' ' && buff[i_1] != '\0'; i_1++) {
      if (opt->width > 0) {
        array1[i2] = buff[i_1];
        i2++;
        if (opt->width == i2) {
          i_1 += 1;
          break;
        }
      } else {
        array1[i2] = buff[i_1];
        i2++;
      }
    }
    opt->on_next_to_read = i_1;

    while (buff[i_1] == ' ') {
      i_1 += 1;
    }
    *pointer_to_string = i_1;
    array1[i2] = '\0';

    if (opt->exclusion == 0) {
      char* sh = (char*)va_arg(variable, char*);
      for (int st = 0; st < i2; st++) {
        sh[st] = array1[st];
      }
      sh[i2] = '\0';
      opt->count += 1;
    }
  } else {
    opt->stoppage = 1;
  }
}

void long_symbol(const char* buff, va_list variable, int* pointer_to_string,
                 struct option* opt) {
  if (opt->prev_space == 1) {
    while (buff[*pointer_to_string] == ' ') {
      *pointer_to_string += 1;
    }
  }
  if (buff[*pointer_to_string] != '\0') {
    if (opt->exclusion == 0) {
      if (opt->prev_space == 1) {
        wchar_t* sh = (wchar_t*)va_arg(variable, wchar_t*);
        *sh = buff[*pointer_to_string];
        *pointer_to_string += 1;
      } else {
        wchar_t* sh = (wchar_t*)va_arg(variable, wchar_t*);
        *sh = buff[opt->on_next_to_read];
        opt->on_next_to_read += 1;
      }
      opt->count += 1;
    }
    if (opt->prev_space == 0) {
      *pointer_to_string = opt->on_next_to_read;
    } else {
      opt->on_next_to_read = *pointer_to_string;
    }
  }
}

void long_string(const char* buff, va_list variable, int* pointer_to_string,
                 struct option* opt) {
  wchar_t array1[950] = {'\0'};
  int i_1 = *pointer_to_string;
  while (buff[i_1] == ' ') {
    i_1++;
  }
  if (buff[i_1] != '\0') {
    int i2 = 0;
    for (; buff[i_1] != ' ' && buff[i_1] != '\0'; i_1++) {
      if ((opt->width > 0) && (opt->width == i2)) {
        i_1 += 1;
        break;
      }
      array1[i2] = buff[i_1];
      i2++;
    }
    opt->on_next_to_read = i_1;
    while (buff[i_1] == ' ') {
      i_1 += 1;
    }
    *pointer_to_string = i_1;
    array1[i2] = '\0';

    if (opt->exclusion == 0) {
      wchar_t* sh = (wchar_t*)va_arg(variable, wchar_t*);
      for (int st = 0; st < i2; st++) {
        sh[st] = array1[st];
      }
      sh[i2] = '\0';
      opt->count += 1;
    }
  } else {
    opt->stoppage = 1;
  }
}

void Octal_func(const char* buff, va_list variable, int* pointer_to_string,
                struct option* opt, char type) {
  int start = *pointer_to_string;
  int sign_count = 0;
  int minus = 0;
  int plus = 0;
  char array[100] = "";

  while (buff[start] == ' ') {
    start++;
  }

  while (buff[start] == '+' || buff[start] == '-') {
    if (buff[start] == '+') {
      plus = 1;
    }
    if (buff[start] == '-') {
      minus = 1;
    }
    start += 1;
    sign_count += 1;
  }

  if ((buff[start] >= '0' && buff[start] <= '7') && sign_count < 2) {
    int count = 0;
    while ((buff[start] >= '0' && buff[start] <= '7')) {
      if (opt->width > 0) {
        if (opt->width - 1 <= count && (plus || minus)) {
          break;
        }
        if (opt->width <= count) {
          break;
        }
      }
      if (opt->width > 0) {
        if (opt->width == count) {
          break;
        }
      }
      array[count] = buff[start];
      count++;
      start++;
    }

    long long int res = 0;

    for (int i = 0, result = 0; i < count; i++) {
      result = array[i] - '0';
      res += result * pow(8, count - i - 1);
    }
    if (minus == 1) {
      res *= -1;
    }
    opt->on_next_to_read = start;
    while (buff[start] == ' ') {
      start += 1;
    }
    *pointer_to_string = start;
    octal_type_choice(variable, opt, type, res);
  } else {
    opt->stoppage = 1;
  }
}

void octal_type_choice(va_list variable, struct option* opt, char type,
                       long long int answer) {
  if (type == '0') {
    if (opt->exclusion == 0) {
      int* sh = (int*)va_arg(variable, int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'o') {
    if (opt->exclusion == 0) {
      unsigned int* sh = (unsigned int*)va_arg(variable, unsigned int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'H') {
    if (opt->exclusion == 0) {
      unsigned short int* sh =
          (unsigned short int*)va_arg(variable, unsigned short int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'h') {
    if (opt->exclusion == 0) {
      short int* sh = (short int*)va_arg(variable, short int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'l') {
    if (opt->exclusion == 0) {
      long int* sh = (long int*)va_arg(variable, long int*);
      *sh = answer;
      opt->count += 1;
    }
  }
  if (type == 'L') {
    if (opt->exclusion == 0) {
      unsigned long int* sh =
          (unsigned long int*)va_arg(variable, unsigned long int*);
      *sh = answer;
      opt->count += 1;
    }
  }
}

void Hex_func(const char* buff, va_list variable, int* pointer_to_string,
              struct option* opt, char type) {
  int start = *pointer_to_string;
  int confirm_width = 0;
  int check = 0;
  int minus = 0;
  char array[125] = "";

  if (opt->width > 0) {
    confirm_width = 1;
  }
  while (buff[start] == ' ') {
    start++;
  }
  int plus = 0;
  if (buff[start] == '+') {
    start += 1;
    check += 1;
    plus = 1;
  }
  if (buff[start] == '-') {
    minus = 1;
    start += 1;
    check += 1;
  }

  if ((confirm_width == 1 && check < opt->width) || confirm_width == 0) {
    if ((buff[start] >= 'A' && buff[start] <= 'F') ||
        (buff[start] >= 'a' && buff[start] <= 'f') ||
        (buff[start] >= '0' && buff[start] <= '9') ||
        (buff[start] == '0' &&
         (buff[start + 1] == 'x' || buff[start + 1] == 'X'))) {
      int i = 0;
      int x_c = 0;
      for (; (buff[start] >= 'A' && buff[start] <= 'F') ||
             (buff[start] >= 'a' && buff[start] <= 'f') ||
             (buff[start] >= '0' && buff[start] <= '9') ||
             (buff[start] == '0' || (buff[start] == 'x' || buff[start] == 'X'));
           i += 1) {
        if (opt->width > 0) {
          if (opt->width == i) {
            break;
          }
          if ((minus == 1 || plus == 1) && opt->width - 1 == i) {
            break;
          }
        }
        if (buff[start] == 'x' || buff[start] == 'X') {
          x_c++;
        }
        if (x_c > 1) {
          break;
        }
        array[i] = buff[start];
        if (buff[start] != '0' &&
            (buff[start + 1] == 'x' || buff[start + 1] == 'X')) {
          i += 1;
          break;
        }
        start++;
      }
      array[i] = '\0';
      long long res = 0;
      int result = 0;
      int b = 0;

      for (b = 0; b < i; b++) {
        if (array[b] >= '0' && array[b] <= '9') {
          result = array[b] - 48;
        } else {
          if (array[b] != 'x' && array[b] != 'X') {
            result = Hex_letters(array[b]);
          }
        }
        res += result * pow(16, i - b - 1);
      }
      if (minus == 1) {
        res *= -1;
      }
      Hex_type_choice(res, variable, opt, type);
      opt->on_next_to_read = start;
      while (buff[start] == ' ') {
        start += 1;
      }
      *pointer_to_string = start;
    } else {
      opt->stoppage = 1;
    }
  } else {
    opt->stoppage = 1;
  }
}
void Hex_type_choice(long long res, va_list variable, struct option* opt,
                     char type) {
  if (type == '0') {
    if (opt->exclusion == 0) {
      int* sh = (int*)va_arg(variable, int*);
      *sh = res;
      opt->count += 1;
    }
  }
  if (type == 'x') {
    if (opt->exclusion == 0) {
      unsigned int* sh = (unsigned int*)va_arg(variable, unsigned int*);
      *sh = res;
      opt->count += 1;
    }
  }
  if (type == 'H') {
    if (opt->exclusion == 0) {
      unsigned short int* sh =
          (unsigned short int*)va_arg(variable, unsigned short int*);
      *sh = res;
      opt->count += 1;
    }
  }
  if (type == 'h') {
    if (opt->exclusion == 0) {
      short int* sh = (short int*)va_arg(variable, short int*);
      *sh = res;
      opt->count += 1;
    }
  }
  if (type == 'l') {
    if (opt->exclusion == 0) {
      long int* sh = (long int*)va_arg(variable, long int*);
      *sh = res;
      opt->count += 1;
    }
  }
  if (type == 'L') {
    if (opt->exclusion == 0) {
      unsigned long int* sh =
          (unsigned long int*)va_arg(variable, unsigned long int*);
      *sh = res;
      opt->count += 1;
    }
  }
}
