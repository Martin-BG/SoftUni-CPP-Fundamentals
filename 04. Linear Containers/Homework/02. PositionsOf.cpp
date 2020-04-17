#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main() {
  using namespace std;

  int rows, cols;
  cin >> rows >> cols;

  auto matrix = vector<vector<int>>(rows);
  for (int row = 0; row < rows; ++row) {
    matrix[row] = vector<int>(cols);
    for (int col = 0; col < cols; ++col) {
      cin >> matrix[row][col];
    }
  }

  int numberToFind;
  cin >> numberToFind;

  auto indexPairs = vector<pair<int, int>>();
  for (int row = 0; row < rows; ++row) {
    for (int col = 0; col < cols; ++col) {
      if (matrix[row][col] == numberToFind) {
        indexPairs.emplace_back(std::make_pair(row, col));

      }
    }
  }

  if (indexPairs.empty()) {
    cout << "not found";
  } else {
    transform(indexPairs.begin(), indexPairs.end(),
              ostream_iterator<string>(cout, "\n"),
              [](pair<int, int> const& indexPair) {
                return to_string(indexPair.first) + " " + to_string(indexPair.second);
              });
//    for (auto pair : indexPairs) {
//      std::cout << pair.first << " " << pair.second << std::endl;
//    }
  }

  return 0;
}
