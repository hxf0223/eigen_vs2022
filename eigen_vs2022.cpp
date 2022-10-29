#include <Eigen/Dense>
#include <iostream>
#include <random>

template <typename T>
using mat_t = Eigen::Matrix<T, Eigen::Dynamic, Eigen::Dynamic>;

template <typename T>
static mat_t<T> randMatrix(int rowNum, int colNum, T min, T max) {
  std::random_device rd;
  const std::mt19937 gen(rd());  // NOLINT
  std::uniform_real_distribution<T> dis(min, max);

  auto m = mat_t<T>::Zero(rowNum, colNum).unaryExpr([&](T /*dummy*/) {
    return dis(gen);
  });
  return m;
}

int main() {
  constexpr int kLoopNum = 1;
  constexpr int kMatrixSize = 2048 / 2;
  auto mat1 = Eigen::MatrixXcd::Random(kMatrixSize, kMatrixSize);
  auto mat2 = Eigen::MatrixXcd::Random(kMatrixSize, kMatrixSize);
  Eigen::MatrixXcd mat3;

  for (int i = 0; i < kLoopNum; i++) {
    mat3 = mat1 * mat2;
  }
}
