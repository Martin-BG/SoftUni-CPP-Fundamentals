#include <iostream>
#include <vector>
#include <sstream>

void parseInput(size_t& size, std::vector<std::string>& matrix) {
  std::cin >> size;
  std::string line;
  for (size_t i = 0; i < size; ++i) {
    std::cin >> line;
    matrix.emplace_back(line);
  }
}

std::string matrixToString(const std::vector<std::string>& matrix) {
  std::ostringstream oss;
  for (auto const& line : matrix) {
    oss << line << std::endl;
  }
  return oss.str();
}

void initResult(const size_t& size, std::vector<std::string>& result) {
  for (size_t i = 0; i < size; ++i) {
    result.emplace_back(size, '.');
  }
}

void findGlitches(const size_t& size, const std::vector<std::string>& matrix, std::vector<std::string>& result) {
  initResult(size, result);

  std::string symbols = "!?@#$%^&*()_+-=[]{}|:";

  bool done;
  do {
    done = true;
    for (size_t i = 0; i < size; ++i) {
      std::size_t col = matrix[i].find_first_of(symbols);
      if (col != std::string::npos) {
        done = false;
        char symbol = matrix[i][col];
        size_t row = 1;
        while (matrix[i + row][col] == symbol) {
          ++row;
        }
        row = i + row / 2;
        result[row][col] = symbol;
        symbols.erase(symbols.find(symbol), 1);
        break;
      }
    }
  } while (!done);
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t size;
  std::vector<std::string> matrix;
  parseInput(size, matrix);

  std::vector<std::string> result;
  findGlitches(size, matrix, result);

  std::cout << matrixToString(result);

  return 0;
}
