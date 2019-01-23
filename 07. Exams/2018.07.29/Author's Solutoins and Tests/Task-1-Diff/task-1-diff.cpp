#include <iostream>
#include <cctype>

int main() {
  using namespace std;
  const int MAX_SIZE = 150;

  char first[MAX_SIZE];
  char second[MAX_SIZE];

  int actualSize;
  cin >> actualSize;

  for (int i = 0; i < actualSize; i++) {
    cin >> first[i];
  }

  for (int i = 0; i < actualSize; i++) {
    cin >> second[i];
  }

  int numDifferences = 0;

  for (int i = 0; i < actualSize; i++) {
    char a = first[i];
    char b = second[i];
    if (a == b) {
      cout << a;
    } else if (toupper(a) == toupper(b)) {
      /// NOTE: toupper doesn't change the value if it is not a letter
      cout << (char) toupper(a);
    } else {
      numDifferences++;
      cout << '!';
    }
  }
  cout << endl;

  cout << numDifferences << endl;

  return 0;
}
