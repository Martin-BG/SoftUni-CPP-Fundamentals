#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Vector2D.h"

class City {
  std::string name;
  Vector2D coords;
public:
  double getDistanceTo(const City& other) const {
    return (coords - other.coords).getLength();
  }

  const std::string& getName() const {
    return name;
  }

  friend std::istream& operator>>(std::istream& is, City& city) {
    double coordX, coordY;
    std::cin >> city.name >> coordX >> coordY;
    city.coords = { coordX, coordY };
    return is;
  }
};

int main() {
  size_t entries;
  std::cin >> entries;

  std::vector<City> cities(entries);
  std::copy_n(std::istream_iterator<City>(std::cin), entries, cities.begin());

  double shortestDist = -1.0;
  std::pair<std::string, std::string> closestCities;

  for (auto from = cities.cbegin(); from != cities.cend(); ++from) {
    for (auto to = std::next(from, 1); to != cities.cend(); ++to) {
      double currentDist = from->getDistanceTo(*to);
      if (shortestDist == -1.0 || currentDist < shortestDist) {
        closestCities = { from->getName(), to->getName() };
        shortestDist = currentDist;
      }
    }
  }

  std::cout << closestCities.first << "-" << closestCities.second;

  return 0;
}
