#include <iostream>

int main() {
  int a, b;
  std::cin >> a >> b;

  while (b != 0) {
    int temp = b;
    b = a % b;
    a = temp;
  }

  std::cout << a << std::endl;

  return 0;
}
