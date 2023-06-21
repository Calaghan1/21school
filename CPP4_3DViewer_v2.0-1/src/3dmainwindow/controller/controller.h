#ifndef CONTROLLER_
#define CONTROLLER_
#include <memory>

#include "../model/model.h"
#include "../parser/parser.h"

namespace s21 {

class Controller {
 public:
  Controller() noexcept;
  Controller(Controller &&) = default;
  Controller(const Controller &) = delete;
  Controller &operator=(Controller &&) = default;
  Controller &operator=(const Controller &) = delete;
  ~Controller() noexcept;

  void SpinX(double x, std::vector<std::vector<double>> &vertex_);
  void SpinY(double x, std::vector<std::vector<double>> &vertex_);
  void SpinZ(double x, std::vector<std::vector<double>> &vertex_);
  void Scale(double mul, std::vector<std::vector<double>> &vertex_);
  std::pair<int, int> SettingChanges(int color, int number);
  std::pair<int, int> SettingChanges(int number);
  void GetSettings(int *arr);
  void SaveSettings(int *arr, std::pair<int, int> x);
  void ReceiveModelFromFile(const std::string &path);
  void DestroyPreviousModel();
  std::vector<std::vector<double>> &GetVertex();
  std::vector<std::vector<double>> &GetPolygons();

 private:
  std::unique_ptr<Model> model_;
  std::unique_ptr<File> file_;
};

}  // namespace s21

#endif  // CONTROLLER_
