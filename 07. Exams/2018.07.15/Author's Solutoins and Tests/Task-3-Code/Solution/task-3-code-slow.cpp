/// NOTE: this solution is nearly analogous to the solution of Task 4 - Letters in the exercise on Associative Containers, Classes and Objects, however:
/// - instead of words (string), we have sequences of numbers (vector<int>)
/// - separators are not non-alphabetical values (!isalpha()) but are entered on the first line of the input (hence if we put them in a set<int> separators, to check if something is a separator we do separators.find(...) != separators.end())
/// - we don't print the "words" ordered alphabetically, just their count
/// - we don't ignore repeated "words" (i.e. if two "words" contain a search value, we need to count both)
/// If you study one of the example inputs, you'll see it is the lowercase ascii codes of the symbols in the example input of the exercise task mentioned earlier

#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

vector<int> readNumbersLine() {
    vector<int> numbers;

    string line;
    getline(cin, line);

    istringstream lineIn(line);

    int number;
    while (lineIn >> number) {
        numbers.push_back(number);
    }

    return numbers;
}

vector<vector<int> > readMessageParts(unordered_set<int> separators) {
    vector<int> message = readNumbersLine();

    vector<vector<int> > messageParts;

    vector<int> currentPart;
    for (size_t i = 0; i < message.size(); i++) {
        int currentValue = message[i];
        bool isSeparator = separators.find(currentValue) != separators.end();
        if (!isSeparator) {
            currentPart.push_back(currentValue);

            if (i == message.size() - 1) {
                messageParts.push_back(currentPart);
            }
        } else {
            if (!currentPart.empty()) {
                messageParts.push_back(currentPart);
            }

            currentPart.clear();
        }
    }

    return messageParts;
}

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    vector<int> separatorValues = readNumbersLine();
    unordered_set<int> separators(separatorValues.begin(), separatorValues.end());

    vector<vector<int> > messageParts = readMessageParts(separators);

    ostringstream output;

    int searchValue;
    cin >> searchValue;
    while (searchValue != 0) {
        // NOTE: directly accessing search value - if no entry for it, we will get a default value for int - which is 0
        int partsContainingSearch = 0;

        for (auto part : messageParts) {
            if (find(part.begin(), part.end(), searchValue) != part.end()) {
                partsContainingSearch++;
            }
        }

        output << partsContainingSearch << endl;

        cin >> searchValue;
    }

    cout << output.str();

    return 0;
}
