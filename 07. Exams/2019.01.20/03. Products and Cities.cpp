#include <iostream>
#include <map>

int main() {
  size_t citiesCount;
  std::string name;
  double price, quantity;

  std::map<std::string, double> citiesTotalPrice;

  std::cin >> citiesCount;

  do {
    std::cin >> name >> price >> quantity;
    citiesTotalPrice[name] += price * quantity;
  } while (citiesCount > citiesTotalPrice.size());

  for (auto const& pair : citiesTotalPrice) {
    std::cout << pair.first << " " << pair.second << std::endl;
  }

  return 0;
}
