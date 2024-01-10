#include <iostream>
#include <vector>

using Wagon = std::string;
using Train = std::vector<Wagon>;

void printTrain(const Train& train) {
  if (train.empty()) {
    return;
  }

  std::cout << '|';
  for (const Wagon& wagon: train) {
    std::cout << wagon << '|';
  }
  std::cout << '\n';
}

Train readTrain() {
  Train train{ };

  while (true) {
    Wagon wagon{ };
    std::getline(std::cin, wagon);

    if (wagon == "end") {
      break;
    }

    if (wagon == "empty") {
      wagon = " ";
    }

    train.emplace_back(wagon);
  }

  return train;
}

Wagon removeWagon(Train& train, size_t pos) {
  Train newTrain{ };
  Wagon removed{ };

  for (size_t i = 0; i < train.size(); ++i) {
    if (i == pos) {
      removed = train[i];
      continue;
    }
    newTrain.emplace_back(train[i]);
  }

  train = newTrain;

  return removed;
}

void moveWagon(Train& train, size_t from, size_t to) {
  Train newTrain(train.size());
  Wagon removed = removeWagon(train, from);

  for (int i = 0, j = 0; j < newTrain.size(); ++j, ++i) {
    if (j == to) {
      newTrain[j] = removed;
      --i;
    } else {
      newTrain[j] = train[i];
    }
  }

  train = newTrain;
}

int main() {
  Train train = readTrain();

  while (true) {
    char command;
    std::cin >> std::ws >> command;

    if (command == 'E') {
      break;
    }

    if (command == 'M') {
      size_t from;
      size_t to;
      std::cin >> from >> to;
      --from;
      --to;
      moveWagon(train, from, to);
      printTrain(train);
    }

    if (command == 'L') {
      size_t pos;
      std::cin >> pos;
      --pos;
      removeWagon(train, pos);
      printTrain(train);
    }

    if (command == 'P') {
      printTrain(train);
    }
  }

  return 0;
}
