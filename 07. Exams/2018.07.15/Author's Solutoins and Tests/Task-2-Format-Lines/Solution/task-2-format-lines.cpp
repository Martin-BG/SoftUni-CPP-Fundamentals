#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    ostringstream allText;

    string line;
    getline(cin, line);
    while (line != "###") {
        // combine all text in a single string, which we will later read with a stream to get rid of
        // unnecessary whitespace characters
        allText << " " << line;

        getline(cin, line);
    }

    int lineWidth;
    cin >> lineWidth;

    istringstream allTextIn(allText.str());

    ostringstream output;
    string word;
    // first word always goes into output, regardless of line width
    allTextIn >> word;
    output << word;
    int currentWidth = word.size();

    while (allTextIn >> word) {
        int spaceAndWordSize = 1 + word.size();
        if (currentWidth + spaceAndWordSize <= lineWidth) {
            output << " " << word;
            currentWidth += spaceAndWordSize;
        } else {
            // end current line - no more room for a space and the next word, move word to next line
            // NOTE: moving word to next line without checking its size is safe, because each line
            // has at least one word on it, regardless of line width
            output << endl << word;
            currentWidth = word.size();
        }
    }

    cout << output.str();

    return 0;
}
