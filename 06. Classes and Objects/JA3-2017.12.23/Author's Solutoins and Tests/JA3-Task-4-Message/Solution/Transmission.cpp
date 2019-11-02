#include <set>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class WordGroup {
    vector<string> words;
    bool sorted;

    void sortWords() {
        sort(this->words.begin(), this->words.end());
        this->sorted = true;
    }
public:
    WordGroup() : sorted(false) {}

    void addWord(const string& word) {
        words.push_back(word);
        this->sorted = false;
    }

    string getSortedWord(int index) {
        if (!this->sorted) {
            this->sortWords();
        }

        return this->words[index];
    }
};

int main() {
    int totalWords = 0;
    map<string, int> wordCounts;
    string word;
    cin >> word;
    while (word != ".") {
        wordCounts[word]++;
        totalWords++;
        cin >> word;
    }

    map<int, WordGroup> wordGroupsByCount;
    for (auto wordCountPair : wordCounts) {
        wordGroupsByCount[wordCountPair.second].addWord(wordCountPair.first);
    }

    int queries;
    cin >> queries;

    ostringstream outputStream;
    for (int i = 0; i < queries; i++) {
        int occurrenceCount, wordIndex;
        cin >> occurrenceCount >> wordIndex;

        auto groupIter = wordGroupsByCount.find(occurrenceCount);
        if (groupIter != wordGroupsByCount.end()) {
            outputStream << groupIter->second.getSortedWord(wordIndex) << endl;
        } else {
            outputStream << "." << endl;
        }
    }

    cout << outputStream.str();

    return 0;
}
