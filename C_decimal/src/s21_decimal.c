#include "s21_decimal.h"

// void print_binary(s21_decimal inp) {
//   printf("%d", (get_sign(inp)));
//   printf(" | ");
//   for (int i = 126; i >= 121; i--) {
//     printf("%d", (get_bit(inp, i)));
//   }
//   printf(" | ");
//   for (int i = 120; i >= 112; i--) {
//     printf("%d", (get_bit(inp, i)));
//   }
//   printf(" | ");
//   for (int i = 111; i >= 96; i--) {
//     printf("%d", (get_bit(inp, i)));
//   }
//   printf(" | ");
//   for (int i = 95; i >= 64; i--) {
//     printf("%d", (get_bit(inp, i)));
//   }
//   printf(" ");
//   for (int i = 63; i >= 32; i--) {
//     printf("%d", (get_bit(inp, i)));
//   }
//   printf(" ");
//   for (int i = 31; i >= 0; i--) {
//     printf("%d", (get_bit(inp, i)));
//   }
//   printf("\n");
// }

int get_sign(s21_decimal src) { return (get_bit(src, 127)); }
void set_sign(s21_decimal *src, int sign) { set_bit(src, 127, sign); }

int get_bit(s21_decimal src, int i) {
  int mask = 1 << (i % 32);
  return !!(src.bits[i / 32] & mask);
}

void set_bit(s21_decimal *src, int i, int bit_value) {
  if (!bit_value) src->bits[i / 32] = ~src->bits[i / 32];
  int mask = 1 << (i % 32);
  src->bits[i / 32] = src->bits[i / 32] | mask;
  if (!bit_value) src->bits[i / 32] = ~src->bits[i / 32];
}

void set_scale(s21_decimal *src, int scale) {
  int start_bit = 112;
  do {
    set_bit(src, start_bit, scale % 2);
    start_bit++;
    scale /= 2;
  } while (start_bit != 118);
}

int get_scale(s21_decimal src) {
  int mask = 255;
  src.bits[3] >>= 16;
  int scale = src.bits[3] & mask;
  return scale;
}

int s21_is_less(s21_decimal first, s21_decimal second) {
  int return_flag = 0;
  if (normalization(&first, &second)) {
    return_flag = 1;
  } else {
    if (get_sign(first) == 1 && get_sign(second) == 0) {
      return_flag = 1;
    } else if (get_sign(first) == 0 && get_sign(second) == 1) {
      return_flag = 0;
    } else {
      for (int i = 95; i >= 0; i--) {
        if (get_bit(first, i) < get_bit(second, i)) {
          return_flag = 1;
          break;
        } else if (get_bit(first, i) > get_bit(second, i)) {
          break;
        }
      }
      if (get_sign(first) == 1 && get_sign(second) == 1) {
        return_flag = !return_flag;
      }
    }
  }
  return return_flag;
}

int s21_is_less_or_equal(s21_decimal first, s21_decimal second) {
  int return_flag = 0;
  if (normalization(&first, &second)) {
    return_flag = 1;
  } else {
    if (s21_is_equal(first, second)) {
      return_flag = 1;
    }
    if (s21_is_less(first, second)) {
      return_flag = 1;
    }
  }
  return return_flag;
}

int s21_is_greater(s21_decimal first, s21_decimal second) {
  int return_flag = 0;
  if (!normalization(&first, &second)) {
    if (get_sign(first) == 1 && get_sign(second) == 0) {
      return_flag = 0;
    } else if (get_sign(first) == 0 && get_sign(second) == 1) {
      return_flag = 1;
    } else {
      for (int i = 95; i >= 0; i--) {
        if (get_bit(first, i) > get_bit(second, i)) {
          return_flag = 1;
          break;
        } else if (get_bit(first, i) < get_bit(second, i)) {
          break;
        }
      }
      if (get_sign(first) == 1 && get_sign(second) == 1) {
        return_flag = !return_flag;
      }
    }
  }

  return return_flag;
}

int s21_is_greater_or_equal(s21_decimal first, s21_decimal second) {
  int return_flag = 0;
  if (!normalization(&first, &second)) {
    if (s21_is_equal(first, second)) {
      return_flag = 1;
    } else if (s21_is_greater(first, second)) {
      return_flag = 1;
    } else {
      return_flag = 0;
    }
  }

  return return_flag;
}

