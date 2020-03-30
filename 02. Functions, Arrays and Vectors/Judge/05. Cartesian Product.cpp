#include <iostream>

void readArrayFromConsole(int*& arr, int& length);

int main() {
  int length;
  int* arr;

  readArrayFromConsole(arr, length);

  for (int i = 0; i < length; ++i) {
    for (int j = 0; j < length; ++j) {
      std::cout << (long long) arr[i] * arr[j] << " ";
    }
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}

void readArrayFromConsole(int*& arr, int& length) {
  std::cin >> length;
  arr = new int[length];

  for (int number, i = 0; i < length; ++i) {
    std::cin >> number;
    arr[i] = number;
  }
}
