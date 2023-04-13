#ifndef Matrix
#define Matrix

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define OK 0
#define INCORRECT_MATRIX 1
#define CALC_ERROR 2

/**
 * @brief матрицы
 *
 */
typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

void down_scale_martix(matrix_t A, matrix_t *B, int column, int row);
double find_det(matrix_t A);
int is_matrix(matrix_t *A);

/**
 * @brief создает матрицу
 *
 * @param rows строки
 * @param columns столбцы
 * @param result матрица
 * @return int 0 - ОК, 1 - ошибка
 */
int s21_create_matrix(int rows, int columns, matrix_t *result);

/**
 * @brief очищает матрицу
 *
 * @param A матрица
 */
void s21_remove_matrix(matrix_t *A);

/**
 * @brief сравнивает матрицы
 *
 * @param A 1 матрица
 * @param B 2 матрица
 * @return int 1 - SUCCESS, 0 - FAILURE
 */
int s21_eq_matrix(matrix_t *A, matrix_t *B);

/**
 * @brief складывает матрицы
 *
 * @param A 1 матрица
 * @param B 2 матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief вычитает матрицы
 *
 * @param A 1 матрица
 * @param B 2 матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief умножает матрицу на число
 *
 * @param A матрица
 * @param number число
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_mult_number(matrix_t *A, double number, matrix_t *result);

/**
 * @brief перемножает матрицы
 *
 * @param A 1 матрица
 * @param B 2 матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

/**
 * @brief транспонирует матрицу
 *
 * @param A матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_transpose(matrix_t *A, matrix_t *result);

/**
 * @brief алгеброическое дополнение
 *
 * @param A матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_calc_complements(matrix_t *A, matrix_t *result);

/**
 * @brief детерминант
 *
 * @param A матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_determinant(matrix_t *A, double *result);

/**
 * @brief обратная матрица
 *
 * @param A матрица
 * @param result результат
 * @return int 0 - ОК, 1 - INCORRECT_MATRIX, 2 - CALC_ERROR
 */
int s21_inverse_matrix(matrix_t *A, matrix_t *result);
#endif  //  Matrix