int s21_is_equal(s21_decimal first, s21_decimal second) {
  int return_flag = 0;
  if (!normalization(&first, &second)) {
    if (get_sign(first) == get_sign(second)) {
      return_flag = 1;
      for (int i = 0; i < 96; i++) {
        if (get_bit(first, i) != get_bit(second, i)) {
          return_flag = 0;
          break;
        }
      }
    }
  }
  return return_flag;
}

int s21_is_not_equal(s21_decimal first, s21_decimal second) {
  int return_flag = 0;
  if (!s21_is_equal(first, second)) {
    return_flag = 1;
  }
  return return_flag;
}

int is_not_equal_to_zero(s21_decimal dst) {
  int return_flag = 0;
  for (int i = 0; i < 96; i++) {
    if (get_bit(dst, i)) {
      return_flag = 1;
      break;
    }
  }
  return return_flag;
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int return_flag = 0;
  s21_decimal tmp = value_1;
  s21_decimal tmp1 = value_2;
  s21_decimal dec_one = {{1, 0, 0, 0}};
  s21_decimal dec_o = {{0, 0, 0, 0}};
  s21_decimal dec_ten = {{10, 0, 0, 0}};
  s21_decimal dec_f = {{5, 0, 0, 0}};
  int scale = get_scale(value_1);
  normalization(&value_1, &value_2);
  if (get_sign(value_1) && !get_sign(value_2)) {
    set_sign(&value_1, 0);
    s21_sub(value_2, value_1, result);
  } else if (get_sign(value_2) && !get_sign(value_1)) {
    set_sign(&value_2, 0);
    s21_sub(value_1, value_2, result);
  } else {
    if (normalization(&value_1, &value_2)) {
      return_flag = 1;
    } else {
      *result = add(value_1, value_2, &return_flag);
      if (return_flag &&
          ((s21_is_less(tmp1, dec_one) && s21_is_greater(tmp1, dec_o))
           // || (s21_is_greater(tmp1, dec_m_one) && s21_is_less(tmp1, dec_o))
           )) {
        set_scale(&tmp, 0);
        clean_dec(&tmp1);
        s21_mod(tmp, dec_ten, &tmp1);
        s21_div_10(tmp, dec_ten, &tmp);

        return_flag = 0;
        bank_round(&tmp1, &dec_f, &dec_one, &tmp, &return_flag);
        set_scale(&tmp, scale - 1);
        *result = tmp;
      }
      if (get_sign(value_1) && get_sign(value_2)) {
        set_sign(result, 1);
      }
    }
  }

  if (return_flag && get_sign(*result)) {
    return_flag = 2;
  }
  return return_flag;
}

