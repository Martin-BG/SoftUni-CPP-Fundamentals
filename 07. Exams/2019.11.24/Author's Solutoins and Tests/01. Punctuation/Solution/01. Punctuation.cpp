#include <iostream>
#include <string>
#include <cctype>
#include <map>

int main() {
  std::string input;
  std::getline(std::cin, input);

  std::map<int, int> punctSentCounter;
  int currPunctCount = 0;

  for (const char letter : input) {
    if ('|' == letter) {
      ++punctSentCounter[currPunctCount];
      currPunctCount = 0;
      continue;
    }

    if (ispunct(letter)) {
      ++currPunctCount;
    }
  }

  std::map<int, int>::const_iterator it;
  for (it = punctSentCounter.begin(); it != punctSentCounter.end(); ++it) {
    std::cout << it->first << " symbol sentences: " << it->second << '\n';
  }

  return 0;
}
