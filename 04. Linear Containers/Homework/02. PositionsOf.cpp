#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <sstream>

int main() {
  using namespace std;

  int rows, cols;
  cin >> rows >> cols;

  auto matrix{ vector<vector<int>>(rows, vector<int>(cols)) };

  for_each(matrix.begin(), matrix.end(), [&cols](vector<int>& row) {
    copy_n(istream_iterator<int>(cin), cols, row.begin());
  });

  int numberToFind;
  cin >> numberToFind;

  auto indexPairs{ vector<pair<int, int>>() };

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
                std::ostringstream out;
                out << indexPair.first << " " << indexPair.second;
                return out.str();
              });
  }

  return 0;
}
