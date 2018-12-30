#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers {42, 13, 69};
    // Example: Change each element in the vector by dividing it by 2
    for (vector<int>::iterator i = numbers.begin(); i != numbers.end(); i++) {
        *i /= 2;
    }

    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    vector<string> words {"the", "quick", "purple", "fox"};
    // Example: print each string element and its length
    for (vector<string>::iterator i = words.begin(); i != words.end(); i++) {
        cout << *i << ": " << i->size() << endl;
        // NOTE: the same can be done with this code:
        //cout << *i << ": " << (*i).size() << endl;
    }

    return 0;
}
