#include <iostream>
#include <algorithm>

void readArrayFromConsole(int*& arr, int& length);

int getMinAbsDif(int* arr, int length);

int main() {
  int length;
  int* arr;

  readArrayFromConsole(arr, length);

  std::cout << getMinAbsDif(arr, length) << std::endl;

  delete[] arr;

  return 0;
}

int getMinAbsDif(int* arr, int length) {
  if (length <= 1) {
    return 0;
  }

  std::sort(arr, arr + length);

  int min = INT_MAX;
  for (int i = 1; i < length; ++i) {
    int dif = abs(arr[i - 1] - arr[i]);
    if (dif < min) {
      min = dif;
    }
  }

  return min;
}

void readArrayFromConsole(int*& arr, int& length) {
  std::cin >> length;
  arr = new int[length];

  for (int number, i = 0; i < length; ++i) {
    std::cin >> number;
    arr[i] = number;
  }
}