void revers_bits(s21_decimal *dec) {
  dec->bits[0] = ~dec->bits[0];
  dec->bits[1] = ~dec->bits[1];
  dec->bits[2] = ~dec->bits[2];
}

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  clean_dec(result);
  int error = 0;
  if ((value_2.bits[0] == -1 && value_2.bits[1] == -1 &&
       value_2.bits[2] == -1 && value_1.bits[0] == -1 &&
       value_1.bits[1] == -1 && value_1.bits[2] == -1)) {
    clean_dec(result);
    result->bits[0] = 1;
    if (get_sign(value_1) != get_sign(value_2)) {
      set_sign(result, 1);
    }
  } else {
    if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
      error = 3;

    } else {
      error = normalization(&value_1, &value_2);
      if (get_sign(value_1) != get_sign(value_2)) {
        set_sign(result, 1);
      }
      if (error != 3) {
        set_scale(&value_1, 0);
        set_scale(&value_2, 0);

        int i = 0;
        if (get_sign(value_1) != get_sign(value_2)) {
          i = 1;
        }
        set_sign(&value_1, 0);
        set_sign(&value_2, 0);
        s21_decimal value_orig = value_2;
        s21_decimal tmp;
        clean_dec(&tmp);
        int scale_count = 0;
        while (is_not_equal_to_zero(value_1) && scale_count <= 28) {
          while ((s21_is_less(value_2, value_1))) {
            if (shift_right(&value_2, 1)) {
              break;
            }
          }
          while (s21_is_greater_or_equal(value_2, value_orig) ||
                 s21_is_greater_or_equal(value_1, value_orig)) {
            shift_right_NE(&tmp, 1);

            if (s21_is_greater(value_2, value_1)) {
              set_bit(&tmp, 0, 0);
            } else {
              s21_sub(value_1, value_2, &value_1);
              set_bit(&tmp, 0, 1);
            }
            shift_left_NE(&value_2, 1);
          }

          if (error > 0) {
            break;
          }
          error = s21_add(tmp, *result, result);

          if (is_not_equal_to_zero(value_1)) {
            value_2 = value_orig;
            if (scale_count != 28) {
              upscale_for_div(&value_1, 1);
              if (upscale_for_div(result, 1)) {
                break;
              } else {
                scale_count++;
              }
            } else {
              break;
            }
            clean_dec(&tmp);
          }
        }
        s21_decimal res_tmp = *result;
        if (is_not_equal_to_zero(value_1) && upscale_for_div(&res_tmp, 1)) {
          s21_decimal dec_one = {{1, 0, 0, 0}};
          s21_decimal dec_five = {{5, 0, 0, 0}};
          s21_decimal dec_ten = {{10, 0, 0, 0}};

          s21_mod(*result, dec_ten, &tmp);
          bank_round(result, &dec_five, &dec_one, result, &error);
        }

        set_sign(result, i);
        set_scale(result, scale_count);
      } else {
        error = 1;
        if (s21_is_greater(value_2, value_1)) {
          error = 2;
        }
      }
    }
  }
  return error;
}

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign_1 = get_sign(value_1);

  set_sign(&value_1, 0);
  set_sign(&value_2, 0);

  int return_flag = 0;
  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    return_flag = 3;
  } else {
    return_flag = normalization(&value_1, &value_2);
    if (return_flag > 0) {
      clean_dec(result);
      return_flag = 0;
    } else if (return_flag == 0) {
      s21_decimal aboba;
      *result = div_for_trunc_and_mod(value_1, value_2, &aboba);
    }
  }
  set_sign(result, sign_1);

  return return_flag;
}

s21_decimal div_for_trunc_and_mod(s21_decimal value_1, s21_decimal value_2,
                                  s21_decimal *div_result) {
  clean_dec(div_result);
  s21_decimal val_orig = value_2;
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  while ((s21_is_less(value_2, value_1))) {
    if (shift_right(&value_2, 1)) {
      break;
    }
  }

  while (s21_is_greater_or_equal(value_2, val_orig) ||
         s21_is_greater_or_equal(value_1, val_orig)) {
    shift_right_NE(div_result, 1);

    if (s21_is_greater(value_2, value_1)) {
      set_bit(div_result, 0, 0);
    } else {
      s21_sub(value_1, value_2, &value_1);
      set_bit(div_result, 0, 1);
    }
    shift_left_NE(&value_2, 1);
  }

  return value_1;
}

void clean_dec(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int sign = 0;
  int return_flag = 0;
  int b = 0;
  normalization(&value_1, &value_2);
  sign = logig_for_sub(&value_1, &value_2, &b);
  if (sign == 2) {  //  если значения равны будет 0
    clean_dec(result);
    set_sign(result, 0);
    return 0;
  } else {  // после преобразавания складываем
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    *result = add(value_1, value_2, &return_flag);
  }
  if (sign) {  // учитываем знак
    set_sign(result, 1);
  }
  if (b == 1) {
    return_flag = 0;
  }
  return return_flag;
}

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  int return_flag = 0;
  if (!(src == S21_INF || src == S21_NaN || dst == NULL ||
        src == S21_NEGATIVE_INF)) {
    clean_dec(dst);
    dst->bits[3] = 0;
    if (src < 0) {
      set_sign(dst, 1);
      src *= -1;
    }
    dst->bits[0] = src;
  } else {
    return_flag = 1;
  }
  return return_flag;
}

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int return_flag = 0;
  int sign = get_sign(value);
  set_sign(&value, 0);
  s21_decimal dec0_0 = {{0, 0, 0, 0}};
  s21_decimal dec = {{10, 0, 0, 0}};
  int scale_count = get_scale(value);
  set_scale(&value, 0);
  for (; scale_count; scale_count--) {
    div_for_trunc_and_mod(value, dec, &value);
  }
  *result = value;
  if (sign && !s21_is_equal(*result, dec0_0)) {
    set_sign(result, 1);
  }
  return return_flag;
}

