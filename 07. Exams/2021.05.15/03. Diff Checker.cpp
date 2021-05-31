#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
  size_t size;
  std::cin >> size;

  std::vector<char> first(size);
  std::vector<char> second(size);
  std::vector<char> dif(size);

  std::copy_n(std::istream_iterator<char>(std::cin >> std::ws), size, first.begin());
  std::copy_n(std::istream_iterator<char>(std::cin >> std::ws), size, second.begin());

  for (size_t i = 0; i < size; ++i) {
    const char firstChar = first[i];
    const char secondChar = second[i];
    char difChar = '!';
    if (firstChar == secondChar) {
      difChar = firstChar;
    } else if (toupper(firstChar) == toupper(secondChar)) {
      difChar = char(toupper(firstChar));
    }
    dif[i] = difChar;
  }

  std::copy(dif.cbegin(), dif.cend(), std::ostream_iterator<char>(std::cout, ""));
  std::cout << std::endl << std::count(dif.cbegin(), dif.cend(), '!');

  return 0;
}
