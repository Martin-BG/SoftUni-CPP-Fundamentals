#include <iostream>

void readArrayFromConsole(int*& arr, int& length);

bool areEqual(const int* arr1, int length1, const int* arr2, int length2);

int main() {
  int length1, length2;
  int* arr1;
  int* arr2;

  readArrayFromConsole(arr1, length1);
  readArrayFromConsole(arr2, length2);

  std::cout << (areEqual(arr1, length1, arr2, length2) ? "equal" : "not equal") << std::endl;

  delete[] arr1;
  delete[] arr2;

  return 0;
}

bool areEqual(const int* arr1, int length1, const int* arr2, int length2) {
  bool areEqual = length1 == length2;
  if (areEqual) {
    for (int i = 0; i < length1; ++i) {
      if (arr1[i] != arr2[i]) {
        areEqual = false;
        break;
      }
    }
  }

  return areEqual;
}

void readArrayFromConsole(int*& arr, int& length) {
  std::cin >> length;
  arr = new int[length];

  for (int number, i = 0; i < length; ++i) {
    std::cin >> number;
    arr[i] = number;
  }
}
