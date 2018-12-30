#include <iostream>
#include <map>

int main() {
  int count;
  std::cin >> count;

  std::string made, model;
  int year;
  std::multimap<std::string, std::pair<std::string, int> > cars;

  for (int i = 0; i < count; ++i) {
    std::cin >> made >> model >> year;
    cars.emplace(made, std::make_pair(model, year));
  }

  int action;
  std::cin >> action;

  if (action == 1) {
    std::cin >> made;
    for (auto itr = cars.lower_bound(made); itr != cars.upper_bound(made); ++itr) {
      std::cout << itr->first << " " << itr->second.first << " " << itr->second.second << std::endl;
    }
  } else if (action == 2) {
    for (const auto& itr : cars) {
      std::cout << itr.first << " " << itr.second.first << " " << itr.second.second << std::endl;
    }
  }

  return 0;
}
