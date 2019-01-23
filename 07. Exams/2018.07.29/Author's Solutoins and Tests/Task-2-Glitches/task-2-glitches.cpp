#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 100;

void readMatrix(char matrix[MAX_SIZE][MAX_SIZE], int matrixSize) {
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      cin >> matrix[row][col];
    }
  }
}

void printMatrix(char matrix[MAX_SIZE][MAX_SIZE], int matrixSize) {
  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      cout << matrix[row][col];
    }
    cout << endl;
  }
}

bool isGlitch(char cell) {
  return cell != '.';
}

int manhattanDistance(int rowA, int colA, int rowB, int colB) {
  return abs(rowA - rowB) + abs(colA - colB);
}

void reduceGlitchToCenter(int firstRow, int centerCol, char matrix[MAX_SIZE][MAX_SIZE], int matrixSize) {
  int lastRow = firstRow;
  while (isGlitch(matrix[lastRow][centerCol])) {
    lastRow++;
  }
  lastRow--; /// we went outside the glitch, go 1 step back

  int radius = (lastRow - firstRow) / 2;

  int centerRow = firstRow + radius;
  int leftCol = centerCol - radius;
  int rightCol = centerCol + radius;

  /// walking the square that contains the glitch
  for (int r = firstRow; r <= lastRow; r++) {
    for (int c = leftCol; c <= rightCol; c++) {
      /// skipping the center - we don't want to clear that
      if (r == centerRow && c == centerCol) {
        continue;
      }

      /// making sure we are looking at the same glitch - since we are walking the square,
      /// there could be another glitch here, but if we check the radius we guarantee we
      /// don't interfere with the other glitch
      /// NOTE: this can also be done easier by checking the glitch symbol, however this
      /// is a more universal solution, because it doesn't require the symbols to be
      /// different for each glitch
      if (manhattanDistance(r, c, centerRow, centerCol) <= radius) {
        matrix[r][c] = '.';
      }
    }
  }
}

int main() {
  int matrixSize;
  cin >> matrixSize;

  char matrix[MAX_SIZE][MAX_SIZE]{ };

  readMatrix(matrix, matrixSize);

  for (int row = 0; row < matrixSize; row++) {
    for (int col = 0; col < matrixSize; col++) {
      if (isGlitch(matrix[row][col])) {
        reduceGlitchToCenter(row, col, matrix, matrixSize);
      }
    }
  }

  printMatrix(matrix, matrixSize);

  return 0;
}
