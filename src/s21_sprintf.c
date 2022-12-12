#include "s21_string.h"

void chek_for_space(char *res, int *index, int *width, struct flags fl) {
  if (!fl.flag_for_min && !fl.flag_for_plus && fl.flag_for_space) {
    res[*index] = ' ';
    *index += 1;
    *width -= 1;
  }
}
int s21_sprintf(char *ptrult, char *format, ...) {
  va_list ap;
  struct flags fl = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int index = 0;
  va_start(ap, format);
  int i = 0;
  int ans;
  int ans_for_dot;
  // int count = 0;
  while (format[i] != '\0') {
    if (format[i] == '%') {
      ans = 0;
      ans_for_dot = -1;
      fl.flag_for_L = 0;
      fl.flag_for_fl = 0;
      fl.flag_for_sh = 0;
      fl.flag_for_shift = 0;
      fl.flag_for_plus = 0;
      fl.flag_for_grid = 0;
      fl.flag_for_zero = 0;
      fl.flag_for_min = 0;
      fl.flag_for_space = 0;
      i++;
      while (format[i] == '-' || format[i] == '+' || format[i] == '#' ||
             format[i] == '0' || format[i] == ' ') {
        if (format[i] == '-') {
          fl.flag_for_shift = 1;
        }
        if (format[i] == '+') {
          fl.flag_for_plus = 1;
        }
        if (format[i] == '#') {
          fl.flag_for_grid = 1;
        }
        if (format[i] == '0') {
          fl.flag_for_zero = 1;
        }
        if (format[i] == ' ') {
          fl.flag_for_space = 1;
        }
        i++;
      }
      if ((format[i] >= '0' && format[i] <= '9') || format[i] == '.' ||
          format[i] == '*') {
        get_lengh_and_dots(format, &ans, &ans_for_dot, &i, &ap);
      }
      // if (flag_for_zero == 1) {
      //   if (ans_for_dot < ans) {
      //     ans_for_dot = ans;
      //     ans = 0;
      //   }
      // }

      if (format[i] == 'L') {
        i++;
        fl.flag_for_L = 1;
      }
      if (format[i] == 'l') {
        i++;
        fl.flag_for_l = 1;
      }
      if (format[i] == 'h') {
        i++;
        fl.flag_for_sh = 1;
      }
      if (format[i] == 'd' || format[i] == 'i') {
        long long int lx = 0;
        if (fl.flag_for_L) {
          long long int l = va_arg(ap, long long int);
          lx = l;
        } else if (fl.flag_for_l) {
          //переполнение на лонг инт
          long int l = va_arg(ap, long long int);
          lx = l;
        } else if (fl.flag_for_sh) {
          short int l = va_arg(ap, long long int);
          lx = l;
          //переполнение на шорт инт
        } else {
          int l = va_arg(ap, long long int);
          lx = l;
          //     if(lx > 2147483647) {
          //   lx = -2147483648 + (lx - 2147483648);
          // }
        }
        if (lx < 0) {
          fl.flag_for_min = 1;
          ans--;
          lx = -1 * lx;
        }
        if (fl.flag_for_plus && !fl.flag_for_min) {
          ans--;
        }
        chek_for_space(ptrult, &index, &ans, fl);
        do_funk_d(ptrult, &index, lx, ans, ans_for_dot, fl);
      } else if (format[i] == 'c') {
        // ans += ans_for_dot;
        ans -= 1;
        if (!fl.flag_for_shift) {
          for (int j = 0; j < ans; j++, index++) {
            ptrult[index] = ' ';
          }
        }
        ptrult[index++] = va_arg(ap, int);
        if (fl.flag_for_shift) {
          for (int j = 0; j < ans; j++, index++) {
            ptrult[index] = ' ';
          }
        }

      } else if (format[i] == 'e' || format[i] == 'E') {
        long double Lh;
        int dec = 0;
        if (format[i] == 'e') {
          dec = 32;
        }
        if (fl.flag_for_L) {
          Lh = va_arg(ap, long double);
        } else {
          double h = va_arg(ap, double);
          Lh = h;
        }

        if (Lh < 0) {
          fl.flag_for_min = 1;
          Lh = fabsl(Lh);
        }
        chek_for_space(ptrult, &index, &ans, fl);
        double_to_sci(ptrult, &index, Lh, ans_for_dot, ans, dec, &fl);
      } else if (format[i] == 'o') {
        long long int res1;

        if (fl.flag_for_sh) {
          unsigned short int xl = va_arg(ap, unsigned int);
          res1 = xl;
        } else if (fl.flag_for_l) {
          unsigned long int xl = va_arg(ap, unsigned long int);
          res1 = xl;
        } else {
          unsigned int xl = va_arg(ap, unsigned int);
          res1 = xl;
        }

        chek_for_space(ptrult, &index, &ans, fl);
        eigh_to_dec(ptrult, &index, res1, ans_for_dot, ans, fl);
      } else if (format[i] == 'f') {
        long double Lh;
        if (fl.flag_for_L) {
          Lh = va_arg(ap, long double);
        } else {
          double h = va_arg(ap, double);
          Lh = h;
        }
        // int c = 0;
        // if (Lh == -0.0) {
        //   c = -1;
        // }
        if (Lh < 0) {
          fl.flag_for_min = 1;
          Lh = fabsl(Lh);
        }
        chek_for_space(ptrult, &index, &ans, fl);
        do_funk_f(ptrult, &index, Lh, ans, ans_for_dot, &fl);

      } else if (format[i] == 'g' || format[i] == 'G') {
        long double Lh;
        if (fl.flag_for_L) {
          Lh = va_arg(ap, long double);
        } else {
          double h = va_arg(ap, double);
          Lh = h;
        }
        if (Lh < 0) {
          fl.flag_for_min = 1;
          Lh = fabsl(Lh);
        }
        int dec = 0;
        if (format[i] == 'g') {
          dec = 32;
        }
        chek_for_space(ptrult, &index, &ans, fl);
        do_funk_g(ptrult, &index, Lh, ans, ans_for_dot, dec, &fl);

      } else if (format[i] == 'n') {
        int *x1 = va_arg(ap, int *);
        *x1 = index;
      } else if (format[i] == 'x' || format[i] == 'X') {
        int dec = 0;
        long long int res1;
        if (format[i] == 'x') {
          dec = 32;
        }
        if (fl.flag_for_sh) {
          unsigned short int x = va_arg(ap, unsigned int);
          res1 = x;
        } else if (fl.flag_for_l) {
          unsigned long int x = va_arg(ap, unsigned long int);
          res1 = x;
        } else {
          unsigned int x = va_arg(ap, unsigned int);
          res1 = x;
        }
        get_hex_from_dec(ptrult, &index, res1, ans_for_dot, ans, dec, fl);

      } else if (format[i] == 'p') {
        char *addres = (char *)va_arg(ap, char *);
        long int addres_buff = (long int)addres;
        fl.flag_for_grid = 1;
        get_hex_from_dec(ptrult, &index, addres_buff, ans_for_dot, ans, 32, fl);

      } else if (format[i] == 'u') {
        long long int res1 = 0;
        if (fl.flag_for_l) {
          unsigned long int x = va_arg(ap, unsigned long int);
          res1 = x;
        } else if (fl.flag_for_sh) {
          unsigned short int x = va_arg(ap, unsigned int);
          res1 = x;
        } else {
          unsigned int x = va_arg(ap, unsigned int);
          res1 = x;
        }
        do_funk_d(ptrult, &index, res1, ans, ans_for_dot, fl);
      } else if (format[i] == 's') {
        char *string = va_arg(ap, char *);
        if (ans_for_dot == -1) {
          ans_for_dot = 10000;
          ans -= s21_strlen(string);
        } else {
          ans += ans_for_dot - s21_strlen(string);
        }
        for (int k = 0; k < ans; k++) {
          ptrult[index] = ' ';
          index++;
        }
        while (*string != '\0' && (ans_for_dot > 0)) {
          ptrult[index] = *string;
          index++;
          string++;
          ans_for_dot--;
        }
      } else if (format[i] == '%') {
        ptrult[index] = format[i];
        index++;
      }
    } else {
      ptrult[index] = format[i];
      index++;
    }
    i++;
  }
  va_end(ap);
  ptrult[index] = '\0';

  return index;
}