int s21_floor(s21_decimal value, s21_decimal *result) {
  int return_flag = 0;
  s21_decimal dec = {{1, 0, 0, 0}};
  set_sign(&dec, 1);

  s21_truncate(value, result);

  if (get_sign(value)) {
    s21_add(*result, dec, result);
    set_sign(result, 1);
  }
  return return_flag;
}

int s21_round(s21_decimal value, s21_decimal *result) {
  int return_flag = 0;
  int sign = get_sign(value);
  set_sign(&value, 0);
  s21_decimal dec05 = {{5, 0, 0, 0}};
  s21_decimal dec0_0 = {{0, 0, 0, 0}};
  set_scale(&dec05, 1);
  s21_decimal trunc_val = value;
  s21_truncate(trunc_val, &trunc_val);
  s21_sub(value, trunc_val, &value);
  if (s21_is_greater_or_equal(value, dec05)) {
    s21_decimal dec1 = {{1, 0, 0, 0}};
    s21_add(trunc_val, dec1, &trunc_val);
  }
  *result = trunc_val;
  if (sign && !s21_is_equal(*result, dec0_0)) {
    set_sign(result, 1);
  }
  return return_flag;
}

int s21_negate(s21_decimal value, s21_decimal *result) {
  int return_flag = 0;
  set_sign(&value, !get_sign(value));
  *result = value;
  return return_flag;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int return_flag = 0;
  s21_truncate(src, &src);
  if (src.bits[0] <= MAX_INT_SIZE && !src.bits[1] && !src.bits[2]) {
    *dst = src.bits[0];
    if (get_sign(src)) {
      *dst *= -1;
    }
  } else {
    return_flag = 1;
  }

  return return_flag;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int return_flag = 0;
  int scale = get_scale(src);
  *dst = 0;
  for (int i = 0; i < 96; i++) {
    if (get_bit(src, i)) {
      *dst += pow(2, i);
    }
  }

  double tmp = *dst;
  for (; scale; scale--, tmp /= 10) {
  }
  *dst = tmp;
  if (get_sign(src)) {
    *dst *= -1;
  }

  return return_flag;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  s21_decimal buff1 = {{0, 0, 0, 0}};
  int return_flag = 0;
  int min_fl = 0;
  if (src < 0) {
    min_fl = 1;
    src *= -1;
  }
  if (!(src == S21_INF || src == S21_NaN || dst == NULL ||
        src > MAX_DECIMAL_SIZE || src < MIN_DECIMAL_SIZE ||
        src == S21_NEGATIVE_INF)) {
    int k = (int)src;
    int z = k;
    int j = 0;
    while (z != 0) {
      z /= 10;
      j++;
    }
    int in = 0;
    while (j > 7) {
      if (j == 8) {
        if (k % 10 >= 5) {
          in = 1;
        }
      }
      k /= 10;
      j--;
    }
    k += in;
    s21_from_int_to_decimal(k, dst);
    if (in == 0) {
      src -= k;
      src *= pow(10, 7 - j);
      z = (int)src;
      src -= (float)z;
      if (src >= 0.5) {
        z++;
      }
      for (int i = 0; i < 7 - j; i++) {
        buff1 = *dst;
        shift_right(dst, 3);
        shift_right(&buff1, 1);
        s21_add(*dst, buff1, dst);
      }
      clean_dec(&buff1);
      s21_from_int_to_decimal(z, &buff1);
      s21_add(*dst, buff1, dst);
    }
    set_scale(dst, 7 - j);
  } else {
    return_flag = 1;
  }
  set_sign(dst, min_fl);
  return return_flag;
}

int down_scale(s21_decimal value, int scale_diff, s21_decimal *result) {
  int error = 0;
  int scale = get_scale(value);

  s21_decimal dec_ten = {{10, 0, 0, 0}};
  s21_decimal dec_five = {{5, 0, 0, 0}};
  s21_decimal dec_one = {{1, 0, 0, 0}};
  s21_decimal dec_mod = {{0, 0, 0, 0}};
  scale_diff = abs(scale_diff);
  while (scale_diff > 0) {
    set_scale(&value, 0);
    s21_mod(value, dec_ten, &dec_mod);
    s21_div(value, dec_ten, result);
    s21_truncate(*result, result);
    bank_round(&dec_mod, &dec_five, &dec_one, result, &error);

    clean_dec(&dec_mod);
    scale_diff--;
    scale--;
    set_scale(result, scale);
  }
  set_scale(result, scale);

  return error;
}

