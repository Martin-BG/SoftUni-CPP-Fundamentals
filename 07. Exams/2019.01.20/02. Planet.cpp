#include <iostream>
#include <sstream>
#include <vector>

class Planet {
private:
  static const int LIGHT_SPEED = 299792;

  std::string name;
  int distanceFromStar;
  int diameter;
  int mass;

  int lightFromStarTravelTime() const {
    return this->distanceFromStar / LIGHT_SPEED;
  }

public:
  Planet(std::string name, int distanceFromStar, int diameter, int mass) :
      name(std::move(name)),
      distanceFromStar(distanceFromStar),
      diameter(diameter),
      mass(mass) { }

  std::string toString() const {
    std::ostringstream oss;
    oss << name << " " << distanceFromStar << " " << diameter << " " << mass << std::endl << lightFromStarTravelTime();
    return oss.str();
  }

  int getDiameter() const {
    return diameter;
  }

  int getMass() const {
    return mass;
  }
};

int findMinMass(std::vector<Planet> const& planets) {
  int minMass = planets.at(0).getMass();
  for (auto const& planet : planets) {
    if (planet.getMass() < minMass) {
      minMass = planet.getMass();
    }
  }
  return minMass;
}

int findMaxDiameter(std::vector<Planet> const& planets) {
  int maxDiameter = planets.at(0).getDiameter();
  for (auto const& planet : planets) {
    if (planet.getDiameter() > maxDiameter) {
      maxDiameter = planet.getMass();
    }
  }
  return maxDiameter;
}

int main() {
  size_t planetsCount;
  std::string name;
  int distance, diameter, mass;

  std::cin >> planetsCount;

  std::vector<Planet> planets;

  for (size_t i = 0; i < planetsCount; ++i) {
    std::cin >> name >> distance >> diameter >> mass;
    planets.emplace_back(name, distance, diameter, mass);
  }

  for (auto const& planet : planets) {
    std::cout << planet.toString() << std::endl;
  }
  std::cout << findMinMass(planets) << std::endl;
  std::cout << findMaxDiameter(planets) << std::endl;

  return 0;
}
