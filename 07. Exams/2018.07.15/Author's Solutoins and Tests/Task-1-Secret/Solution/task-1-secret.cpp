#include <iostream>
#include <cctype>

int main() {
    using namespace std;

    int sum = 0;
    char inputChar;
    cin >> inputChar;
    while (inputChar != '.') {
        if (isdigit(inputChar)) {
            sum += inputChar - '0';
        }

        cin >> inputChar;
    }

    if (isalpha(sum)) {
        cout << (char)sum << endl;
    } else {
        cout << sum << endl;
    }

    return 0;
}
