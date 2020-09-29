#include <iostream>

int* readArrayFromConsole(int length);

void findLongestSequence(const int* arr, int length, int& index, int& lengthMax);

int main() {
  int length;
  std::cin >> length;
  const int* arr = readArrayFromConsole(length);

  int longestStartIndex, longestLength;
  findLongestSequence(arr, length, longestStartIndex, longestLength);

  for (int i = longestStartIndex; i < longestStartIndex + longestLength; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}

void findLongestSequence(const int* arr, const int length, int& index, int& lengthMax) {
  index = 0;
  lengthMax = 1;

  for (int lengthCurrent = 1, prev = arr[0], i = 1; i < length; prev = arr[i], ++i) {
    if (prev != arr[i]) {
      lengthCurrent = 0;
    }

    if (++lengthCurrent >= lengthMax) {
      lengthMax = lengthCurrent;
      index = i - lengthCurrent + 1;
    }
  }
}

int* readArrayFromConsole(const int length) {
  int* arr = new int[length];

  for (int i = 0; i < length; ++i) {
    std::cin >> arr[i];
  }

  return arr;
}
