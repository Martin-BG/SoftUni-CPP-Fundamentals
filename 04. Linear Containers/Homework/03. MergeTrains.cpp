#include <iostream>
#include <stack>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <vector>

using Railcar = std::pair<char, int>;
using Train = std::stack<int>;
using MergedTrain = std::vector<Railcar>;

Train readTrainFromStream(std::basic_istream<char>& istream);

MergedTrain mergeTrains(Train trainA, Train trainB);

void printTrain(const MergedTrain& merged, std::basic_ostream<char>& ostream);

int main() {
  Train trainA{ readTrainFromStream(std::cin) };
  Train trainB{ readTrainFromStream(std::cin) };

  MergedTrain merged{ mergeTrains(trainA, trainB) };

  printTrain(merged, std::cout);

  return 0;
}

void printTrain(const MergedTrain& merged, std::basic_ostream<char>& ostream) {
  std::transform(merged.cbegin(), merged.cend(),
                 std::ostream_iterator<char>(ostream, ""),
                 [](Railcar const& p) { return p.first; });
  ostream << std::endl;

  std::transform(merged.rbegin(), merged.rend(),
                 std::ostream_iterator<int>(ostream, " "),
                 [](Railcar const& p) { return p.second; });
  ostream << std::endl;
}

MergedTrain mergeTrains(Train trainA, Train trainB) {
  MergedTrain mergedTrain{ };

  while (!trainA.empty() || !trainB.empty()) {
    if (trainA.empty()) {
      mergedTrain.emplace_back('B', trainB.top());
      trainB.pop();
    } else if (trainB.empty()) {
      mergedTrain.emplace_back('A', trainA.top());
      trainA.pop();
    } else if (trainA.top() < trainB.top()) {
      mergedTrain.emplace_back('A', trainA.top());
      trainA.pop();
    } else {
      mergedTrain.emplace_back('B', trainB.top());
      trainB.pop();
    }
  }

  return mergedTrain;
}

Train readTrainFromStream(std::basic_istream<char>& istream) {
  Train train{ };

  std::string input;
  getline(istream, input);
  std::istringstream iss{ input };

  std::for_each(std::istream_iterator<int>(iss),
                std::istream_iterator<int>(),
                [&train](const int i) {
                  train.push(i);
                });

  return train;
}
