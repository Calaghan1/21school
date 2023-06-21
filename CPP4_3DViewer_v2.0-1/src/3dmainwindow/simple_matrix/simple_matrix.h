#include "s21_matrix_oop.h"
#ifndef SIMPLE_MATRIX_
#define SIMPLE_MATRIX_

namespace s21 {
class SimpleMatrix {
 public:
  SimpleMatrix();
  explicit SimpleMatrix(S21Matrix *data);
  SimpleMatrix(int x, int y);
  ~SimpleMatrix();
  explicit SimpleMatrix(const SimpleMatrix &other);
  explicit SimpleMatrix(SimpleMatrix &&other);
  SimpleMatrix &operator=(const SimpleMatrix &other);
  SimpleMatrix &operator=(SimpleMatrix &other);
  void MulMatrix(const SimpleMatrix &other);
  double &operator()(const int x, const int y) const;
  int GetRows() const { return matrix_->GetRows(); };
  int GetCols() const { return matrix_->GetCols(); };

 private:
  std::shared_ptr<S21Matrix> matrix_;
  SimpleMatrix &CopyMatrix(const SimpleMatrix &other);
};
}  // namespace s21

#endif  // SIMPLE_MATRIX_
