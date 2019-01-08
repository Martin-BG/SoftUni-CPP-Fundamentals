#include <iostream>
#include <vector>

int main() {
  size_t rows, cols;
  std::cin >> rows >> cols;
  std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      std::cin >> matrix[row][col];
    }
  }

  size_t evens = 0;
  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      if (matrix[row][col] % 2 == 0) {
        ++evens;
      }
    }
  }

  std::cout << evens << std::endl;

  return 0;
}
