#include "s21_matrix_oop.h"

// KONSTRUCTORS
S21Matrix::S21Matrix() noexcept {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}
S21Matrix::S21Matrix(int row, int col) : rows_(row), cols_(col) {
  if (rows_ < 1 || cols_ < 1) {
    throw std::out_of_range("Не корректная матрица");
  }
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  cols_ = other.cols_;
  rows_ = other.rows_;
  matrix_ = new double*[rows_]();
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_]();
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  if (this != &other) {
    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
    other.rows_ = 0;
    other.cols_ = 0;
  }
}
S21Matrix::~S21Matrix() {
  for (int i = 0; i < rows_; i++) {
    delete (matrix_[i]);
  }
  delete (matrix_);
  matrix_ = NULL;
  cols_ = 0;
  rows_ = 0;
}
int S21Matrix::get_rows() { return rows_; }
int S21Matrix::get_columns() { return cols_; }

void S21Matrix::set_rows(int i) {
  S21Matrix K(i, cols_);
  int new_r = rows_;
  if (i < rows_) {
    new_r = i;
  }
  for (int j = 0; j < new_r; j++) {
    for (int z = 0; z < cols_; z++) {
      K.matrix_[j][z] = matrix_[j][z];
    }
  }
  double** m = matrix_;
  matrix_ = K.matrix_;
  K.matrix_ = m;
  K.rows_ = rows_;
  rows_ = i;
}
void S21Matrix::set_columns(int i) {
  S21Matrix K(rows_, i);
  int new_c = cols_;
  if (i < cols_) {
    new_c = i;
  }
  for (int j = 0; j < rows_; j++) {
    for (int z = 0; z < new_c; z++) {
      K.matrix_[j][z] = matrix_[j][z];
    }
  }
  double** m = matrix_;
  matrix_ = K.matrix_;
  K.matrix_ = m;
  K.cols_ = cols_;
  // std::swap(K.matrix_, matrix_);
  cols_ = i;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if ((rows_ != other.rows_ || cols_ != other.cols_) ||
      (rows_ <= 0 || cols_ <= 0)) {
    throw std::out_of_range("Неверная размерность матриц");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] + other.matrix_[i][j];
    }
  }
}

bool S21Matrix::EqMatrix(const S21Matrix& other) const noexcept {
  bool res = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    res = false;
  }
  for (int i = 0; i < rows_ && res; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(matrix_[i][j] - other.matrix_[i][j]) > 1e-6) {
        res = false;
      }
    }
  }
  return res;
}
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if ((rows_ != other.rows_ || cols_ != other.cols_) ||
      (rows_ <= 0 || cols_ <= 0)) {
    throw std::out_of_range("Неверная размерность матриц");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] - other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (rows_ == 0 || cols_ == 0) {
    throw std::out_of_range("Неверная размерность матриц");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = matrix_[i][j] * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (rows_ != other.cols_ || cols_ != other.rows_) {
    throw std::out_of_range("Неверная размерность матриц");
  }
  S21Matrix C(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      for (int k = 0; k < other.rows_; k++) {
        C.matrix_[i][j] += matrix_[i][k] * other.matrix_[k][j];
      }
    }
  }
  *this = C;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix RES(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      RES.matrix_[j][i] = matrix_[i][j];
    }
  }
  return RES;
}

S21Matrix S21Matrix::CalcComplements() {
  S21Matrix RES(rows_, cols_);
  if (cols_ != rows_ && cols_ < 2) {
    throw std::out_of_range("Неверная матрица");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix* B = new S21Matrix(rows_ - 1, cols_ - 1);
      DownScaleMartix(*this, B, j, i);
      RES.matrix_[i][j] = B->Determinant() * pow(-1, i + 1 + j + 1);
      if (fabs(RES.matrix_[i][j]) < 1e-7) {
        RES.matrix_[i][j] = 0;
      }
      delete (B);
    }
  }
  return RES;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_ || rows_ <= 0) {
    throw std::out_of_range("Неверная матрица");
  }
  double res = 0;
  S21Matrix tmp;
  S21Matrix copy(*this);
  res = (-copy.Triangulate(tmp) % 2) ? -1 : 1;
  for (int x = 0; x < tmp.cols_; x++) {
    res *= tmp.matrix_[x][x];
  }
  return -res;
}

