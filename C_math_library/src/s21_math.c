#include "s21_math.h"

int s21_abs(int a) {
  if (a < 0) {
    a *= -1;
  }
  return a;
}

long double s21_fabs(double b) {
  if (b < 0) {
    b *= -1;
  }
  return b;
}

long double s21_ceil(double c) {
  if (c == S21_INF) {
    c = S21_INF;
  } else {
    if (c > 0) {
      if ((long long int)c != c) {
        long double c1;
        c1 = c - (long long int)c;
        c -= c1;
        c += 1;
      }
    }
    if (c < 0) {
      if ((long long int)c != c) {
        long double c1;
        c1 = c - (long long int)c;
        c = c - c1;
      }
    }
  }
  return c;
}

long double s21_floor(double c) {
  if (c == S21_INF) {
    c = S21_INF;
  } else if (c == -S21_INF) {
    c = -S21_INF;
  } else {
    if (c > 0) {
      if ((long long int)c != c) {
        long double c1;
        c1 = c - (long long int)c;
        c -= c1;
      }
    }
    if (c < 0) {
      if ((long long int)c != c) {
        long double c1;
        c1 = c - (long long int)c;
        c = c - c1;
        c += -1;
      }
    }
  }
  return c;
}

long double s21_sqrt(double x) {
  long double answer = 0.0;
  if (x < 0) {
    answer = S21_NaN;
  } else if (x == S21_INF) {
    answer = S21_INF;
  } else if (x != 0) {
    if (s21_fabs(x) < 0.00000001) {
      answer = 0 / (x - x);
    } else {
      if (x > 1 - 0.00000001) {
        long double l = 0.0, mult = 2.0;

        while (mult * mult <= x) {
          mult *= 2.0;
        }

        while (mult - l > 0.00000001) {
          long double m = (mult + l) / 2;

          if (m * m > x) {
            mult = m;
          } else {
            l = m;
          }

          answer = l;
        }
      } else {
        long double l = x, r = 1.0;

        while (r - l > 0.00000001) {
          long double m = (r + l) / 2;

          if (m * m > x) {
            r = m;
          } else {
            l = m;
          }

          answer = r;
        }
      }
    }
  }

  return answer;
}

long double s21_fmod(double x, double y) {
  long double n = 0;
  if (y == S21_INF) {
    n = x;
  } else if (x == S21_INF) {
    n = S21_NaN;
  } else {
    int minus = 0;
    if (x < 0.00000001) {
      minus = 1;
    }
    x = (double)s21_fabs(x);
    y = (double)s21_fabs(y);
    n = s21_floor(x / y);
    n = x - n * y;
    if (minus == 1) {
      n *= -1;
    }
  }
  return n;
}

long double s21_exp(double x) {
  long double n = 0;
  long double an = 1.0, S = 0.0;
  if (x == -S21_INF) {
    S = 0;
  } else if (x == S21_INF) {
    S = S21_INF;
  } else {
    while (s21_fabs(an) > EPS) {
      S += an;
      n++;
      an *= x / n;
    }
  }
  return S;
}

long double s21_sin(double radians) {
  long double res;
  long double sinus = 0;
  if (radians == S21_INF || radians == -S21_INF) {
    res = S21_NaN;
  } else {
    radians = s21_fmod(radians, 2 * S21_PI);
    long double rslt = radians;
    for (int i = 1; s21_fabs(rslt) > 0.0000001; i++) {
      sinus += rslt;
      rslt *= (-1) * (radians * radians) / ((2 * i + 1) * (2 * i));
    }
    res = sinus;
  }
  return res;
}

long double s21_cos(double radians) {
  long double cos = 0;
  long double g = 1;

  if (radians == S21_INF || radians == -S21_INF) {
    cos = S21_NaN;
  } else {
    long double x = s21_fmod(radians, 2 * S21_PI);
    for (int i = 1; s21_fabs(g) > 0.0000000000001; i++) {
      cos += g;
      g *= (-1) * (x * x) / ((2 * i) * (2 * i - 1));
    }
  }
  return cos;
}

long double s21_tan(double radians) {
  long double tang;
  if (radians == S21_INF || radians == -S21_INF) {
    tang = S21_NaN;
  } else {
    tang = s21_sin(radians) / s21_cos(radians);
  }
  return tang;
}

