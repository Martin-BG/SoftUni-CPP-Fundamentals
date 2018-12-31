#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int> > arrays;

    for (int i = 0; i < n; i++) {
        vector<int> currentArr;

        for (int col = 0; col < m; col++) {
            int value;
            cin >> value;
            currentArr.push_back(value);
        }

        arrays.push_back(currentArr);
    }

    vector<int> weights;
    for (int i = 0; i < n; i++) {
        int weight;
        cin >> weight;
        weights.push_back(weight);
    }

    int weightedSumArr[m];
    for (int column = 0; column < m; column++) {
        weightedSumArr[column] = 0;
        for (int arrInd = 0; arrInd < arrays.size(); arrInd++) {
            weightedSumArr[column] += arrays[arrInd][column] * weights[arrInd];
        }
    }

    for (int i = 0; i < m; i++) {
        cout << weightedSumArr[i] << " ";
    }

    return 0;
}