void get_hex_from_dec(char *ptrult, int *index, long long int dec, int ans,
                      int ans_for_space, int decr, struct flags fl) {
  char buff_str[100] = {'\0'};
  int count = 0;
  char *p = buff_str;
  long long int ost = dec % 16;
  while (dec != 0) {
    switch (ost) {
      case (10):
        *p = ('A' + decr);
        p++;
        break;
      case (11):
        *p = ('B' + decr);
        p++;
        break;
      case (12):
        *p = ('C' + decr);
        p++;
        break;
      case (13):
        *p = ('D' + decr);
        p++;
        break;
      case (14):
        *p = ('E' + decr);
        p++;
        break;
      case (15):
        *p = ('F' + decr);
        p++;
        break;
      default:
        *p = ost + 48;
        p++;
        break;
    }
    dec /= 16;
    ost = dec % 16;
  }
  char *l = buff_str;
  p--;

  while (p > l) {
    char t;
    t = *p;
    *p = *l;
    *l = t;
    p--;
    l++;
  }
  p = buff_str;
  while (*(p) != '\0') {
    count++;
    p++;
  }
  // printf("WIDTH %d ACCUARCY %d count %d\n", ans_for_space, ans, count);
  if (count >= ans) {
    ans_for_space = ans_for_space - (count - ans) + fl.flag_for_grid * 2;
    ans = 0;
  } else {
    ans = ans - count - fl.flag_for_grid * 2;
  }
  ans_for_space -= fl.flag_for_grid * 2;
  // printf("----WIDTH %d ACCUARCY %d count %d\n", ans_for_space, ans, count);
  if (!fl.flag_for_shift) {
    for (int i = 0; i < ans_for_space; i++) {
      if (fl.flag_for_zero) {
        ptrult[*index] = '0';
      } else {
        ptrult[*index] = ' ';
      }
      *index += 1;
    }
  }
  for (int i = 0; i < ans; i++) {
    ptrult[*index] = '0';
    *index += 1;
  }
  if (fl.flag_for_grid) {
    ptrult[*index] = '0';
    *index += 1;
    ptrult[*index] = 'x';
    *index += 1;
  }
  p = buff_str;
  while (count) {
    ptrult[*index] = *p;
    p++;
    *index += 1;
    count--;
  }
  if (fl.flag_for_shift) {
    for (int i = 0; i < ans_for_space; i++) {
      if (fl.flag_for_zero) {
        ptrult[*index] = '0';
      } else {
        ptrult[*index] = ' ';
      }
      *index += 1;
    }
  }
}
void eigh_to_dec(char *ptrult, int *index, long long int dec, int ans,
                 int ans_for_space, struct flags fl) {
  char buff_str[100];
  int count = 0;
  long long int buff = 0;
  char *p = buff_str;
  while (dec != 0) {
    *p = (dec % 8) + '0';
    p++;
    dec /= 8;
    count++;
  }
  int counter = count;
  char *l = buff_str;
  p--;
  while (p > l) {
    char t;
    t = *p;
    *p = *l;
    *l = t;
    p--;
    l++;
  }
  p = buff_str;
  while (count) {
    buff *= 10;
    buff += (*p - 48);
    p++;
    count--;
  }
  // printf("WIDTH %d ACCUARCY %d count %d\n", ans_for_space, ans, counter);
  if (counter >= ans) {
    ans_for_space = ans_for_space - (counter - ans) + fl.flag_for_grid * 2;
    ans = 0;
  } else {
    ans = ans - counter - fl.flag_for_grid * 2;
  }
  ans_for_space -= fl.flag_for_grid * 2;
  // printf("----WIDTH %d ACCUARCY %d count %d\n", ans_for_space, ans, counter);
  if (!fl.flag_for_shift) {
    for (int i = 0; i < ans_for_space; i++) {
      if (fl.flag_for_zero) {
        ptrult[*index] = '0';
      } else {
        ptrult[*index] = ' ';
        *index += 1;
      }
    }
    for (int i = 0; i < ans; i++) {
      ptrult[*index] = '0';
      *index += 1;
    }
  }
  do_funk_d(ptrult, index, buff, 0, 0, fl);
  if (fl.flag_for_shift) {
    for (int i = 0; i < ans_for_space; i++) {
      if (fl.flag_for_zero) {
        ptrult[*index] = '0';
      } else {
        ptrult[*index] = ' ';
      }
      *index += 1;
    }
  }
}
void get_lengh_and_dots(const char *format, int *ans, int *ans_for_dot, int *i,
                        va_list *ap) {
  int l = *i;
  int flag = 0;
  int flag2 = 0;
  // int flag3 = 0;
  int flag4 = 0;
  while ((format[l] > 47 && format[l] < 58) || format[l] == '*') {
    l++;
  }
  if (format[*i] == '.') {
    flag = 1;
  }
  if (format[l] == '.') {
    flag = 1;
  }
  if (flag == 1) {
    *ans_for_dot = 0;
  }
  if (format[*i] == '*') {
    *ans = va_arg(*ap, int);
    *i += 1;
    flag2 = 1;
  }
  if ((format[*i] > 47 && format[*i] < 58) && flag2 == 1) {
    *ans = 0;
  }
  while (format[*i] > 47 && format[*i] < 58) {
    flag2 = 0;
    *ans *= 10;
    *ans += format[*i] - 48;
    *i += 1;
  }
  if (format[*i] == '*') {
    *ans = va_arg(*ap, int);
    *i += 1;
    flag2 = 1;
  }
  if (format[*i] > 47 && format[*i] < 58 && flag2 == 1) {
    *ans = 0;
  }
  while (format[*i] > 47 && format[*i] < 58) {
    // flag2 = 0;
    *ans *= 10;
    *ans += format[*i] - 48;
    *i += 1;
  }
  l++;
  while ((format[l] > 47 && format[l] < 58) ||
         (format[l] == '*' && flag == 1)) {
    if (format[l] == '*') {
      flag4 = 1;
      *ans_for_dot = va_arg(*ap, int);
      l++;
      while (format[l] > 47 && format[l] < 58) {
        l++;
      }
      *i = l;
    }
    l++;
  }
  if (flag == 1 && flag4 == 0) {  /// dot
    *i += 1;
    while (format[*i] > 47 && format[*i] < 58) {
      // flag3 = 0;
      *ans_for_dot *= 10;
      *ans_for_dot += format[*i] - 48;
      *i += 1;
    }
  }
  if (*ans_for_dot > 0) {
    *ans = *ans - *ans_for_dot;
  }
}

