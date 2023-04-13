// created by pizpoti
#ifndef PARCER_H_
#define PARCER_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_matrix.h"

/**
 * @brief структура хранения вершин
 */
typedef struct {
  int vertex_mount;        // количество вершин
  double **vertex_matrix;  // матрица координат
  double vertex_x[2];      // min and max
  double vertex_y[2];      // min and max
  double vertex_z[2];      // min and max
} vertex;

/**
 * @brief структура с полигонами
 */
typedef struct {
  int *poligon_arr;  // массив полигонов
  int poligon_sum;  // колличество индексов в полигоне
} poligon;

/**
 * @brief основная структура
 */
typedef struct {
  vertex *v;
  poligon **p;
  int struct_count;  // колличество созданных структур с полигонами
} main_struct;

/**
 * @brief открывает файл и проверяет на валидность
 *
 * @param file файл
 * @param tmp структура из QT
 * @return int 1 - ОК, 0 - файл не существует
 */
int parser(char *file, main_struct *tmp);

/**
 * @brief читает файл построчно
 *
 * @param file файл
 * @param tmp структура из QT
 * @return int 1 - ОК, 0 - ошибка
 */
int file_parser(FILE *file, main_struct *tmp);

/**
 * @brief парсит строку
 *
 * @param str строка
 * @param tmp структура из QT
 * @return int 0 - ошибка, 1 - v, 2 - f
 */
int check_str(char *str);

/**
 * @brief записывает координаты в матрицу tmp->v->vertex_matrix
 *
 * @param str строка из файла
 * @param tmp структура из QT
 */
void record_on_vertex(char *str, main_struct *tmp);

/**
 * @brief конвертирует строку в число и устанавливает указатель на следующее
 * число
 *
 * @param res записывает результат
 * @param str строка
 * @return char* указатель на следующее число или NULL если числа нет
 */
char *convertation(char *str, double *res);

/**
 * @brief создает матрицу
 *
 * @param rows строки
 * @param result результат
 * @return int 0 - ОК, 1 - матрица не создана
 */
int s21_realloc_matrix(int rows, int columns, main_struct *result);

/**
 * @brief реалочит полигон
 *
 * @param result результат записывает в poligon_arr
 */
void s21_realloc_poligon_arr(main_struct *result);

/**
 * @brief реалочит структуру полигонов
 *
 * @param result результат
 */
void s21_realloc_struct(main_struct *result);

/**
 * @brief очищает матрицу
 *
 * @param rows строки
 * @param tmp структура из QT
 */
void s21_free_matrix(int rows, main_struct *tmp);

/**
 * @brief очищает полигон
 *
 * @param tmp структура из QT
 */
void s21_free_poligon(main_struct *tmp);

/**
 * @brief записывает координаты полигона в poligon_arr
 *
 * @param str строка
 * @param tmp структура из QT
 */
void record_on_poligon(char *str, main_struct *tmp);

/**
 * @brief центрует рисунок
 *
 * @param tmp структура из QT
 */
void centr(main_struct *tmp);

/**
 * @brief редактирует масштаб
 *
 * @param tmp структура из QT
 * @param mul число
 */
void mashtab(main_struct *tmp, double mul);

/**
 * @brief перемножает массив вершин
 *
 * @param g 1 - х, 2 - у, 3 - z
 * @param x число
 * @param tmp структура
 */
void spin(int g, double x, main_struct *tmp);

/**
 * @brief принтует файл
 *
 * @param file файл
 */
void pr_file(char *file);

/**
 * @brief принтует вершины
 *
 * @param tmp структура
 */
void print_matrix(main_struct *tmp);

/**
 * @brief принтует структуры с полигонами
 *
 * @param tmp структура
 */
void print_poligon(main_struct *tmp);

#endif  // PARCER_H_