long double s21_asin(double radians) {
  int flag = 0;
  if (radians < 0) {
    radians *= -1;
    flag = 1;
  }
  long double arsin = radians;
  if (radians > 1) {
    arsin = S21_NaN;
  } else {
    if (radians != -1 && radians != 1) {
      radians /= s21_sqrt((double)1 - radians * radians);
      arsin = s21_atan(radians);
    } else {
      if (radians == 1 || radians == -1) {
        arsin = 1.5707963;
      }
    }
    if (flag == 1) {
      arsin *= -1;
    }
  }
  return arsin;
}

long double s21_acos(double radians) {
  long double arcos;
  if (s21_fabs(radians) < 1) {
    arcos = 1.57079632679 - s21_asin(radians);
  } else if (radians == 1) {
    arcos = 0;
  } else {
    arcos = S21_NaN;
  }
  return arcos;
}

long double s21_atan(double radians) {
  long double res = 0;
  int flag = 0;
  int sign = 1;
  if (radians == S21_INF) {
    res = S21_PI / 2;
  } else if (radians == -S21_INF) {
    res = -S21_PI / 2;
  } else {
    if (radians < -0.0000001) {
      radians = -radians;
      sign = -1;
    }

    if (s21_fabs(radians) > 1.F) {
      radians = 1.0 / radians;
      flag = 1;
    }

    long double vr = radians;
    long double atan = 0;

    for (int i = 1; s21_fabs(vr) > 0.00000001; i++) {
      atan += vr;

      vr *= -(radians * radians) * (2 * i - 1) / (2 * i + 1);
    }

    if (flag == 1) {
      res = sign * (1.57079632679489661923 - atan);
    } else {
      res = sign * atan;
    }
  }

  return res;
}

long double s21_log(double x) {
  long double ans = 0.0;
  if (x == S21_INF) {
    ans = S21_INF;
  } else {
    if (x < -EPS) {
      ans = 0 / (x - x);
    } else if (x < EPS) {
      ans = -1 / (x - x);
    } else if (x < 0.1 || (x > 1.9 && x < 2 - EPS)) {
      ans = 2 * s21_log(s21_sqrt(x));
    } else if (x > EPS && x < 2 - EPS) {
      long double mul = x - 1.0;
      long double cntr = 1.0;

      long double cur = mul;

      while (cur > EPS || cur < -EPS) {
        ans += cur / cntr;

        cntr += 1.0;
        cur = (-cur) * mul;
      }

    } else {
      ans = s21_log((2 * x) / (x + 1)) - s21_log(2 / (x + 1));
    }
  }

  return ans;
}

long double s21_pow(double x, double y) {
  long double num = 0;
  if (x < 0) {
    if ((long int)y == y) {
      if (y > 0) {
        num = x;
        for (long int i = 0; i < (long int)y - 1; i++) {
          num *= x;
        }
      } else if (y == 0) {
        num = 1;
      } else {
        num = 1 / x;
        for (long int i = 0; i < -(long int)y - 1; i++) {
          num /= x;
        }
      }
    } else {
      if (y == S21_INF || y == -S21_INF) {
        if (s21_fabs(x) < 1) {
          if (y == -S21_INF) {
            num = S21_INF;
          } else {
            num = 0;
          }
        } else if ((s21_fabs(x) == 1)) {
          num = 1;
        } else {
          if (y == -S21_INF) {
            num = 0;
          } else {
            num = S21_INF;
          }
        }
      } else {
        num = S21_NaN;
      }
    }
  } else if (x == 0) {
    if (y >= 0) {
      num = y == 0 ? 1 : 0;
    } else {
      num = S21_INF;
    }
  } else {
    if (y == S21_INF || y == -S21_INF) {
      if (x < 1) {
        if (y == S21_INF) {
          num = 0;
        } else {
          num = S21_INF;
        }
      } else if (x == 1) {
        if (y == S21_INF || y == -S21_INF) {
          num = 1;
        }
      } else {
        if (y == S21_INF) {
          num = S21_INF;
        } else {
          num = 0;
        }
      }
    } else {
      num = s21_exp((y * s21_log(x)));
    }
  }
  return num;
}
