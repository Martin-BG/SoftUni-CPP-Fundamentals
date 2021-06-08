#include<iostream>
#include "BigInt.h"

int getSumOfDigits(const std::string&);

int charToInt(char ch);

int main() {
  std::string start, end;
  std::cin >> start >> end;

  BigInt startNum(start);
  BigInt endNum(end);

  if (charToInt(start.back()) % 5 != 0) {
    startNum += BigInt((10 - charToInt(start.back())) % 5);
  }

  while (getSumOfDigits(startNum.getDigits()) % 9 != 0) {
    startNum += BigInt(5);
  }

  for (BigInt i = startNum; i < endNum; i += 45) {
    std::cout << i << std::endl;
  }

  return 0;
}

int charToInt(const char ch) {
  return ch - '0';
}

int getSumOfDigits(const std::string& digits) {
  int sum = 0;
  for (char digit : digits) {
    sum += charToInt(digit);
  }
  return sum;
}
