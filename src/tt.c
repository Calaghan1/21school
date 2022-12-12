#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *s21_strcpy(char *dest, const char *src);
void left_part(char *res, const char *src, const char *trim_chars);
void right_part(char *res, const char *trim_chars);
void *s21_trim(const char *src, const char *trim_chars);
char *s21_strcpy(char *dest, const char *src);
char *s21_strstr(const char *haystack, const char *needle);
size_t s21_strlen(const char *str);
int main() {
  //     printf("%d", strlen(""));
  char str[100] = "";
  char *stt = NULL;
  char str1[100] = "";
  // char *str2 = s21_trim(str, str1);
  // printf("%s", str2);
  printf("%s|\n", s21_strstr(stt, str1));
  printf("%s|", strstr(stt, str1));
  // free(str2);
  return 0;
}

void delete_first_char(char *str) {
  int count = 0;
  while (str[count]) {
    str[count] = str[count + 1];
    count++;
  }
}

void left_part(char *res, const char *src, const char *trim_chars) {
  size_t len_src = s21_strlen(src);
  size_t len_trim_chars = s21_strlen(trim_chars);

  for (size_t i = 0; i < len_src; i++) {
    int is_break = 1;
    for (size_t j = 0; j < len_trim_chars; j++) {
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
  char *res = NULL;
  res = calloc(s21_strlen(src), sizeof(char));
  if (res != NULL) {
    s21_strcpy(res, src);
    left_part(res, src, trim_chars);
    right_part(res, trim_chars);
  }
  return (void *)res;
}

char *s21_strcpy(char *dest, const char *src) {
  char *res = dest;

  if (dest != NULL && src != NULL) {
    while (*src != '\0') {
      *dest++ = *src++;
    }
    *dest = '\0';
  }
  //  копирует строку src в dest
  return res;
}

size_t s21_strlen(const char *str) {
  size_t i = 0;

  if (str != NULL) {
    while (str[i] != '\0') {
      i++;
    }
  }
  // возвращает длину строки
  return i;
}

char *s21_strstr(const char *haystack, const char *needle) {
  char *res = NULL;

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
      res = NULL;
    }
  } else {
    res = (char *)(haystack);
  }
  // ищет подстроку, вернет указатель на начало
  return res;
}