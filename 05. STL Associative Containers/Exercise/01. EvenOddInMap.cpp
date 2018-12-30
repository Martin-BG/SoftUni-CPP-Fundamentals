#include <iostream>
#include <map>

int main() {
  std::map<int, std::string> typeMap = {{ 0, "EVEN" },
                                        { 1, "ODD" }};

  int count;
  std::cin >> count;

  std::map<int, std::string> dataMap;
  for (int i = 0; i < count; ++i) {
    dataMap[i] = typeMap[(i % 2)];
  }

  for (int j = 0; j < count; ++j) {
    std::cout << "KEY: " << j << " VALUE: " << dataMap[j] << std::endl;
  }

  return 0;
}
