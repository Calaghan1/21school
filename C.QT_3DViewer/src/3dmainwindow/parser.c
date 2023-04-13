// created by pizpoti
#include "parcer.h"

int parser(char *file, main_struct *tmp) {
  FILE *f = NULL;
  int flag = 0;
  tmp->v = malloc(sizeof(vertex));
  tmp->v->vertex_x[0] = tmp->v->vertex_y[0] = tmp->v->vertex_z[0] = 10000000;
  tmp->v->vertex_x[1] = tmp->v->vertex_y[1] = tmp->v->vertex_z[1] = -10000000;
  if ((f = fopen(file, "r")) != NULL) {
    tmp->v->vertex_matrix = (double **)malloc(1 * sizeof(double *));
    tmp->v->vertex_matrix[0] = (double *)malloc(3 * sizeof(double));
    tmp->p = (poligon **)malloc(1 * sizeof(poligon *));
    tmp->p[0] = (poligon *)malloc(sizeof(poligon));
    tmp->p[0]->poligon_sum = 0;
    if (!(file_parser(f, tmp))) {
      fclose(f);
      centr(tmp);
    }
  } else {
    flag = 1;
    free(tmp->v);
    tmp->v = NULL;
    // printf("файл не открылся\n");
  }
  return flag;
}

int file_parser(FILE *file, main_struct *tmp) {
  int res = 1, flag = 0;
  char str[130] = {0};
  tmp->v->vertex_mount = 0;
  fgets(str, 126, file);
  while (!feof(file)) {
    res = 0;
    flag = check_str(str);
    if (flag == 1) {
      tmp->v->vertex_mount++;
      if (tmp->v->vertex_mount > 1) {
        s21_realloc_matrix(tmp->v->vertex_mount, 3, tmp);
      }
      record_on_vertex(str, tmp);
    } else if (flag == 2) {
      tmp->struct_count++;
      if (tmp->struct_count > 1) {
        s21_realloc_struct(tmp);
      }
      record_on_poligon(str, tmp);
    }
    fgets(str, 126, file);
  }
  return res;
}

int check_str(char *str) {
  int res = 1, i = 0;
  if ((str[i] == 'v' || str[i] == 'f') && str[1] == ' ') {
    i++;
    for (; str[i] != '\0' && res; i++) {
      if ((str[i] > 8 && str[i] < 11) || str[i] == 13 || str[i] == 32 ||
          (str[i] > 44 && str[i] < 58)) {
      } else {
        res = 0;
      }
    }
    if (res) {
      if (str[0] == 'f') {
        res = 2;
      }
    }
  } else {
    res = 0;
  }
  return res;
}

void record_on_vertex(char *str, main_struct *tmp) {
  char *str1 = str;
  double x = 0;
  int count = 0, step = 0;
  while (str1) {
    step++;
    int i = 0;
    for (; (str1[i] < 48 || str1[i] > 58) && str1[i] != 45 && str1[i] != '\0' &&
           str1[i] != '\n';
         i++) {
    }
    if (str1[i] == '\0' || str1[i] == '\n' || str1[i] == 13) {
      str1 = NULL;
    }
    if (str1) {
      str = str1 + i;
      str1 = convertation(str, &x);
      tmp->v->vertex_matrix[tmp->v->vertex_mount - 1][count] = x;
      count++;
    }
    if (step == 1) {
      if (x < tmp->v->vertex_x[0]) {
        tmp->v->vertex_x[0] = x;
      }
      if (x > tmp->v->vertex_x[1]) {
        tmp->v->vertex_x[1] = x;
      }
    } else if (step == 2) {
      if (x < tmp->v->vertex_y[0]) {
        tmp->v->vertex_y[0] = x;
      }
      if (x > tmp->v->vertex_y[1]) {
        tmp->v->vertex_y[1] = x;
      }
    } else if (step == 3) {
      if (x < tmp->v->vertex_z[0]) {
        tmp->v->vertex_z[0] = x;
      }
      if (x > tmp->v->vertex_z[1]) {
        tmp->v->vertex_z[1] = x;
      }
    }
  }
}