void double_to_sci(char *ptrult, int *index, long double num, int ans,
                   int ans_for_space, int dec, struct flags *fl) {
  char buff_str[100] = {'\0'};
  int buff_index = 0;
  if (ans < 0) {
    ans = 6;
  }
  int fl1 = fl->flag_for_min;
  int count = 0;
  int buff_pow = 0;
  char sign = (int)num == 0 ? '-' : '+';
  int pow = get_e_from_double(&num);
  do_funk_f(buff_str, &buff_index, num, 0, ans, fl);
  fl->flag_for_e = 0;
  int index_buff = buff_index - 1;
  if (ans == 0) {
    while (buff_str[index_buff] == '0') {
      if (buff_str[index_buff - 1] != '.') {
        buff_str[index_buff] = '\0';
      } else {
        break;
      }
      index_buff--;
      buff_index--;
      buff_pow++;
    }
    // printf("Drager = %c\n\n",ptrult[index_buff + 2]);
    // if(ptrult[index_buff+1] == '0' && ptrult[index_buff+2] == '.'){
    // ptrult[index_buff+1] = '\0'; ptrult[index_buff + 2] = '.';
    // ptrult[index_buff + 3] == '0';
    // ptrult[index_buff + 4] == '\0';
    // }
  }
  while (buff_str[index_buff] != '.' && index_buff != 0) {
    index_buff--;
  }
  if (buff_str[index_buff] == '.') {
    count = 0;
    index_buff--;
    while (buff_str[index_buff] == '0') {
      count++;
      index_buff--;
    }
    // if(buff_str[index_buff] >= '0' &&  '9' <= buff_str[index_buff]) {
    buff_str[index_buff + count] = buff_str[index_buff];
    //}
  }
  pow += count + buff_pow;

  buff_str[buff_index] = 'E' + dec;
  buff_index += 1;
  if (!pow) {
    sign = '+';
  }
  buff_str[buff_index] = sign;
  buff_index += 1;
  buff_str[buff_index] = '0';
  buff_index += 1;
  pow = abs(pow);
  buff_str[buff_index] = pow + '0';
  buff_index += 1;

  ans_for_space -= buff_index - 2 + 1 * fl1;
  if (!fl->flag_for_shift) {
    for (int i = 0; i < ans_for_space; i++) {
      if (fl->flag_for_zero) {
        ptrult[*index] = '0';
      } else {
        ptrult[*index] = ' ';
        *index += 1;
      }
    }
  }
  for (int i = count; i < buff_index; i++) {
    ptrult[*index] = buff_str[i];
    *index += 1;
  }
  if (fl->flag_for_shift) {
    for (int i = 0; i < ans_for_space; i++) {
      if (fl->flag_for_zero) {
        ptrult[*index] = '0';
      } else {
        ptrult[*index] = ' ';
        *index += 1;
      }
    }
  }
}

