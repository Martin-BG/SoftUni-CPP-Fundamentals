#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    cout << endl;
}

void printMultiplied(vector<int> numbers, int multiplier) {
    for (int i = 0; i < numbers.size(); i++) {
        numbers[i] *= multiplier;
    }
    print(numbers);
}

int main() {
    std::vector<int> numbers {1, 2, 3};
    printMultiplied(numbers, 10); /// 10, 20, 30
    print(numbers); /// 1, 2, 3
    return 0;
}
