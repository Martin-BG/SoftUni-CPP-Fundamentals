#include <string>
#include <iostream>
#include <vector>

static const char* const DELIMITERS = ".,;!? ";

template<class Container>
void splitString(std::string const& str,
                 Container& cont,
                 std::string const& delimiters = DELIMITERS) {
  size_t current, previous = 0;
  current = str.find_first_of(delimiters);
  while (current != std::string::npos) {
    cont.push_back(str.substr(previous, current - previous));
    previous = current + 1;
    current = str.find_first_of(delimiters, previous);
  }
  cont.push_back(str.substr(previous, current - previous));
}

size_t countMatchingChars(std::string const& wordA, std::string const& wordB) {
  size_t matches = 0;
  if (wordA.length() == wordB.length() && wordA[0] == wordB[0]) {
    for (size_t i = 0; i < wordA.length(); i++) {
      if (wordA[i] == wordB[i]) {
        ++matches;
      }
    }
  }
  return matches;
}

template<class Container>
size_t countSimilarWords(Container const& words, std::string const& word, double minPercentage) {
  size_t similarWords = 0, matchingChars;

  for (auto const& w : words) {
    matchingChars = countMatchingChars(w, word);
    if (matchingChars > 0 && 100.0 * matchingChars / w.length() >= minPercentage) {
      ++similarWords;
    }
  }
  return similarWords;
}

int main() {
  std::string text, word;
  double percentage;
  std::vector<std::string> words;

  getline(std::cin, text);
  std::cin >> word >> percentage;

  splitString(text, words);

  size_t similarWords = countSimilarWords(words, word, percentage);

  std::cout << similarWords << std::endl;

  return 0;
}
