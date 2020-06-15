#include <iostream>

int main() {
  std::string first, second;
  std::getline(std::cin >> std::ws, first);
  std::getline(std::cin >> std::ws, second);

  std::cout << ((first == second) ? "equal" : "not equal") << std::endl;

  return 0;
}
