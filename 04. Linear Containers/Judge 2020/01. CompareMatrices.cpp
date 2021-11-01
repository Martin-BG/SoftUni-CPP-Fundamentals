#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

using IntRow = std::vector<int>;
using IntMatrix = std::vector<IntRow>;

IntMatrix readMatrixFromStream(std::basic_istream<char>& istream);

int main() {
  std::istream& istream = std::cin;
  std::ostream& ostream = std::cout;

  auto firstMatrix = readMatrixFromStream(istream);
  auto secondMatrix = readMatrixFromStream(istream);

  if (firstMatrix == secondMatrix) {
    ostream << "equal" << std::endl;
  } else {
    ostream << "not equal" << std::endl;
  }

  return 0;
}

IntMatrix readMatrixFromStream(std::basic_istream<char>& istream) {
  int rows;
  istream >> rows;

  auto matrix{ IntMatrix(rows) };

  for_each(matrix.begin(), matrix.end(), [&istream](IntRow& row) {
    std::string input;
    getline(istream >> std::ws, input);
    std::istringstream iss{input};
    copy(std::istream_iterator<int>(iss), std::istream_iterator<int>(), std::back_inserter(row));
  });

  return matrix;
}
