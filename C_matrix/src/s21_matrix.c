
#include "s21_matrix.h"
int s21_create_matrix(int rows, int columns, matrix_t *result) {
  result->columns = columns;
  result->rows = rows;
  int status = OK;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    status = INCORRECT_MATRIX;
  } else {
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      s21_remove_matrix(result);
      status = INCORRECT_MATRIX;
    } else {
      for (int i = 0; i < rows && status != INCORRECT_MATRIX; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          s21_remove_matrix(result);
          status = INCORRECT_MATRIX;
        }
      }
    }
  }
  return status;
}
void s21_remove_matrix(matrix_t *A) {
  if (is_matrix(A)) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}
int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = FAILURE;
  if (is_matrix(A) && is_matrix(B)) {
    if (A->columns == B->columns && A->rows == B->rows) {
      status = SUCCESS;
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-7) {
            status = FAILURE;
          }
        }
      }
    }
  }
  return status;
}
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A) && is_matrix(B)) {
    status = CALC_ERROR;
    if (A->columns == B->columns && A->rows == B->rows) {
      status = OK;
      status = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && status == OK; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
        }
      }
    }
  }
  return status;
}
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A) && is_matrix(B)) {
    status = CALC_ERROR;
    if (A->columns == B->columns && A->rows == B->rows) {
      status = OK;
      status = s21_create_matrix(A->rows, A->columns, result);
      for (int i = 0; i < A->rows && status == OK; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
        }
      }
    }
  }
  return status;
}
int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A)) {
    status = OK;
    status = s21_create_matrix(A->rows, A->columns, result);
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return status;
}
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A) && is_matrix(B)) {
    status = CALC_ERROR;
    if (A->columns == B->rows) {
      status = OK;
      status = s21_create_matrix(A->rows, B->columns, result);
      for (int i = 0; i < A->rows && status == OK; i++) {
        for (int j = 0; j < B->columns; j++) {
          for (int k = 0; k < B->rows; k++) {
            result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
          }
        }
      }
    }
  }
  return status;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A)) {
    status = OK;
    status = s21_create_matrix(A->columns, A->rows, result);
    for (int i = 0; i < A->rows && status == OK; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return status;
}
int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A)) {
    status = CALC_ERROR;
    if (A->columns == A->rows && A->columns >= 2) {
      status = OK;
      status = s21_create_matrix(A->rows, A->columns, result);
      matrix_t B;
      // int invers = -1;
      for (int i = 0; i < A->rows && status == OK; i++) {
        for (int j = 0; j < A->columns; j++) {
          s21_create_matrix(A->rows - 1, A->columns - 1, &B);
          down_scale_martix(*A, &B, j, i);
          // invers *= -1;
          result->matrix[i][j] = find_det(B) * pow(-1, i + 1 + j + 1);
          if (fabs(result->matrix[i][j]) < 1e-7) {
            result->matrix[i][j] = 0;
          }
          s21_remove_matrix(&B);
        }
      }
    }
  }
  return status;
}

double find_det(matrix_t A) {
  double result = 0;
  // int invers = -1;
  if (A.rows == 1) {
    result = A.matrix[0][0];
  } else if (A.columns == A.rows && A.columns == 2) {
    result = A.matrix[0][0] * A.matrix[1][1] - A.matrix[0][1] * A.matrix[1][0];
  } else {
    matrix_t B;
    for (int i = 0; i < A.columns; i++) {
      s21_create_matrix(A.rows - 1, A.columns - 1, &B);
      down_scale_martix(A, &B, i, 0);
      // invers *= -1;
      result += A.matrix[0][i] * find_det(B) * pow(-1, i);
      s21_remove_matrix(&B);
    }
  }
  return result;
}

void down_scale_martix(matrix_t A, matrix_t *B, int column, int row) {
  int ik = 0;
  int jk = 0;
  for (int i = 0; i < A.rows; i++) {
    for (int j = 0; j < A.columns; j++) {
      if (i != row && j != column) {
        B->matrix[ik][jk] = A.matrix[i][j];
        jk++;
        if (jk == B->columns) {
          ik++;
          jk = 0;
        }
      }
    }
  }
}
int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int status = INCORRECT_MATRIX;
  double det = find_det(*A);
  if (is_matrix(A)) {
    status = CALC_ERROR;
    if (A->columns == A->rows) {
      status = CALC_ERROR;
      status = 2;
      if (fabs(det) > 1e-7) {
        status = OK;
        matrix_t B;
        matrix_t C;
        if (!s21_calc_complements(A, &C) && !s21_transpose(&C, &B) &&
            !s21_mult_number(&B, 1 / det, result)) {
          s21_remove_matrix(&B);
          s21_remove_matrix(&C);
        } else {
          status = INCORRECT_MATRIX;
        }
      } else {
        status = CALC_ERROR;
      }
    }
  }
  return status;
}
int s21_determinant(matrix_t *A, double *result) {
  int status = INCORRECT_MATRIX;
  if (is_matrix(A)) {
    status = CALC_ERROR;
    if (A->columns == A->rows) {
      status = OK;
      *result = find_det(*A);
    }
  }
  return status;
}
int is_matrix(matrix_t *A) {
  int flag = 1;
  if (A == NULL || A->matrix == NULL || A->rows < 1 || A->columns < 1) {
    flag = 0;
  }
  return flag;
}
