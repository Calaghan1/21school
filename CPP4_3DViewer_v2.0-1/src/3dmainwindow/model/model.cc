#include "model.h"

namespace s21 {

Model::Model()
    : vertex_(std::vector<std::vector<double>>{}),
      polygons_(std::vector<std::vector<double>>{}) {}

Model::Model(std::vector<std::vector<double>> vertex,
             std::vector<std::vector<double>> polygons)
    : vertex_(vertex), polygons_(polygons) {}

/*!
 * @brief пересчитывает вершины при движение модели
 *
 * @param mul множитель расстояния
 * @param vertex_ вектор вершин
 */
void Model::Scale(double mul, std::vector<std::vector<double>> &vertex_) {
  for (size_t i = 0; i < vertex_.size(); i++) {
    for (int j = 0; j < 3; j++) {
      vertex_[i][j] = vertex_[i][j] * (mul);
    }
  }
};

/*!
 * @brief афинное преобразование
 *
 * @param val тип координаты
 * @param x коэфицент поворота
 * @param vertex_ вектор вершин
 */
void Model::Spin(CoordinateType val, double x,
                 std::vector<std::vector<double>> &vertex_) {
  SimpleMatrix X(3, 1);
  SimpleMatrix M(3, 3);
  ChooseAffineMatrice_(val, x, M);
  for (size_t i = 0; i < vertex_.size(); i++) {
    X(0, 0) = vertex_[i][0];
    X(1, 0) = vertex_[i][1];
    X(2, 0) = vertex_[i][2];
    SimpleMatrix A(M);
    A.MulMatrix(X);
    vertex_[i][0] = A(0, 0);
    vertex_[i][1] = A(1, 0);
    vertex_[i][2] = A(2, 0);
  }
};

/*!
 * @brief афинное преобразование
 *
 * @param val тип координаты
 * @param x коэфицент поворота
 * \return SimpleMatrix
 */
void Model::ChooseAffineMatrice_(CoordinateType val, double x,
                                 SimpleMatrix &M) {
  double c = cos(x);
  double s = sin(x);
  switch (val) {
    case CoordinateType::kX:
      M(0, 0) = c;
      M(0, 1) = 0;
      M(0, 2) = s;
      M(1, 0) = 0;
      M(1, 1) = 1;
      M(1, 2) = 0;
      M(2, 0) = -s;
      M(2, 1) = 0;
      M(2, 2) = c;
      break;
    case CoordinateType::kY:
      M(0, 0) = 1;
      M(0, 1) = 0;
      M(0, 2) = 0;
      M(1, 0) = 0;
      M(1, 1) = c;
      M(1, 2) = s;
      M(2, 0) = 0;
      M(2, 1) = -s;
      M(2, 2) = c;
      break;
    case CoordinateType::kZ:
      M(0, 0) = c;
      M(0, 1) = s;
      M(0, 2) = 0;
      M(1, 0) = -s;
      M(1, 1) = c;
      M(1, 2) = 0;
      M(2, 0) = 0;
      M(2, 1) = 0;
      M(2, 2) = 1;
      break;
  }
};

/*!
 * @brief запускает метод класса s21::Setting для сохранения новых настроек в
 * файл
 *
 * @param color значение
 * @param number ключ
 * \return std::pair<int, int> возвращает пару: ключ, значение
 */
std::pair<int, int> Model::SettingChanges(int color, int number) {
  s21::Settings tmp;
  return tmp.SettingChanges(color, number);
};

/*!
 * @brief запускает метод класса s21::Setting для сохранения новых настроек в
 * файл
 *
 * @param number ключ
 * \return std::pair<int, int> int> возвращает пару: ключ, значение
 */
std::pair<int, int> Model::SettingChanges(int number) {
  s21::Settings tmp;
  return tmp.SettingChanges(number);
};

/*!
 * @brief сохраняет найстройки в массив
 *
 * @param arr массив настроек
 * @param x пара: ключ, значение
 */
void Model::SaveSettings(int *arr, std::pair<int, int> x) {
  if (x.first == 11) {
    arr[11] = 10000;
  } else if (x.first == 12) {
    arr[16] = 1;
    arr[17] = 2;
  } else if (x.first == 13) {
    arr[16] = 0;
    arr[17] = 2;
  } else if (x.first == 14) {
    arr[18] = 1;
    arr[11] = 0;
  } else if (x.first == 15) {
    arr[18] = 0;
    arr[11] = 0;
  } else {
    arr[x.first] = x.second;
  }
};

/*!
 * @brief запускает метод класса s21::Setting для считывания настроек из файла в
 * массив
 *
 * @param arr массив настроек
 */
void Model::GetSettings(int *arr) {
  s21::Settings tmp;
  tmp.GetSettings(arr);
};

std::vector<std::vector<double>> &Model::GetVertex() { return vertex_; };

std::vector<std::vector<double>> &Model::GetPolygons() { return polygons_; };
}  // namespace s21
