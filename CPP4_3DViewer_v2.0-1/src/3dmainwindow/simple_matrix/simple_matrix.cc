#include "simple_matrix.h"

namespace s21 {
SimpleMatrix::SimpleMatrix() { matrix_ = std::make_shared<S21Matrix>(3, 3); }

SimpleMatrix::SimpleMatrix(const SimpleMatrix& other) { CopyMatrix(other); }

SimpleMatrix::SimpleMatrix(SimpleMatrix&& other) {
  if (other.matrix_) {
    matrix_ = std::make_shared<S21Matrix>(*other.matrix_);
  }
}

SimpleMatrix::SimpleMatrix(int x, int y) {
  matrix_ = std::make_shared<S21Matrix>(x, y);
}

SimpleMatrix::~SimpleMatrix() {}

void SimpleMatrix::MulMatrix(const SimpleMatrix& other) {
  matrix_->MulMatrix(*(other.matrix_));
}

double& SimpleMatrix::operator()(const int x, const int y) const {
  return (*matrix_)(x, y);
}

SimpleMatrix& SimpleMatrix::operator=(const SimpleMatrix& a) {
  CopyMatrix(a);
  return *this;
}

SimpleMatrix& SimpleMatrix::operator=(SimpleMatrix& a) {
  CopyMatrix(a);
  return *this;
}

SimpleMatrix& SimpleMatrix::CopyMatrix(const SimpleMatrix& other) {
  matrix_ = std::make_shared<S21Matrix>(other.GetRows(), other.GetCols());
  for (size_t i = 0; i < other.GetRows(); ++i) {
    for (size_t j = 0; j < other.GetCols(); ++j) {
      (*matrix_)(i, j) = other(i, j);
    }
  }
  return *this;
}
}  // namespace s21
