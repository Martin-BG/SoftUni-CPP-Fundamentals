#include <iostream>
#include <map>

int main() {
  std::map<std::string, std::pair<double, double>> towsMinMaxTemperatures{ };

  size_t towns;
  std::cin >> towns;

  while (towsMinMaxTemperatures.size() < towns) {
    double min, max;
    std::string town;
    std::cin >> town >> min >> max;

    if (towsMinMaxTemperatures.find(town) == towsMinMaxTemperatures.end()) {
      towsMinMaxTemperatures.emplace(town, std::make_pair(min, max));
    }

    if (towsMinMaxTemperatures[town].first > min) {
      towsMinMaxTemperatures[town].first = min;
    }

    if (towsMinMaxTemperatures[town].second < max) {
      towsMinMaxTemperatures[town].second = max;
    }
  }

  for (const auto& townTemps: towsMinMaxTemperatures) {
    const std::string& town = townTemps.first;
    const double minTemp = townTemps.second.first;
    const double maxTemp = townTemps.second.second;
    std::cout << town << " " << minTemp << " " << maxTemp << std::endl;
  }

  return 0;
}
