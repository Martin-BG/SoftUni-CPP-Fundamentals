#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using Words = std::vector<std::string>;

Words getWords(std::istream& in);

class SentenceShifter {
private:
  Words words;

  void shift(size_t shiftCount) {
    shiftCount %= this->words.size();
    std::rotate(this->words.rbegin(), this->words.rbegin() + shiftCount, this->words.rend());
  }

public:
  SentenceShifter(Words words, size_t shiftCount) :
      words(std::move(words)) {
    shift(shiftCount);
  }

  Words getShiftedSentence() {
    return words;
  }
};

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  Words words = getWords(in);
  size_t shiftCount;
  in >> shiftCount;
  SentenceShifter sentenceShifter{ words, shiftCount };

  Words shifted = sentenceShifter.getShiftedSentence();

  for (auto const& word : shifted) {
    out << word << std::endl;
  }

  return 0;
}

Words getWords(std::istream& in) {
  std::string sentence;
  std::getline(in, sentence);
  std::istringstream iss{ sentence };
  Words words{ std::istream_iterator<std::string>{ iss },
               std::istream_iterator<std::string>{ }};
  return words;
}
