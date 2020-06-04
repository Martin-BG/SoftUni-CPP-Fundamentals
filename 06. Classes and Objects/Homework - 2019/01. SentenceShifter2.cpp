#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>

class WordsShifter {
  const std::vector<std::string> words;
public:
  explicit WordsShifter(std::vector<std::string> words) : words(std::move(words)) { }

  std::vector<std::string> getShiftedBy(size_t shiftBy) {
    if (this->words.empty()) {
      return std::vector<std::string>{ };
    }

    std::vector<std::string> shiftedWords{ this->words.size() };

    shiftBy %= this->words.size();

    std::rotate_copy(
        this->words.rbegin(),
        this->words.rbegin() + shiftBy,
        this->words.rend(),
        shiftedWords.rbegin());

    return shiftedWords;
  }
};

void printVectorToConsole(std::vector<std::string> shiftedWords);

std::vector<std::string> parseWordsFromConsole();

int main() {
  WordsShifter wordsShifter(parseWordsFromConsole());

  size_t shiftBy;
  std::cin >> shiftBy;

  printVectorToConsole(wordsShifter.getShiftedBy(shiftBy));

  return 0;
}

void printVectorToConsole(std::vector<std::string> shiftedWords) {
  std::move(shiftedWords.begin(), shiftedWords.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

std::vector<std::string> parseWordsFromConsole() {
  std::string line;
  std::getline(std::cin, line);

  std::istringstream iss(line);

  std::vector<std::string> words{
      std::istream_iterator<std::string>{ iss },
      std::istream_iterator<std::string>{ }};

  return words;
}
