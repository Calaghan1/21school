#include "s21_string.h"

void *s21_memchr(const void *str, int c, s21_size_t n) {
  void *res = s21_NULL;

  for (s21_size_t i = 0; i < n; i++) {
    if (c == ((char *)str)[i]) {
      res = ((char *)str) + i;
      break;
    }
  }
  //   ищет заданный символ по аски
  return res;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  int res = 0;

  for (s21_size_t i = 0; i < n; i++) {
    if (((char *)str1)[i] - ((char *)str2)[i] != 0) {
      res = ((char *)str1)[i] - ((char *)str2)[i];
      break;
    }
  }
  //  сравнивает посимвольно и возвращает разницу первого расхождения по аски
  return res;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  if (dest != s21_NULL && src != s21_NULL) {
    s21_size_t len_src = s21_strlen(src);
    s21_size_t len_dest = s21_strlen(dest);
    char *str1 = (char *)dest;
    char *str2 = (char *)src;

    if (str1 > &(str2[len_src]) || &(str1[len_dest]) < str2) {
      for (s21_size_t i = 0; i < n; i++) {
        ((char *)dest)[i] = ((char *)src)[i];
      }
    }
  }
  //  копирует n байт из src в dest
  return (void *)dest;
}

void *s21_memmove(void *dest, const void *src, s21_size_t n) {
  char buff[n];

  for (s21_size_t i = 0; i < n; i++) {
    buff[i] = ((char *)src)[i];
  }
  for (s21_size_t i = 0; i < n; i++) {
    ((char *)dest)[i] = buff[i];
  }
  //  копирует n символов строки src в dest (можно пересекающиеся)
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    ((char *)str)[i] = c;
  }
  // заполняет символом с n раз
  return str;
}

char *s21_strcat(char *dest, const char *src) {
  char *str1 = dest;
  char *str2 = (char *)src;

  while (*str1 != '\0') {
    str1++;
  }

  for (s21_size_t i = 0; str2[i] != '\0'; i++, str1++) {
    *str1 = str2[i];
  }
  *str1 = '\0';
  // копирует строку src в dest
  return dest;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  char *res = dest;

  while (*dest) dest++;
  for (s21_size_t i = 0; i < n; i++) {
    *dest++ = *src++;
  }
  // копирует n символов строки src в dest
  return res;
}

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  char *str1 = (char *)str;
  int i = 0;

  while (str[i] != '\0') {
    if (str1[i] == c) {
      res = &(str1[i]);
      break;
    }
    i++;
  }
  if (c == '\0' && str1[i] == c) {
    res = &(str1[i]);
  }
  // ищет первое вхождение с в строке
  return res;
}

int s21_strcmp(const char *str1, const char *str2) {
  while (*str1 != '\0' && *str1 == *str2) {
    str1++;
    str2++;
  }
  //  строки равны - вернет 0, либо разницу первого различного символа по аски
  return *str1 - *str2;
}

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  for (s21_size_t i = 1; i < n && *str1 == *str2; i++) {
    str1++;
    str2++;
  }
  //  сравнивает n байт, равны - вернет 0, либо разницу первого различного
  //  символа по аски
  return *str1 - *str2;
}

char *s21_strcpy(char *dest, const char *src) {
  char *res = dest;

  if (dest != s21_NULL && src != s21_NULL) {
    while (*src != '\0') {
      *dest++ = *src++;
    }
    *dest = '\0';
  }
  //  копирует строку src в dest
  return res;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  for (s21_size_t i = 0; i < n; i++) {
    dest[i] = src[i];
    if (src[i] == '\0') {  //  если src < n, заполняет дальше '\0'
      for (; i < n; i++) {
        dest[i] = '\0';
      }
    }
  }
  // копирует n байт из src в dest
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t len1 = s21_strlen(str1);
  s21_size_t len2 = s21_strlen(str2);
  s21_size_t res = len1;

  for (s21_size_t i = 0; i < len1; i++) {
    for (s21_size_t j = 0; j < len2; j++) {
      if (str1[i] == str2[j]) {
        res = i;
        i = len1;
        break;
      }
    }
  }
  //   возвращает длину str1 без символов str2
  return res;
}

