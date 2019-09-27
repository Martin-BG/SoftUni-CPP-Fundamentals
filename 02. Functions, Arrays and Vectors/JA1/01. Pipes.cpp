#include <iostream>
#include <vector>

typedef std::vector<int> Pipes;

Pipes parsePipes(int pipesCount);

int parseInt();

int main() {
  int pipesCount = parseInt();

  Pipes pipesOld = parsePipes(pipesCount);
  Pipes pipesNew = parsePipes(pipesCount);

  for (int i = 0; i < pipesCount; ++i) {
    int yearsLeft = pipesNew[i] / (pipesNew[i] - pipesOld[i]);
    std::cout << yearsLeft << " ";
  }

  return 0;
}

int parseInt() {
  int value;
  std::cin >> value;
  return value;
}

Pipes parsePipes(const int pipesCount) {
  Pipes pipes;
  for (int i = 0; i < pipesCount; ++i) {
    pipes.emplace_back(parseInt());
  }
  return pipes;
}
