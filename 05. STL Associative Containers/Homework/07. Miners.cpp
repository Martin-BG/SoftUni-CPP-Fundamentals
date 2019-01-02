#include <iostream>
#include <map>
#include <vector>
#include <sstream>

int main() {
  std::map<std::string, size_t> resourceQuantity;
  std::vector<std::string> resourcesInOrder;

  std::string resource;
  size_t quantity;
  while (std::cin >> resource && resource != "stop") {
    std::cin >> quantity;
    if (resourceQuantity.find(resource) == resourceQuantity.end()) {
      resourcesInOrder.emplace_back(resource);
    }
    resourceQuantity[resource] += quantity;
  }

  for (auto const& res : resourcesInOrder) {
    std::cout << res << " -> " << resourceQuantity[res] << std::endl;
  }

  return 0;
}
