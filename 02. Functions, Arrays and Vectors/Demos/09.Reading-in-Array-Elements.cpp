#include<iostream>
using namespace std;

const int MaxCount = 100;

int main() {
    int numbers[MaxCount] = {};
    int actualCount;
    cin >> actualCount;

    // Note: reading in a number for the array size is also supported by most C++ compilers,
    // but is not officially supported by C++ standards (it is part of the C99 standard)
    //int numbers[actualCount];

    for (int i = 0; i < actualCount; i++) {
        cin >> numbers[i];
    }

    return 0;
}
