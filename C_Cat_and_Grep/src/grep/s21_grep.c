#include "s21_grep.h"

#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char **argv) {
  struct flags fl;
  fl.c = 0;
  fl.e = 0;
  fl.i = 0;
  fl.l = 0;
  fl.n = 0;
  fl.v = 0;
  fl.f = 0;
  fl.h = 0;
  fl.s = 0;
  fl.o = 0;
  int count = 0;
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-e") == 0 && (int)strlen(argv[i]) > 2) {
      count++;
    }
    count++;
  }
  int array_of_patternfile[count];
  int count_of_patternfile = 0;
  char *array_of_patterns[count];
  char *array_of_files[count];
  int count_of_files = 0;
  for (int i = 0; i < count; i++) {
    array_of_files[i] = NULL;
    array_of_patternfile[i] = 0;
    array_of_patterns[i] = NULL;
  }
  int count_for_patterns = 0;
  parser(argc, argv, &fl, array_of_patterns, &count_for_patterns,
         array_of_files, &count_of_files, array_of_patternfile,
         &count_of_patternfile);
  print_result(argv, array_of_patterns, &count_for_patterns, array_of_files,
               &count_of_files, &fl, array_of_patternfile,
               &count_of_patternfile);
  return 0;
}
