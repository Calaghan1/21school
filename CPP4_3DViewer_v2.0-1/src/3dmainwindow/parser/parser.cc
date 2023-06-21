#include "parser.h"

namespace s21 {

File::File() {
  vertex_x_[0] = 1000000;
  vertex_x_[1] = -1000000;
  vertex_y_[0] = 1000000;
  vertex_y_[1] = -1000000;
  vertex_z_[0] = 1000000;
  vertex_z_[1] = -1000000;
};
File::~File(){};

/*!
 * @brief читает файл
 *
 * @param file_name путь к файлу
 * \return std::pair <std::vector<std::vector<double>>,
 * std::vector<std::vector<double>>> возвращает пару двумерных векторов из
 * вершин и полигонов
 */
Model File::Parser(const std::string &file_name) {
  std::string str;
  std::ifstream file(file_name);
  vertex_.clear();
  polygons_.clear();
  while (getline(file, str)) {
    if (CheckStr(str)) {
      if (str[0] == 'v' && str[1] == ' ') {
        RecordOn(str, true);
      } else if (str[0] == 'f' && str[1] == ' ') {
        RecordOn(str, false);
      }
      str.clear();
    }
  }
  for (size_t i = 0; i < polygons_.size(); ++i) {
    for (size_t j = 0; j < polygons_[i].size(); ++j) {
      polygons_[i][j] -= 1;
    }
  }
  Alignment();
  file.close();
  return Model(vertex_, polygons_);
};

/*!
 * @brief проверяет строку на соответствие
 *
 * @param str строка
 * \return bool true строка валидная
 */
bool File::CheckStr(const std::string str) const noexcept {
  bool res = true;
  int i = 0;
  if ((str[i] == 'v' || str[i] == 'f') && str[1] == ' ') {
    i++;
    for (; str[i] != '\0' && res; i++) {
      if ((str[i] > 8 && str[i] < 11) || str[i] == 13 || str[i] == 32 ||
          (str[i] > 44 && str[i] < 58)) {
      } else {
        res = false;
      }
    }
  } else {
    res = false;
  }
  return res;
};

/*!
 * @brief записывает значения в вектора
 *
 * @param str строка
 * @param flag вершины или полигоны
 */
void File::RecordOn(const std::string str, bool flag) {
  std::vector<double> vec;
  for (size_t i = 2; str[i] != '\n' && str[i] != '\0' && i < str.size(); ++i) {
    std::string tmp;
    for (; !std::isdigit(str[i]) && str[i] != 45 && str[i] != '\0' &&
           str[i] != '\n';
         ++i) {
    }
    if (str[i] == '\0' || str[i] == '\n' || str[i] == 13) {
      break;
    }
    while (std::isdigit(str[i]) || str[i] == '.' || str[i] == '-') {
      tmp.push_back(str[i]);
      ++i;
    }
    while (str[i] != ' ' && str[i] != '\0' && str[i] != '\n') {
      ++i;
    }
    vec.push_back(std::stod(tmp));
  }
  if (flag) {
    vertex_.push_back(vec);
    if (vec[0] <= vertex_x_[0]) {
      vertex_x_[0] = vec[0];
    }
    if (vec[0] > vertex_x_[1]) {
      vertex_x_[1] = vec[0];
    }
    if (vec[1] <= vertex_y_[0]) {
      vertex_y_[0] = vec[1];
    }
    if (vec[1] > vertex_y_[1]) {
      vertex_y_[1] = vec[1];
    }
    if (vec[2] <= vertex_z_[0]) {
      vertex_z_[0] = vec[2];
    }
    if (vec[2] > vertex_z_[1]) {
      vertex_z_[1] = vec[2];
    }
  } else {
    polygons_.push_back(vec);
  }
};

/*!
 * @brief центрует объект
 *
 */
void File::Alignment() {
  double x = vertex_x_[0] + (vertex_x_[1] - vertex_x_[0]) / 2;
  double y = vertex_y_[0] + (vertex_y_[1] - vertex_y_[0]) / 2;
  double z = vertex_z_[0] + (vertex_z_[1] - vertex_z_[0]) / 2;
  for (size_t i = 0; i < vertex_.size(); i++) {
    for (size_t j = 0; j < 3; j++) {
      if (j == 0) {
        vertex_[i][j] -= x;
      } else if (j == 1) {
        vertex_[i][j] -= y;
      } else if (j == 2) {
        vertex_[i][j] -= z;
      }
    }
  }
  double max_x = vertex_x_[1] - vertex_x_[0];
  double max_y = vertex_y_[1] - vertex_y_[0];
  double max_z = vertex_z_[1] - vertex_z_[0];
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
  for (size_t i = 0; i < vertex_.size(); i++) {
    for (int j = 0; j < 3; j++) {
      vertex_[i][j] *= mul;
    }
  }
};
}  // namespace s21
