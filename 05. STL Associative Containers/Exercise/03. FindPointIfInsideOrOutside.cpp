#include <iostream>
#include <vector>

int main() {
  std::vector<std::pair<int, int> > points;

  for (int x, y, i = 0; i < 3; ++i) {
    std::cin >> x >> y;
    points.emplace_back(x, y);
  }

  std::cout << "Check point is ";

  if (points[2].first <= std::max(points[0].first, points[1].first) &&
      points[2].first >= std::min(points[0].first, points[1].first) &&
      points[2].second <= std::max(points[0].second, points[1].second) &&
      points[2].second >= std::min(points[0].second, points[1].second)) {
    std::cout << "inside" << std::endl;
  } else {
    std::cout << "outside" << std::endl;
  }

  return 0;
}