int S21Matrix::Triangulate(S21Matrix& other) noexcept {
  int znak = 1;
  other = *this;
  for (int i = 0; i < other.cols_; i++) {
    if (!other.matrix_[i][i]) {
      for (int j = i + 1; j < other.rows_; j++) {
        if (other.matrix_[j][i]) {
          znak -= other.Sdvig(j, i);
        }
      }
    }
    for (int j = i + 1; j < rows_; j++) {
      other.SumStr(j, i, -other.matrix_[j][i] / other.matrix_[i][i]);
    }
  }
  return -znak;
}
void S21Matrix::SumStr(int row, int ro, double tmp) noexcept {
  for (int x = 0; x < cols_; x++) matrix_[row][x] += matrix_[ro][x] * tmp;
}

int S21Matrix::Sdvig(int i, int j) noexcept {
  double* tmp = matrix_[i];
  matrix_[i] = matrix_[j];
  matrix_[j] = tmp;
  return -1;
}
void S21Matrix::DownScaleMartix(S21Matrix a, S21Matrix* b, int column,
                                int row) {
  int ik = 0;
  int jk = 0;
  for (int i = 0; i < a.rows_; i++) {
    for (int j = 0; j < a.cols_; j++) {
      if (i != row && j != column) {
        b->matrix_[ik][jk] = a.matrix_[i][j];
        jk++;
        if (jk == b->cols_) {
          ik++;
          jk = 0;
        }
      }
    }
  }
}

S21Matrix S21Matrix::InverseMatrix() {
  S21Matrix C_T(*this);
  double det = this->Determinant();
  if (det == 0) {
    throw std::out_of_range("Определитель равен 0");
  }
  if (rows_ >= 2) {
    S21Matrix C = CalcComplements();
    C_T = C.Transpose();
    C_T.MulNumber(1 / det);
  } else {
    C_T(0, 0) = 1 / det;
  }
  return C_T;
}

S21Matrix S21Matrix::operator+(const S21Matrix& o) const {
  // creating result matrix_
  S21Matrix res(o);
  res.SumMatrix(*this);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& o) const {
  // creating result matrix_
  S21Matrix N(*this);
  N.SubMatrix(o);
  return N;
}

S21Matrix S21Matrix::operator*(const S21Matrix& o) const {
  S21Matrix K(*this);
  K.MulMatrix(o);
  return K;
}
S21Matrix S21Matrix::operator*(const double x) const {
  S21Matrix K(*this);
  K.MulNumber(x);
  return K;
}

bool S21Matrix::operator==(const S21Matrix& o) const noexcept {
  bool res = o.EqMatrix(*this);
  return res;
}

S21Matrix S21Matrix::operator=(const S21Matrix& o) {
  if (this == &o) return *this;
  for (int i = 0; i < rows_; i++) {
    delete (matrix_[i]);
  }
  delete (matrix_);
  matrix_ = NULL;
  matrix_ = new double*[o.rows_]();
  for (int i = 0; i < o.rows_; i++) {
    matrix_[i] = new double[o.cols_]();
  }
  cols_ = o.cols_;
  rows_ = o.rows_;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+=(const S21Matrix& o) {
  this->SumMatrix(o);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& o) {
  this->SubMatrix(o);
  return *this;
}

double& S21Matrix::operator()(int i, int j) {
  if ((i < 0 || i > rows_) || (j < 0 || j > cols_)) {
    throw std::out_of_range("Неверные индексы");
  }
  return matrix_[i][j];
}

S21Matrix S21Matrix::operator*=(const S21Matrix& o) {
  S21Matrix K(*this);
  K.MulMatrix(o);
  return K;
}

S21Matrix S21Matrix::operator*=(double x) {
  this->MulNumber(x);
  return *this;
}

S21Matrix operator*(double x, S21Matrix& o) {
  S21Matrix K(o);
  K.MulNumber(x);
  return K;
}
