#include "calc_core.h"

int main() {
  printf("%lf\n", M_PI_2);
  char str[256] = {'\0'};
  char str1[256] = {'\0'};
  scanf("%[^\n]s", str);
  if (find_token(str, str1)) {
    printf("FIND TOKEN %s\n", str1);
    clean_str(str);
    To_Polish(str1, str);
    printf("POLISH %s\n", str);
    printf("%lf", calc_resutl(str, 0));
  } else {
    printf("ERROR\n");
  }
  //     double X = -10;
  //     double max_X = 10;
  //     double h = 0.1;
  //     double res = 0;
  //     char check[10];
  //     for (X; X < max_X; X+=h) {
  //                    if (fabs(X) < 1e-7) {
  //                        res = calc_resutl(str, 0);
  //                        printf(" RES1 %lf\n", res);
  //                    } else {
  //                         res = calc_resutl(str, X);
  //                         printf(" RES %lf\n", res);
  //                    }
  //                    sprintf(check, "%lf", res);
  //                    if (strcmp(check, "nan") == 0) {
  //                     printf("NANAA\n");
  //                    }
  //                    if (isnan(res) || !isfinite(res)) {
  //                        while (isnan(res) || !isfinite(res) && X < max_X) {
  //                            X+=h;
  //                            printf("IF X %lf\n", X);
  //                            res = calc_resutl(str, X);
  //                        }
  //                        printf("BREAK\n");
  //                        break;
  //                    } else {
  //                     printf("ELSE X %lf\n", X);
  // }INT32_MAX
  // __LONG_MAX__
  // __LONG_LONG_MAX__
  //     }
}