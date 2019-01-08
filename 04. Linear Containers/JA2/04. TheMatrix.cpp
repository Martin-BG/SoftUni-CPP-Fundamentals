#include <iostream>
#include <vector>

void fillMatrix(std::vector<std::vector<char>>& matrix,
                size_t rows, size_t cols,
                char fillChar,
                char replaceChar,
                size_t row, size_t col) {
  if (row < 0 || row > rows - 1 ||
      col < 0 || col > cols - 1 ||
      matrix[row][col] != replaceChar) {
    return;
  }

  matrix[row][col] = fillChar;

  fillMatrix(matrix, rows, cols, fillChar, replaceChar, row - 1, col);
  fillMatrix(matrix, rows, cols, fillChar, replaceChar, row + 1, col);
  fillMatrix(matrix, rows, cols, fillChar, replaceChar, row, col - 1);
  fillMatrix(matrix, rows, cols, fillChar, replaceChar, row, col + 1);

}

int main() {
  size_t rows, cols;
  std::cin >> rows >> cols;
  std::vector<std::vector<char>> matrix(rows, std::vector<char>(cols));

  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      std::cin >> matrix[row][col];
    }
  }

  char fillChar;
  size_t startRow, startCol;
  std::cin >> fillChar >> startRow >> startCol;

  char replaceChar = matrix[startRow][startCol];
  fillMatrix(matrix, rows, cols, fillChar, replaceChar, startRow, startCol);

  for (size_t row = 0; row < rows; ++row) {
    for (size_t col = 0; col < cols; ++col) {
      std::cout << matrix[row][col];
    }
    std::cout << std::endl;
  }

  return 0;
}
