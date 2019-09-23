#include<iostream>
#include<string>
#include<vector>

#pragma GCC optimize ("O3")

typedef std::vector<int> BusArrivalTimes;
typedef std::vector<int>::size_type Index;

Index getSoonestBusIndex(BusArrivalTimes const& busArrivalTimes, int trainArrivalTime);

std::vector<int> getBusArrivalTimes();

int getTrainArrivalTime();

int convertToMinutes(int time);

int main() {
  // Tweaks for faster cin execution
  std::istream::sync_with_stdio(false);
  std::cin.tie(nullptr);

  const BusArrivalTimes busArrivalTimes = getBusArrivalTimes();
  const int trainArrivalTime = getTrainArrivalTime();
  const Index index = getSoonestBusIndex(busArrivalTimes, trainArrivalTime);

  std::cout << index << std::endl;

  return 0;
}

Index getSoonestBusIndex(BusArrivalTimes const& busArrivalTimes, const int trainArrivalTime) {
  int minWaitTime = -1;

  Index index = 0;
  for (Index i = 0; i < busArrivalTimes.size(); i++) {
    int min = busArrivalTimes.at(i);
    if (trainArrivalTime < min) {
      continue;
    }

    if (minWaitTime == -1 || trainArrivalTime - min < minWaitTime) {
      minWaitTime = trainArrivalTime - min;
      index = i + 1;
    }
  }
  return index;
}

std::vector<int> getBusArrivalTimes() {
  Index busCount;
  std::cin >> busCount;
  std::vector<int> busArrivalTimes(busCount);

  int busArrivalTime;
  for (Index bus = 0; bus < busCount; ++bus) {
    std::cin >> busArrivalTime;
    busArrivalTimes[bus] = (convertToMinutes(busArrivalTime));
  }
  return busArrivalTimes;
}

int getTrainArrivalTime() {
  int trainArrivalTime;
  std::cin >> trainArrivalTime;
  trainArrivalTime = convertToMinutes(trainArrivalTime);
  return trainArrivalTime;
}

int convertToMinutes(const int time) {
  return (time / 100) * 60 + (time % 100);
}
