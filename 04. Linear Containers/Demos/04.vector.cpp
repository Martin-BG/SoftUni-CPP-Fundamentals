#include <iostream>
#include <vector>
#include <list>
#include <sstream>

int main() {
    // Reads numbers until "end" is entered, then shows the maximum abs difference between any two elements

    std::vector<int> numbers;

    std::string itemString;
    std::cin >> itemString;
    while (itemString != "end") {
        std::stringstream itemParser(itemString);
        int itemValue;
        itemParser >> itemValue;

        numbers.push_back(itemValue);

        std::cin >> itemString;
    }

    int maxAbsDifference = 0;
    for (int a = 0; a < numbers.size(); a++) {
        for (int b = 0; b < numbers.size(); b++) {
            int currentDiff = numbers[a] - numbers[b];
            if (currentDiff > maxAbsDifference) {
                maxAbsDifference = currentDiff;
            }
        }
    }

    std::cout << "max abs difference: " << maxAbsDifference << std::endl;

    return 0;
}