void record_on_poligon(char *str, main_struct *tmp) {
  char *str1 = str;
  double x = 0;
  int count = 0;
  tmp->p[tmp->struct_count - 1]->poligon_arr = (int *)malloc(sizeof(int));
  while (str1) {
    count++;
    int i = 0;
    for (; (str1[i] < 48 || str1[i] > 58) && str1[i] != 45 && str1[i] != '\0' &&
           str1[i] != '\n';
         i++) {
    }
    if (str1[i] == '\0' || str1[i] == '\n' || str1[i] == 13) {
      str1 = NULL;
    }
    if (str1) {
      tmp->p[tmp->struct_count - 1]->poligon_sum++;
      if (tmp->p[tmp->struct_count - 1]->poligon_sum > 1) {
        s21_realloc_poligon_arr(tmp);
      }
      str = str1 + i;
      str1 = convertation(str, &x);
      tmp->p[tmp->struct_count - 1]
          ->poligon_arr[tmp->p[tmp->struct_count - 1]->poligon_sum - 1] =
          fabs(x) - 1;
      for (; str1[i] != ' ' && str1[i] != '\0' && str1[i] != '\n'; i++) {
      }
      str = str1 + i;
      str1 = str;
    }
  }
}

char *convertation(char *str, double *res) {
  char *tmp = NULL;
  *res = 0;
  int count = 0, flag = 0, i = 0, znak = 0;
  if (str[i] == '-') {
    znak = 1;
    i++;
  }
  for (; (str[i] < 58 && str[i] > 47) || str[i] == '.'; i++) {
    if (str[i] == '.') {
      flag = 1;
    } else {
      *res = (*res * 10) + (int)(str[i] - '0');
      if (flag == 1) {
        count++;
      }
    }
  }
  if (str[i] != '\0') {
    tmp = str + i;
  }
  while (count > 0) {
    *res = *res * 0.1;
    count--;
  }
  if (znak == 1) {
    *res *= -1;
  }
  return tmp;
}

void centr(main_struct *tmp) {
  double x =
      tmp->v->vertex_x[0] + (tmp->v->vertex_x[1] - tmp->v->vertex_x[0]) / 2;
  double y =
      tmp->v->vertex_y[0] + (tmp->v->vertex_y[1] - tmp->v->vertex_y[0]) / 2;
  double z =
      tmp->v->vertex_z[0] + (tmp->v->vertex_z[1] - tmp->v->vertex_z[0]) / 2;
  for (int i = 0; i < tmp->v->vertex_mount; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0) {
        tmp->v->vertex_matrix[i][j] -= x;
      } else if (j == 1) {
        tmp->v->vertex_matrix[i][j] -= y;
      } else if (j == 2) {
        tmp->v->vertex_matrix[i][j] -= z;
      }
    }
  }
  double max_x = tmp->v->vertex_x[1] - tmp->v->vertex_x[0];
  double max_y = tmp->v->vertex_y[1] - tmp->v->vertex_y[0];
  double max_z = tmp->v->vertex_z[1] - tmp->v->vertex_z[0];
  double mul = 0;
  if (max_x >= max_y && max_x >= max_z) {
    mul = max_x;
  } else if (max_y >= max_x && max_y >= max_z) {
    mul = max_y;
  } else if (max_z >= max_y && max_z >= max_x) {
    mul = max_z;
  }
  if (mul != 0) {
    mul = (0.8 - (-0.8)) / mul;
  } else {
    mul = 1;
  }
  mashtab(tmp, mul);
}

void mashtab(main_struct *tmp, double mul) {
  for (int i = 0; i < tmp->v->vertex_mount; i++) {
    for (int j = 0; j < 3; j++) {
      tmp->v->vertex_matrix[i][j] = tmp->v->vertex_matrix[i][j] * (mul);
    }
  }
}

// void print_matrix(main_struct *tmp) {
//   for (int i = 0; i < tmp->v->vertex_mount; i++) {
//     for (int j = 0; j < 3; j++) {
//       printf("ck_assert_ldouble_eq_tol(%lf, obj.v->vertex_matrix[%d][%d],
//       1e-6);\n", tmp->v->vertex_matrix[i][j], i, j);
//     }
//     printf("\n");
//   }
// }

