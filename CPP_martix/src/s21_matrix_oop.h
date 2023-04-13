#ifndef CPP_CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_H
#define CPP_CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_H

#include <cmath>
#include <iostream>

class S21Matrix {
 private:
  int rows_, cols_;
  double** matrix_;
  void DownScaleMartix(S21Matrix a, S21Matrix* b, int column, int row);  //
  int Triangulate(S21Matrix& other) noexcept;
  int Sdvig(int i, int j) noexcept;
  void SumStr(int row, int row2, double tmp) noexcept;

 public:
  S21Matrix() noexcept;
  S21Matrix(int row, int col);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix() noexcept;
  void SumMatrix(const S21Matrix& other);
  bool EqMatrix(const S21Matrix& other) const noexcept;
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
  int get_rows();
  int get_columns();
  void set_rows(int i);
  void set_columns(int i);
  S21Matrix operator+(const S21Matrix& o) const;
  S21Matrix operator-(const S21Matrix& o) const;

  S21Matrix operator*(const S21Matrix& o) const;
  S21Matrix operator*(const double x) const;

  bool operator==(const S21Matrix& o) const noexcept;
  S21Matrix operator=(const S21Matrix& o);
  S21Matrix operator+=(const S21Matrix& o);
  S21Matrix operator-=(const S21Matrix& o);
  S21Matrix operator*=(const S21Matrix& o);
  S21Matrix operator*=(double x);
  double& operator()(int i, int j);
  friend S21Matrix operator*(double x, S21Matrix& o);
};

#endif  //  CPP_CPP1_S21_MATRIXPLUS_1_SRC_S21_MATRIX_H
