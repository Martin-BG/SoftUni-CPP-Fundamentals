#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<double> getSquareRoots(int from, int to) {
    vector<double> roots;
    for (int i = from; i <= to; i++) {
        roots.push_back(sqrt(i));
    }

    return roots;
}

void print(vector<double> numbers) {
    for (int number : numbers) {
        cout << number << " "
    }
    cout << endl;
}

int main() {
    print (getSquareRoots(4, 25));
    return 0;
}
