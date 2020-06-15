#include <iostream>
#include <map>
#include <sstream>

int main() {
  std::string line;
  std::getline(std::cin >> std::ws, line);
  std::istringstream iss(line);
  std::map<double, size_t> numbersCount;

  double num;
  while (iss >> num) {
    ++numbersCount[num];
  }

  for (auto const& pair: numbersCount) {
    std::cout << pair.first << " -> " << pair.second << std::endl;
  }

  return 0;
}
