#include <iostream>
#include <vector>

bool isSimpleNumber(int number) {
  if (number != 2) {
    if (number < 1 || number % 2 == 0) {
      return false;
    }

    for (int i = 3; (i * i) <= number; i += 2) {
      if (number % i == 0) {
        return false;
      }
    }
  }
  return true;
}

int main() {
  size_t matrixSize;
  std::cin >> matrixSize;

  std::vector<std::vector<int>> matrix{ matrixSize, std::vector<int>(matrixSize) };

  for (size_t row = 0; row < matrixSize; ++row) {
    for (size_t col = 0; col < matrixSize; ++col) {
      std::cin >> matrix[row][col];
    }
  }

  long long sum = 0;
  if (matrixSize > 2) {
    for (size_t row = matrixSize - 1, offset = 1; row > matrixSize / 2; --row, ++offset) {
      for (size_t col = offset; col < matrixSize - offset; ++col) {
        if (isSimpleNumber(matrix[row][col])) {
          sum += matrix[row][col];
        }
      }
    }
  }
  std::cout << sum;

  return 0;
}