char *s21_strerror(int errnum) {
  static char res[1024] = {'\0'};
  char *errors[MAXERRORS] = ERRORS;

  if (errnum > 0 && errnum < MAXERRORS) {
#ifdef __APPLE__
    errnum--;
#endif
    s21_strcpy(res, errors[errnum]);
  } else {
#ifdef __linux__
    if (errnum == 0) {
      s21_sprintf(res, "Success");
    } else {
      s21_sprintf(res, "Unknown error %d", errnum);
    }
#elif __APPLE__
    if (errnum == 0) {
      s21_sprintf(res, "Undefined error: %d", errnum);
    } else {
      s21_sprintf(res, "Unknown error: %d", errnum);
    }
#endif
  }
  // возвращает тескт номера ошибки errnum
  return res;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t i = 0;

  if (str != s21_NULL) {
    while (str[i] != '\0') {
      i++;
    }
  }
  // возвращает длину строки
  return i;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *res = s21_NULL;
  int flag = 0;

  if (str1 != NULL && str2 != NULL) {
    int i = 0;
    while (str1[i] != '\0' && flag != 1) {
      for (int j = 0; str2[j] != '\0'; j++) {
        if (str1[i] == str2[j]) {
          res = (char *)(&str1[i]);
          flag = 1;
          break;
        }
      }
      /*
    for (int i = 0; str1[i] != '\0' && flag != 1; i++) {
        printf("\nA\nA\nA\n");
        if (flag == 0) {
            for (int j = 0; str2[j] != '\0'; j++) {
              if (str1[i] == str2[j]) {
                res = (char *)(&str1[i]);
                flag = 1;
                break;
              }
        }
        } else {
            break;
        }
       */
    }
  }

  return res;
}

char *s21_strrchr(const char *str, int c) {
  char *res = s21_NULL;
  int i = s21_strlen(str);

  if (c == '\0') {
    res = (char *)(str + i);
  } else {
    i--;
    for (; i >= 0; i--) {
      if (str[i] == c) {
        res = (char *)(str + i);
        break;
      }
    }
  }
  // возвращает последнее вхождение символа
  return res;
}

s21_size_t s21_strspn(const char *str1, const char *str2) {
  int quantity = 0;

  for (int i1 = 0; str1[i1] != '\0'; i1++) {
    int i;

    for (i = 0; str2[i] != '\0'; i++) {
      if (str1[i1] == str2[i]) {
        quantity++;
        break;
      }
    }
    if (str2[i] == '\0') {
      break;
    }
  }
  // возвращает кол-во символов из списка str2
  return quantity;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = s21_NULL;

  if (needle[0] != '\0') {
    int seek = 0;
    int i = 0;

    for (; haystack[i] != '\0'; i++) {
      if (haystack[i] == needle[seek]) {
        seek++;
        if (needle[seek] == '\0') {
          break;
        }
      } else {
        seek = 0;
      }
    }

    if (seek > 0) {
      i = i - seek + 1;
      res = (char *)(haystack + i);
    } else {
      res = s21_NULL;
    }
  } else {
    res = (char *)(haystack);
  }
  // ищет подстроку, вернет указатель на начало
  return res;
}

