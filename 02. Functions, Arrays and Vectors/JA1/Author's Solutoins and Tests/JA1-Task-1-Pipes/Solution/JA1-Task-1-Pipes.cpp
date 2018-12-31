#include <iostream>
#include <vector>
#include <sstream>
#include <string>

std::vector<int> readPipes(int numPipes) {
    std::vector<int> numbers;

    for (int i = 0; i < numPipes; i++) {
        int currentPipeValue;
        std::cin >> currentPipeValue;
        numbers.push_back(currentPipeValue);
    }

    return numbers;
}

int main() {
    int numPipes;
    std::cin >> numPipes;
    std::vector<int> firstYearValues = readPipes(numPipes);
    std::vector<int> secondYearValues = readPipes(numPipes);

    for (int i = 0; i < firstYearValues.size(); i++) {
        int damagePerYear = firstYearValues[i] - secondYearValues[i];
        int yearsRemaining = secondYearValues[i] / damagePerYear;

        std::cout << yearsRemaining << " ";
    }

    std::cout << std::endl;

    return 0;
}
