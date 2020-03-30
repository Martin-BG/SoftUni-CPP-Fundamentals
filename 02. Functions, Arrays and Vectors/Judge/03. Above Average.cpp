#include <iostream>

void readArrayFromConsole(int*& arr, int& length);

int calculateAverage(const int* arr, int length);

int main() {
  int length;
  int* arr;

  readArrayFromConsole(arr, length);
  int average = calculateAverage(arr, length);

  for (int i = 0; i < length; ++i) {
    if (arr[i] >= average) {
      std::cout << arr[i] << " ";
    }
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}

int calculateAverage(const int* arr, int length) {
  long long sum{ 0L };
  for (int i = 0; i < length; ++i) {
    sum += arr[i];
  }

  return (int) (sum / length);
}

void readArrayFromConsole(int*& arr, int& length) {
  std::cin >> length;
  arr = new int[length];

  for (int number, i = 0; i < length; ++i) {
    std::cin >> number;
    arr[i] = number;
  }
}
