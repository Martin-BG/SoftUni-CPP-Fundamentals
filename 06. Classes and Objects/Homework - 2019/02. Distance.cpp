#include <iostream>
#include <cmath>
#include <iomanip>

class Point {
private:
  double x;
  double y;
public:
  Point(double x, double y) : x(x), y(y) { }

  double distance(Point const& p) {
    return sqrt(pow(this->x - p.x, 2.0) + pow(this->y - p.y, 2.0));
  }
};

int main() {
  double x, y;

  std::cin >> x >> y;
  Point p{ x, y };

  std::cin >> x >> y;
  Point q{ x, y };

  std::cout << std::fixed << std::setprecision(3) << p.distance(q) << std::endl;

  return 0;
}