void do_funk_d(char *res, int *index, long long int number, int width,
               int accuracy, struct flags fl) {
  char str[100] = {'\0'};
  char *p = str;
  int count = digits_in_int(number);
  get_str_from_long_int(str, number, count);
  if (accuracy < 0) {
    width -= count;
  }
  if (fl.flag_for_min && fl.flag_for_zero) {
    res[*index] = '-';
    *index += 1;
  }
  if (fl.flag_for_plus && !fl.flag_for_min && fl.flag_for_zero) {
    res[*index] = '+';
    *index += 1;
  }
  if (!fl.flag_for_shift) {
    for (int i = 0; i < width; i++) {
      if (fl.flag_for_zero) {
        res[*index] = '0';
      } else {
        res[*index] = ' ';
      }
      *index += 1;
    }
  }
  if (fl.flag_for_min && !fl.flag_for_zero) {
    res[*index] = '-';
    *index += 1;
  }
  if (fl.flag_for_plus && !fl.flag_for_min && !fl.flag_for_zero) {
    res[*index] = '+';
    *index += 1;
  }
  accuracy -= count;
  for (int i = 0; i < accuracy; i++) {
    res[*index] = '0';
    *index += 1;
  }

  // if (number == 0) {
  //   res[*index] = '0';
  //   *index += 1;
  // }
  for (int i = 0; i < count; i++) {
    res[*index] = *p;
    p++;
    *index += 1;
  }
  if (fl.flag_for_shift) {
    for (int i = 0; i < width; i++) {
      if (fl.flag_for_zero) {
        res[*index] = ' ';
      } else {
        res[*index] = ' ';
      }
      *index += 1;
    }
  }
}
int digits_in_int(long long int number) {
  int count = 0;
  if (number == 0) {
    return 1;
  }
  while (number != 0) {
    count++;
    number /= 10;
  }
  return count;
}