int normalization(s21_decimal *value_1, s21_decimal *value_2) {
  int return_flag = 0;

  if (value_1->bits[0] + value_1->bits[1] + value_1->bits[2] == 0) {
    set_scale(value_1, 0);
    set_sign(value_1, 0);
  }
  if (value_2->bits[0] + value_2->bits[1] + value_2->bits[2] == 0) {
    set_scale(value_2, 0);
    set_sign(value_2, 0);
  }

  int scale_1 = get_scale(*value_1);
  int scale_2 = get_scale(*value_2);

  if (scale_1 > 28) {
    down_scale(*value_1, scale_1 - 28, value_1);
  }
  if (scale_2 > 28) {
    down_scale(*value_2, scale_2 - 28, value_2);
  }

  int scale_diff = get_scale(*value_1) - get_scale(*value_2);

  if (scale_diff != 0) {
    if (scale_diff < 0) {
      if (upscale(value_1, abs(scale_diff))) {
        scale_diff = get_scale(*value_1) - get_scale(*value_2);
        down_scale(*value_2, abs(scale_diff), value_2);
        if ((value_2->bits[0] + value_2->bits[1] + value_2->bits[2]) == 0) {
          return_flag = 3;
        }
      }
      scale_diff = get_scale(*value_1) - get_scale(*value_2);
    } else {
      if (upscale(value_2, abs(scale_diff))) {
        scale_diff = get_scale(*value_1) - get_scale(*value_2);
        down_scale(*value_1, abs(scale_diff), value_1);
        if ((value_1->bits[0] + value_1->bits[1] + value_1->bits[2]) == 0) {
          return_flag = 3;
        }
      }
      scale_diff = get_scale(*value_1) - get_scale(*value_2);
    }
  }

  return return_flag;
}

int upscale(s21_decimal *dst, int number) {
  int return_flag = 0;
  s21_decimal value_last = *dst;

  for (int scale = get_scale(*dst); number; number--) {
    if (shift_right(dst, 1)) {
      *dst = value_last;
      set_scale(dst, scale);
      return_flag = 1;

      break;
    }
    s21_decimal tmp_1 = *dst;
    if (shift_right(dst, 2)) {
      *dst = value_last;
      set_scale(dst, scale);
      return_flag = 1;

      break;
    }
    *dst = add(*dst, tmp_1, &return_flag);
    if (return_flag) {
      *dst = value_last;
      set_scale(dst, scale);

      return_flag = 1;
      break;
    }
    if (scale > 28) {
      *dst = value_last;
      set_scale(dst, scale);
      return_flag = 1;

      break;
    }
    value_last = *dst;
    scale++;
    set_scale(dst, scale);
  }

  return return_flag;
}

int upscale_for_div(s21_decimal *dst, int number) {
  int return_flag = 0;
  s21_decimal tmp_dst = *dst;
  for (; number; number--) {
    if (shift_right(&tmp_dst, 1)) {
      return_flag = 1;
      break;
    }
    s21_decimal tmp_1 = tmp_dst;
    if (shift_right(&tmp_dst, 2)) {
      return_flag = 1;
      break;
    }

    tmp_dst = add(tmp_dst, tmp_1, &return_flag);
    if (return_flag) {
      break;
    }
    int scale = get_scale(tmp_dst);
    if (scale > 28) {
      return_flag = 1;
      break;
    }
  }

  if (!return_flag) {
    *dst = tmp_dst;
  }
  return return_flag;
}

s21_decimal add(s21_decimal dst, s21_decimal src, int *return_flag) {
  int add_status = 0;
  s21_decimal res = dst;
  for (int i = 0; i < 96; i++) {
    int dst_bit = get_bit(res, i);
    int src_bit = get_bit(src, i);
    if (dst_bit && src_bit) {
      if (i == 95) {
        *return_flag = 1;
      }
      if (add_status) {
        set_bit(&res, i, 1);
      } else {
        set_bit(&res, i, 0);
      }
      add_status = 1;
    } else if (dst_bit ^ src_bit) {
      if (i == 95 && add_status) {
        *return_flag = 1;
      }
      if (add_status) {
        set_bit(&res, i, 0);
        add_status = 1;
      } else {
        set_bit(&res, i, 1);
        add_status = 0;
      }
    } else if (!(dst_bit | src_bit)) {
      if (add_status) {
        set_bit(&res, i, 1);
        add_status = 0;
      }
    }
  }
  return res;
}

