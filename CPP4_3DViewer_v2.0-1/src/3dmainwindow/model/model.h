#ifndef MODEL
#define MODEL

#include <cmath>
#include <iostream>
#include <vector>

#include "../simple_matrix/simple_matrix.h"
#include "settings.h"

namespace s21 {

class Model {
 public:
  Model();
  Model(std::vector<std::vector<double>> vertex,
        std::vector<std::vector<double>> polygons);
  enum class CoordinateType { kX, kY, kZ };
  void Scale(double mul, std::vector<std::vector<double>> &vertex_);
  void Spin(CoordinateType val, double x,
            std::vector<std::vector<double>> &vertex_);
  std::pair<int, int> SettingChanges(int color, int number);
  std::pair<int, int> SettingChanges(int number);
  void SaveSettings(int *arr, std::pair<int, int> x);
  void GetSettings(int *arr);
  std::vector<std::vector<double>> &GetVertex();
  std::vector<std::vector<double>> &GetPolygons();
  std::vector<std::vector<double>> vertex_;

 private:
  void ChooseAffineMatrice_(CoordinateType val, double x, SimpleMatrix &M);
  std::vector<std::vector<double>> polygons_;
  std::unique_ptr<Settings> set;
};
}  // namespace s21
#endif  // MODEL
