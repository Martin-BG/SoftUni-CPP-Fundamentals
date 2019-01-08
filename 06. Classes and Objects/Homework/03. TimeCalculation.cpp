#include <iostream>

static const int MINUTES_IN_HOUR = 60;
static const int SECONDS_IN_MINUTE = 60;

class TimeConverter {
private:
  size_t hours;
  size_t minutes;
  size_t seconds;

  void init() {
    this->seconds += (this->hours * MINUTES_IN_HOUR + this->minutes) * SECONDS_IN_MINUTE;
    this->minutes = this->seconds / SECONDS_IN_MINUTE;
    this->hours = this->seconds / (MINUTES_IN_HOUR * SECONDS_IN_MINUTE);
  }

public:
  TimeConverter(size_t hours, size_t minutes, size_t seconds) : hours(hours), minutes(minutes), seconds(seconds) {
    this->init();
  }

  size_t getHours() const {
    return this->hours;
  }

  size_t getMinutes() const {
    return this->minutes;
  }

  size_t getSeconds() const {
    return this->seconds;
  }
};

int main() {
  size_t hours, minutes, seconds;
  std::cin >> hours >> minutes >> seconds;

  TimeConverter timeConverter{hours, minutes, seconds};

  std::cout << timeConverter.getHours() << std::endl
            << timeConverter.getMinutes() << std::endl
            << timeConverter.getSeconds() << std::endl;

  return 0;
}
