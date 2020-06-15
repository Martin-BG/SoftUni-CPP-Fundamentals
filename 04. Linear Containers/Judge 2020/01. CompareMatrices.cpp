#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using IntMatrix = std::vector<std::vector<int>>;

IntMatrix readMatrixFromStream(std::basic_istream<char>& istream);

int main() {
  auto firstMatrix = readMatrixFromStream(std::cin);
  auto secondMatrix = readMatrixFromStream(std::cin);

  if (firstMatrix == secondMatrix) {
    std::cout << "equal" << std::endl;
  } else {
    std::cout << "not equal" << std::endl;
  }

  return 0;
}

IntMatrix readMatrixFromStream(std::basic_istream<char>& istream) {
  int rows;
  istream >> rows;

  auto matrix{ IntMatrix(rows) };

  for_each(matrix.begin(), matrix.end(), [&istream](std::vector<int>& row) {
    std::string input;
    getline(istream >> std::ws, input);
    std::istringstream iss{ input };
    copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(row));
  });

  return matrix;
}
