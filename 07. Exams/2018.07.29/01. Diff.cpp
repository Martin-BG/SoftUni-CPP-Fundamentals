#include <iostream>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  size_t length;
  std::string first, second;

  std::cin >> length >> first >> second;

  int differences = 0;
  std::string diff(length, '!');
  for (size_t i = 0; i < length; ++i) {
    if (toupper(first[i]) == toupper(second[i])) {
      if (isupper(first[i]) || isupper(second[i])) {
        diff[i] = static_cast<char>(toupper(first[i]));
      } else {
        diff[i] = first[i];
      }
    } else {
      ++differences;
    }
  }

  std::cout << diff << std::endl << differences << std::endl;

  return 0;
}
