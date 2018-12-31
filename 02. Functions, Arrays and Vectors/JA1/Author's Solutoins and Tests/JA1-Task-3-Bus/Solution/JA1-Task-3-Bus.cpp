#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<int> readNumbers(int n) {
    std::vector<int> numbers;

    for (int i = 0; i < n; i++) {
        int currentPipeValue;
        std::cin >> currentPipeValue;
        numbers.push_back(currentPipeValue);
    }

    return numbers;
}

int toMinutes(int militaryTime) {
    return (militaryTime / 100) * 60 + (militaryTime % 100);
}

int calculateMinutesDiff(int militaryHoursA, int militaryHoursB) {
    return toMinutes(militaryHoursA) - toMinutes(militaryHoursB);
}

int main() {
    int n;
    cin >> n;
    vector<int> arrivalTimes = readNumbers(n);

    int trainTime;
    cin >> trainTime;

    int minWaitTimeMinutes = -1;
    for (int arrivalTime : arrivalTimes) {
        int waitTimeMinutes = calculateMinutesDiff(trainTime, arrivalTime);

        if (waitTimeMinutes >= 0 &&
            (minWaitTimeMinutes == -1 || waitTimeMinutes < minWaitTimeMinutes)) {
            minWaitTimeMinutes = waitTimeMinutes;
        }
    }

    cout << minWaitTimeMinutes << endl;

    return 0;
}
