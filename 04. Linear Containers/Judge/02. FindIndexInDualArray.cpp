#include <iostream>
#include <vector>

int main() {
  int number;
  size_t rows, cols;
  std::cin >> number >> rows >> cols;
  std::vector<std::vector<int>> matrix(rows, std::vector<int>(cols));

  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      std::cin >> matrix[row][col];
    }
  }

  bool found = false;
  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      if (matrix[row][col] == number) {
        std::cout << row << col << std::endl;
        found = true;
      }
    }
  }

  if (!found) {
    std::cout << "Number not found" << std::endl;
  }

  return 0;
}
