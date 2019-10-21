#include <iostream>
#include <vector>

template<typename T>
using Matrix = std::vector<std::vector<T>>;

template<typename T>
Matrix<T> readMatrix(std::istream& in);

template<typename T>
void fillMatrix(Matrix<T>& matrix,
                T fill, T start,
                size_t row, size_t col);

template<typename T>
void readParams(const Matrix<T>& matrix,
                T& fill, T& start,
                size_t& startRow, size_t& startCol,
                std::istream& in);

template<typename T>
void writeMatrixOut(const Matrix<T>& matrix, std::ostream& out);

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;
  using Type = char;

  Matrix<Type> matrix = readMatrix<Type>(in);

  Type fill, start;
  size_t startRow, startCol;
  readParams(matrix, fill, start, startRow, startCol, in);

  fillMatrix(matrix, fill, start, startRow, startCol);

  writeMatrixOut(matrix, out);

  return 0;
}

template<typename T>
Matrix<T> readMatrix(std::istream& in) {
  size_t rows;
  size_t cols;
  in >> rows >> cols;
  Matrix<T> matrix(rows, std::vector<T>(cols));

  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      std::cin >> matrix[row][col];
    }
  }

  return matrix;
}

template<typename T>
void readParams(const Matrix<T>& matrix,
                T& fill, T& start,
                size_t& startRow, size_t& startCol,
                std::istream& in) {
  in >> fill >> startRow >> startCol;
  start = matrix[startRow][startCol];
}

template<typename T>
void fillMatrix(Matrix<T>& matrix,
                const T fill, const T start,
                const size_t row, const size_t col) {
  if (row >= matrix.size() || col >= matrix[row].size() || matrix[row][col] != start) {
    return;
  }

  matrix[row][col] = fill;

  fillMatrix(matrix, fill, start, row - 1, col);
  fillMatrix(matrix, fill, start, row + 1, col);
  fillMatrix(matrix, fill, start, row, col - 1);
  fillMatrix(matrix, fill, start, row, col + 1);
}

template<typename T>
void writeMatrixOut(const Matrix<T>& matrix, std::ostream& out) {
  for (const auto& row : matrix) {
    for (const auto& col : row) {
      out << col;
    }
    out << std::endl;
  }
}