// void print_poligon(main_struct *tmp) {
//   for (int i = 0; i < tmp->struct_count; i++) {
//     for (int j = 0; j < tmp->p[tmp->struct_count - 1]->poligon_sum; j++) {
//       printf("%d ", tmp->p[i]->poligon_arr[j]);
//     }
//     printf("\n");
//   }
// }

void s21_realloc_poligon_arr(main_struct *result) {
  result->p[result->struct_count - 1]->poligon_arr = (int *)realloc(
      result->p[result->struct_count - 1]->poligon_arr,
      result->p[result->struct_count - 1]->poligon_sum * sizeof(int));
}

void s21_realloc_struct(main_struct *result) {
  result->p =
      (poligon **)realloc(result->p, result->struct_count * sizeof(poligon *));
  result->p[result->struct_count - 1] = (poligon *)malloc(sizeof(poligon));
  result->p[result->struct_count - 1]->poligon_sum = 0;
}

int s21_realloc_matrix(int rows, int columns, main_struct *result) {
  int res = 0;
  if ((result->v->vertex_matrix = (double **)realloc(
           result->v->vertex_matrix, rows * sizeof(double *))) == NULL) {
    res = 1;
  }
  if (result->v->vertex_matrix) {
    result->v->vertex_matrix[rows - 1] =
        (double *)malloc(columns * sizeof(double));
  } else {
    res = 1;
  }
  return res;
}

void s21_free_matrix(int rows, main_struct *tmp) {
  if (rows == 0) {
    rows = 1;
  }
  for (int i = 0; i < rows; i++) {
    if (tmp->v->vertex_matrix) {
      free(tmp->v->vertex_matrix[i]);
    }
  }
  free(tmp->v->vertex_matrix);
  free(tmp->v);
}

void s21_free_poligon(main_struct *tmp) {
  for (int i = 0; i < tmp->struct_count; i++) {
    free(tmp->p[i][0].poligon_arr);
  }
  for (int i = 0; i < tmp->struct_count; i++) {
    free(tmp->p[i]);
  }
  free(tmp->p);
}

void spin(int g, double x, main_struct *tmp) {
  matrix_t M;
  matrix_t X;
  matrix_t A;
  double c = cos(x);
  double s = sin(x);
  s21_create_matrix(3, 3, &M);
  s21_create_matrix(3, 1, &X);
  if (g == 1) {
    M.matrix[0][0] = c;
    M.matrix[0][1] = 0;
    M.matrix[0][2] = s;

    M.matrix[1][0] = 0;
    M.matrix[1][1] = 1;
    M.matrix[1][2] = 0;

    M.matrix[2][0] = -s;
    M.matrix[2][1] = 0;
    M.matrix[2][2] = c;
  }
  if (g == 2) {
    M.matrix[0][0] = 1;
    M.matrix[0][1] = 0;
    M.matrix[0][2] = 0;

    M.matrix[1][0] = 0;
    M.matrix[1][1] = c;
    M.matrix[1][2] = s;

    M.matrix[2][0] = 0;
    M.matrix[2][1] = -s;
    M.matrix[2][2] = c;
  }
  if (g == 3) {
    M.matrix[0][0] = c;
    M.matrix[0][1] = s;
    M.matrix[0][2] = 0;

    M.matrix[1][0] = -s;
    M.matrix[1][1] = c;
    M.matrix[1][2] = 0;

    M.matrix[2][0] = 0;
    M.matrix[2][1] = 0;
    M.matrix[2][2] = 1;
  }

  for (int i = 0; i < tmp->v->vertex_mount; i++) {
    X.matrix[0][0] = tmp->v->vertex_matrix[i][0];
    X.matrix[1][0] = tmp->v->vertex_matrix[i][1];
    X.matrix[2][0] = tmp->v->vertex_matrix[i][2];
    s21_mult_matrix(&M, &X, &A);
    tmp->v->vertex_matrix[i][0] = A.matrix[0][0];
    tmp->v->vertex_matrix[i][1] = A.matrix[1][0];
    tmp->v->vertex_matrix[i][2] = A.matrix[2][0];
  }
  s21_remove_matrix(&M);
  s21_remove_matrix(&X);
  s21_remove_matrix(&A);
}
