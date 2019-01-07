#include <iostream>
#include <cmath>

class Point {
private:
  double x;
  double y;
public:
  Point(double x, double y) : x(x), y(y) { }

  static double distance(Point const& p, Point const& q) {
    return sqrt(pow(q.x - p.x, 2.0) + pow(q.y - p.y, 2.0));
  }
};

int main() {
  double x, y;

  std::cin >> x >> y;
  Point p{ x, y };

  std::cin >> x >> y;
  Point q{ x, y };

  std::cout << Point::distance(p, q) << std::endl;

  return 0;
}
