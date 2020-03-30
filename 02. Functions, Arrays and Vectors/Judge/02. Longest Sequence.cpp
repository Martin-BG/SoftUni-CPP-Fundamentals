#include <iostream>

void readArrayFromConsole(int*& arr, int& length);

void findLongestSequence(const int* arr, int length, int& index, int& lengthMax);

int main() {
  int length;
  int* arr;

  readArrayFromConsole(arr, length);

  int longestStartIndex, longestLength;
  findLongestSequence(arr, length, longestStartIndex, longestLength);

  for (int i = longestStartIndex; i < longestStartIndex + longestLength; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}

void findLongestSequence(const int* arr, int length, int& index, int& lengthMax) {
  index = 0;
  lengthMax = 1;

  for (int lengthCurrent = 1, prev = arr[0], i = 1; i < length; ++i) {
    if (prev != arr[i]) {
      lengthCurrent = 0;
    }

    if (++lengthCurrent >= lengthMax) {
      lengthMax = lengthCurrent;
      index = i - lengthMax + 1;
    }

    prev = arr[i];
  }
}

void readArrayFromConsole(int*& arr, int& length) {
  std::cin >> length;
  arr = new int[length];

  for (int number, i = 0; i < length; ++i) {
    std::cin >> number;
    arr[i] = number;
  }
}