int shift_right(s21_decimal *dst, int number) {
  int return_flag = 0;
  for (; number; number--) {
    if (!get_bit(*dst, 95)) {
      dst->bits[2] <<= 1;
      set_bit(dst, 64, get_bit(*dst, 63));
      dst->bits[1] <<= 1;
      set_bit(dst, 32, get_bit(*dst, 31));
      dst->bits[0] <<= 1;
    } else {
      return_flag = 1;
      break;
    }
  }
  return return_flag;
}

int shift_left_NE(s21_decimal *dst, int number) {
  int return_flag = 0;
  for (; number; number--) {
    dst->bits[0] >>= 1;
    set_bit(dst, 31, get_bit(*dst, 32));
    dst->bits[1] >>= 1;
    set_bit(dst, 63, get_bit(*dst, 64));
    dst->bits[2] >>= 1;
    set_bit(dst, 95, 0);
  }
  return return_flag;
}

int shift_right_NE(s21_decimal *dst, int number) {
  int return_flag = 0;
  for (; number; number--) {
    dst->bits[2] <<= 1;
    set_bit(dst, 64, get_bit(*dst, 63));
    dst->bits[1] <<= 1;
    set_bit(dst, 32, get_bit(*dst, 31));
    dst->bits[0] <<= 1;
  }
  return return_flag;
}