int get_str_from_long_int(char *str, long long int dec, int count) {
  char *p = str;
  char *tmp1 = (char *)malloc(count * ((s21_size_t)sizeof(char)));

  int i = count - 1;
  while (dec) {
    tmp1[i] = (char)(dec % 10 + 48);
    dec /= 10;
    i--;
  }
  while (i >= 0) {
    tmp1[i] = '0';
    i--;
  }
  for (int j = 0; j < count; j++) {
    *p = tmp1[j];
    p++;
  }
  free(tmp1);
  return count;
}

void do_funk_f(char *res, int *index, long double number, int width,
               int accuracy, struct flags *fl) {
  char buff[100] = {'\0'};
  width = width + accuracy;
  int flag_for_min = fl->flag_for_min;
  int flag_for_plus = fl->flag_for_plus;
  fl->flag_for_plus = 0;
  fl->flag_for_min = 0;
  int buffindex = 1;
  // char *p = buff;
  long long int evenp = (long long int)number;
  // int count_for_even = digits_in_int(evenp);
  if (accuracy == -1) {
    accuracy = 6;
  }
  evenp = llabs(evenp);

  // if (fl.flag_for_e && evenp == 0 ) {
  //   number *= 10;
  //   evenp = (long long int)number;
  // }
  do_funk_d(buff, &buffindex, evenp, 0, 0, *fl);
  // printf("EVENPSTR - %s\n", buff);
  if (accuracy > 0 || fl->flag_for_grid == 1) {
    buff[buffindex] = '.';
    buffindex += 1;
  }
  number = number - (long double)evenp;
  for (int i = 0; i < accuracy; i++) {
    number *= 10;
    evenp = (long int)number;
    buff[buffindex] = evenp + '0';
    buffindex += 1;
    number = number - (long double)evenp;
  }
  evenp = (long long int)number;
  long double montisa = number - (long double)evenp;
  int bindex = buffindex - 1;
  int flag_for_new_dig = 1;
  if (montisa >= 0.5) {
    int flag = 1;
    while (flag) {
      if (buff[bindex] == '9') {
        buff[bindex] = '0';
        bindex--;
      } else {
        if (buff[bindex] == '.') {
          bindex--;
        } else {
          if (buff[bindex] >= '0' && buff[bindex] <= '9') {
            buff[bindex] += 1;
          } else {
            buff[bindex] = '1';
            flag_for_new_dig = 0;
          }
          flag = 0;
        }
      }
    }
  }
  width =
      width - (buffindex - flag_for_new_dig) - (flag_for_min || flag_for_plus);
  if (flag_for_min && fl->flag_for_zero) {
    res[*index] = '-';
    *index += 1;
  }
  if (flag_for_plus && fl->flag_for_zero && !flag_for_min) {
    res[*index] = '+';
    *index += 1;
  }
  if (!fl->flag_for_shift) {
    for (int i = 0; i < width; i++) {
      if (fl->flag_for_zero) {
        res[*index] = '0';
      } else {
        res[*index] = ' ';
      }
      *index += 1;
    }
  }
  if (flag_for_min && !fl->flag_for_zero) {
    res[*index] = '-';
    *index += 1;
  }
  if (flag_for_plus && !fl->flag_for_zero && !flag_for_min) {
    res[*index] = '+';
    *index += 1;
  }
  for (int i = 0 + flag_for_new_dig; i < buffindex; i++) {
    res[*index] = buff[i];
    *index += 1;
  }
  if (fl->flag_for_shift) {
    for (int i = 0; i < width; i++) {
      if (fl->flag_for_zero) {
        res[*index] = ' ';
      } else {
        res[*index] = ' ';
      }
      *index += 1;
    }
  }
}