char *s21_strtok(char *str, const char *delim) {
  int end_of_token = 0;
  static char *static_str = s21_NULL;

  if (delim != s21_NULL && delim[0] == '\0') {
    return str;
  }

  if (delim == s21_NULL || (str == s21_NULL && static_str == s21_NULL)) {
    return s21_NULL;
  }
  if (str == s21_NULL) {
    str = static_str;
  }
  int del_f = 1;
  int flag = 0;
  while (del_f != 0) {
    for (int i = 0; delim[i] != '\0'; i++) {
      if (str[0] == delim[i]) {
        static_str = (str + 1);
        str[0] = '\0';
        str = static_str;
      }
      del_f = 1;
      if (delim[i + 1] == '\0') {
        for (int i1 = 0; delim[i1] != '\0'; i1++) {
          if (str[0] == delim[i1]) {
            del_f = 2;
          }
        }
        if (del_f != 2) {
          del_f = 0;
        }
      }
    }
  }
  for (; str[end_of_token] != '\0'; end_of_token++) {
    for (int i = 0; delim[i] != '\0'; i++) {
      if (str[end_of_token] == delim[i]) {
        flag = 1;
      }
    }
    if (flag == 1) {
      break;
    }
  }
  str[end_of_token] = '\0';
  if (flag == 0) {
    static_str = s21_NULL;
    return str;
  }

  if ((void *)(str + end_of_token + 1) != s21_NULL) {
    static_str = (str + end_of_token + 1);
  } else {
    static_str = s21_NULL;
  }
  return str;
}

// Дополнительные функции из C#:

void *s21_to_upper(const char *str) {
  char *tmp = s21_NULL;

  if (str != s21_NULL) {
    tmp = calloc(s21_strlen(str) + 1, (s21_size_t)sizeof(char));

    if (tmp != s21_NULL) {
      int i = 0;
      for (; str[i] != '\0'; i++) {
        tmp[i] = str[i];
        if (str[i] >= 'a' && str[i] <= 'z') {
          tmp[i] -= 32;
        }
      }
      tmp[i] = '\0';
    }
  }
  // перевод в нижний регистр
  return tmp;
}

void *s21_to_lower(const char *str) {
  char *tmp = s21_NULL;

  if (str != s21_NULL) {
    tmp = calloc(s21_strlen(str) + 1, (s21_size_t)sizeof(char));

    if (tmp != s21_NULL) {
      int i = 0;
      for (; str[i] != '\0'; i++) {
        tmp[i] = str[i];
        if (str[i] >= 'A' && str[i] <= 'Z') {
          tmp[i] += 32;
        }
      }
      tmp[i] = '\0';
    }
  }
  // перевод в нижний регистр
  return tmp;
}

void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  s21_size_t len_src = s21_strlen(str);
  s21_size_t len_str = s21_strlen(src);
  s21_size_t length = len_src + len_str + 1;
  char *res = calloc(length, sizeof(char));

  if (!src || !str) {
    free(res);
    res = s21_NULL;
  } else {
    s21_size_t i = 0, j = 0, k = 0;
    while (i < start_index) {
      res[i] = src[i];
      i++;
    }
    while (j < len_src) {
      res[i + j] = str[j];
      j++;
    }
    while (k < (len_str - start_index)) {
      res[i + j + k] = src[start_index + k];
      k++;
    }
  }
  // вставка строки
  return (void *)res;
}

void delete_first_char(char *str) {
  int count = 0;
  while (str[count]) {
    str[count] = str[count + 1];
    count++;
  }
}

void left_part(char *res, const char *src, const char *trim_chars) {
  s21_size_t len_src = s21_strlen(src);
  s21_size_t len_trim_chars = s21_strlen(trim_chars);

  for (s21_size_t i = 0; i < len_src; i++) {
    int is_break = 1;
    for (s21_size_t j = 0; j < len_trim_chars; j++) {
      if (src[i] == trim_chars[j]) {
        delete_first_char(res);
        is_break = 0;
        break;
      }
    }
    if (is_break) break;
  }
}

void right_part(char *res, const char *trim_chars) {
  int len_res = s21_strlen(res);
  int len_trim_chars = s21_strlen(trim_chars);

  for (int i = len_res - 1; i >= 0; i--) {
    int is_break = 1;
    for (int j = 0; j < len_trim_chars; j++) {
      if (res[i] == trim_chars[j]) {
        res[i] = '\0';
        is_break = 0;
        break;
      }
    }
    if (is_break) break;
  }
}

void *s21_trim(const char *src, const char *trim_chars) {
  char *res = calloc(s21_strlen(src), sizeof(char));

  s21_strcpy(res, src);
  left_part(res, src, trim_chars);
  right_part(res, trim_chars);

  return (void *)res;
}
