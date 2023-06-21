#ifndef PARSER_H_
#define PARSER_H_

#include <fstream>

#include "../model/model.h"

namespace s21 {
class File {
 public:
  File();
  ~File();
  Model Parser(const std::string &file_name);
  bool CheckStr(const std::string str) const noexcept;
  void RecordOn(const std::string str, bool flag);
  void Alignment();

 private:
  std::vector<std::vector<double>> vertex_;
  std::vector<std::vector<double>> polygons_;
  double vertex_x_[2];
  double vertex_y_[2];
  double vertex_z_[2];
};
}  // namespace s21

#endif  // PARSER_H_