void do_funk_g(char *res, int *index, long double number, int width,
               int accuracy, int dec, struct flags *fl) {
  char buff_str[100];
  int index_buff = 0;
  // int save_acc = accuracy;
  if (accuracy > -1) {
    width += accuracy;
  }
  if (accuracy == 0) {
    accuracy = 1;
  }
  if (accuracy < 0) {
    accuracy = 6;
  }
  char sign = (int)number == 0 ? '-' : '+';
  long double buff = number;
  int count = get_e_from_double(&buff);
  // printf("ACC %d\n", accuracy);
  // printf("ASD %Lf\n", buff);
  // printf("COUNT %d\n", count);
  if (count < -4 || count >= accuracy) {
    // printf("ASD %Lf\n", buff);
    // printf("ACC %d\n", accuracy);
    // printf("COUNT %d\n", count);
    // buff = roundl(buff);
    do_funk_f(buff_str, &index_buff, buff, 0, accuracy - 1, fl);
    // printf("asdasd %d\n", fl.flag_for_grid);
    delete_all_last_zero_in_montisa(buff_str, &index_buff, *fl);
    buff_str[index_buff] = 'E' + dec;
    index_buff += 1;
    buff_str[index_buff] = sign;
    index_buff += 1;
    count = abs(count);
    if (count < 10) {
      buff_str[index_buff] = '0';
    }
    index_buff += 1;
    fl->flag_for_min = 0;
    do_funk_d(buff_str, &index_buff, count, 0, 0, *fl);
  } else {
    //  printf("ASD1 %Lf\n", number);
    // printf("ACC1 %d\n", accuracy);
    //  printf("COUNT1 %d\n", count);
    accuracy = accuracy - (count)-1;
    do_funk_f(buff_str, &index_buff, number, 0, accuracy, fl);
    // printf("STROKA GOVNA %s\n",buff_str );

    delete_all_last_zero_in_montisa(buff_str, &index_buff, *fl);
    // if (pow > 0 && save_acc < 2) {
    //   buff_str[index_buff] = 'E' + dec;
    //   index_buff += 1;
    //   buff_str[index_buff] = sign;
    //   index_buff += 1;
    //   pow = abs(pow);
    //   if (count < 10) {
    //     buff_str[index_buff] = '0';
    //   }
    //   index_buff += 1;
    //   do_funk_d(buff_str, &index_buff, pow, 0, 0, *fl);
    // }
  }
  width -= index_buff;
  if (!fl->flag_for_shift) {
    for (int i = 0; i < width; i++) {
      if (fl->flag_for_zero) {
        res[*index] = '0';
      } else {
        res[*index] = ' ';
      }
      *index += 1;
    }
  }
  for (int i = 0; i < index_buff; i++) {
    res[*index] = buff_str[i];
    *index += 1;
  }

  // if (fl.flag_for_grid == 1) {
  //   res[*index] = '.';
  //   *index+= 1;
  // }
  if (fl->flag_for_shift) {
    for (int i = 0; i < width; i++) {
      if (fl->flag_for_zero) {
        res[*index] = '0';
      } else {
        res[*index] = ' ';
      }
      *index += 1;
    }
  }
}

int get_e_from_double(long double *number) {
  int result = 0;
  if (*number > 1) {
    while (*number > 0.9999999) {
      *number /= 10;
      result++;
    }
    if ((int)*number == 0) {
      *number *= 10;
      result--;
    }
  } else {
    while (*number < 0.9999999) {
      *number *= 10;
      result--;
    }
    if ((int)*number > 9.9999) {
      *number /= 10;
      result++;
    }
  }
  return result;
}
int delete_all_last_zero_in_montisa(char *str, int *index, struct flags fl) {
  int count = 0;
  *index -= 1;
  while (str[*index] == '0') {
    str[*index] = '\0';
    count++;
    *index -= 1;
  }
  if (str[*index] == '.' && fl.flag_for_grid == 0) {
    str[*index] = '\0';
    *index -= 1;
  }
  *index += 1;
  return count;
}