void make_dec(s21_decimal *value, char *str) {
  int i = 0;
  int k = strlen(str);
  for (; i < 96; i++) {
    if (k == i) {
      break;
    }
    set_bit(value, i, str[k - 1 - i] - '0');
  }
  for (; i < 96; i++) {
    set_bit(value, i, 0);
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_decimal adder = value_2;
  if (s21_is_greater_or_equal(value_2, value_1)) {
    adder = value_1;
  }
  int error = 0;
  int bit_1 = 0;
  int first_scale = get_scale(value_1);
  int second_scale = get_scale(value_2);
  int sign_1 = get_sign(value_1);
  int sign_2 = get_sign(value_2);

  if (sign_1 != sign_2)
    set_sign(result, 1);
  else
    set_sign(result, 0);

  for (int i = 0; i < 96; i++) {
    if (s21_is_greater_or_equal(value_2, value_1)) {
      bit_1 = get_bit(value_2, i);
    } else {
      bit_1 = get_bit(value_1, i);
    }
    if (bit_1) {
      if (!get_bit(*result, 95)) {
        s21_logic(*result, adder, result);
      } else {
        error = 1;
        break;
      }
    }
    shift_right(&adder, 1);
  }
  set_scale(result, (first_scale + second_scale));
  if (error == 1 && get_sign(*result)) {
    error = 2;
  }

  s21_decimal dec_zero = {{0, 0, 0, 0}};

  if (get_scale(*result) > 28) {
    int res_zero = 0;
    int sign_scale_bit = result->bits[3];

    result->bits[3] = 0;

    if (s21_is_equal(*result, dec_zero)) {
      res_zero = 1;
    }
    result->bits[3] = sign_scale_bit;

    s21_decimal dec_ten = {{10, 0, 0, 0}};
    s21_decimal dec_five = {{5, 0, 0, 0}};
    s21_decimal dec_one = {{1, 0, 0, 0}};
    set_scale(result, get_scale(*result) - 28 - 1);
    s21_truncate(*result, result);

    s21_decimal tmp = {{0, 0, 0, 0}};
    s21_mod(*result, dec_ten, &tmp);

    set_scale(result, 1);
    s21_truncate(*result, result);
    bank_round(&tmp, &dec_five, &dec_one, result, &error);
    set_scale(result, 28);

    if (!res_zero && s21_is_equal(*result, dec_zero)) {
      error = 2;
    }
  }

  set_sign(&dec_zero, get_sign(*result));
  set_scale(&dec_zero, get_scale(*result));
  if (s21_is_equal(*result, dec_zero)) {
    set_sign(result, 0);
  }

  return error;
}

int logig_for_sub(s21_decimal *first, s21_decimal *second, int *b) {
  int sign = 0;
  int r = 0;
  int sign_1 = get_sign(*first);
  int sign_2 = get_sign(*second);
  s21_decimal gg = {{1, 0, 0, 0}};
  s21_decimal buffer = {{0, 0, 0, 0}};
  if (s21_is_greater(*first, *second)) {  //  first > second
    if (!sign_1 && !sign_2) {             //  + +
      revers_bits(second);
      set_scale(&gg, sign_2);
      *second = add(*second, gg, &r);
      sign = 0;
      *b = 1;
    } else if (sign_1 && !sign_2) {  //  - +
      sign = 1;
    } else if (!sign_1 && sign_2) {  //  + -
      sign = 0;
    } else if (sign_1 && sign_2) {  //  - -
      //  -7 - -5 = -2   =   7 - 5
      revers_bits(first);
      set_scale(&gg, sign_1);
      *first = add(*first, gg, &r);
      sign = 0;
      *b = 1;
    }
  } else if (s21_is_equal(*first, *second)) {  //  first = second
    sign = 2;
  } else {                     //  first < second
    if (!sign_1 && !sign_2) {  //  + +
      buffer = *second;
      *second = *first;
      *first = buffer;
      revers_bits(second);
      set_scale(&gg, sign_2);
      *second = add(*second, gg, &r);
      sign = 1;
      *b = 1;
    } else if (sign_1 && !sign_2) {  //  - +
      sign = 1;
    } else if (!sign_1 && sign_2) {  //  +
      sign = 0;
    } else if (sign_1 && sign_2) {  //  - -
                                    //  -5 - -7 = 2   =   7 - 5
      revers_bits(second);
      set_scale(&gg, sign_2);
      *second = add(*second, gg, &r);
      sign = 1;
      *b = 1;
    }
  }
  return sign;
}

void s21_logic(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int prev = 0;
  int next = 0;
  int res = 0;
  for (int i = 0; i < 96; i++) {
    int first_num_bit = get_bit(value_1, i);
    int second_num_bit = get_bit(value_2, i);
    if (first_num_bit == 0) {
      if (second_num_bit == 0 && prev == 0) {
        res = 0;
        next = 0;
      } else if (second_num_bit == 0 || prev == 0) {
        res = 1;
        next = 0;
      } else {
        res = 0;
        next = 1;
      }
    } else {
      if (second_num_bit == 0 && prev == 0) {
        res = 1;
        next = 0;
      } else if (second_num_bit == 0 || prev == 0) {
        res = 0;
        next = 1;
      } else {
        res = 1;
        next = 1;
      }
    }
    prev = next;
    if (res) {
      set_bit(result, i, 1);
    } else {
      set_bit(result, i, 0);
    }
  }
}

int s21_div_10(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int error = 0;

  if (value_2.bits[0] == 0 && value_2.bits[1] == 0 && value_2.bits[2] == 0) {
    error = 3;
  } else {
    clean_dec(result);
    normalization(&value_1, &value_2);
    int scale_src = get_scale(value_1);
    set_scale(&value_1, 0);
    set_scale(&value_2, 0);

    if (get_sign(value_1) != get_sign(value_2)) {
      set_sign(result, 1);
    } else {
      set_sign(result, 0);
    }
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);

    s21_decimal value_orig = value_2;
    s21_decimal tmp;
    clean_dec(&tmp);
    int scale_count = get_scale(value_1);

    while (is_not_equal_to_zero(value_1) && scale_count < 28 - scale_src) {
      while (s21_is_less(value_2, value_1) && !shift_right(&value_2, 1)) {
      }

      while (s21_is_greater_or_equal(value_2, value_orig) ||
             s21_is_greater_or_equal(value_1, value_orig)) {
        shift_right_NE(&tmp, 1);

        if (s21_is_greater(value_2, value_1)) {
          set_bit(&tmp, 0, 0);
        } else {
          s21_sub(value_1, value_2, &value_1);
          set_bit(&tmp, 0, 1);
        }
        shift_left_NE(&value_2, 1);
      }
      s21_add(tmp, *result, result);

      if (is_not_equal_to_zero(value_1)) {
        break;
      }
    }
    set_scale(result, scale_count + scale_src);
  }

  return error;
}

void bank_round(s21_decimal *dec_mod, s21_decimal *dec_five,
                s21_decimal *dec_one, s21_decimal *result, int *error) {
  if (s21_is_greater(*dec_mod, *dec_five)) {
    *result = add(*result, *dec_one, error);
  }

  if (s21_is_equal(*dec_mod, *dec_five)) {
    if (get_bit(*result, 0)) {
      *result = add(*result, *dec_one, error);
    }
  }
}
