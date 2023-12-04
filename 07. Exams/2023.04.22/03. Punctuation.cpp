#include <iostream>
#include <cctype>
#include <map>

int main() {
  std::map<size_t, size_t> punctuationSentences{ };

  std::string essay;
  std::getline(std::cin, essay);

  size_t punctuationChars = 0;
  for (const auto ch: essay) {
    if (ch == '|') {
      punctuationSentences[punctuationChars]++;
      punctuationChars = 0;
    } else if (ispunct(ch)) {
      ++punctuationChars;
    }
  }

  for (const auto [symbols, sentences]: punctuationSentences) {
    std::cout << symbols << " symbol sentences: " << sentences << '\n';
  }

  return 0;
}
