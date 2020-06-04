#include <iostream>
#include <vector>
#include <algorithm>

class Car {
  const std::string make;
  int year = 2000;
  double price = 1000.0;

  void setYear(const int carYear) {
    if (carYear >= 1950 && carYear <= 2019) {
      year = carYear;
    }
  }

  void setPrice(const double carPrice) {
    if (carPrice > 0.0) {
      price = carPrice;
    }
  }

public:
  Car(std::string make, const int year, const double price) :
      make(std::move(make)) {
    setPrice(price);
    setYear(year);
  }

  double getPrice() const {
    return price;
  }

  const std::string& getMake() const {
    return make;
  }

  int getYear() const {
    return year;
  }
};

class AutoHouse {
  double capital = 10000.0;
  double overchargeTax = 500.0;
  std::vector<Car> cars{ };

  void setCapital(double startingCapital) {
    if (startingCapital > 0.0) {
      capital = startingCapital;
    }
  }

  void setOverchargeTax(double overcharge) {
    if (overcharge > 0.0) {
      overchargeTax = overcharge;
    }
  }

public:
  AutoHouse(double capital, double overchargeTax) {
    setCapital(capital);
    setOverchargeTax(overchargeTax);
  }

  void sellAllCars() {
    for (const Car& car : cars) {
      capital += car.getPrice() + overchargeTax;
    }
    cars.clear();
  }

  void buyCar(Car car) {
    if (car.getPrice() <= capital) {
      capital -= car.getPrice();
      cars.emplace_back(std::move(car));
    }
  }

  double getCapital() const {
    return capital;
  }

  friend void showAllCars(const AutoHouse& autoHouse);
};

void tryBuyCar(AutoHouse& autoHouse);

void trySellAllCars(AutoHouse& autoHouse);

std::vector<int> getCommands();

int main() {
  double initialCapital, taxOvercharge;
  std::cin >> initialCapital >> taxOvercharge;

  AutoHouse autoHouse{ initialCapital, taxOvercharge };

  const std::vector<int> commands = getCommands();

  for (const int command : commands) {
    switch (command) {
    case 1 :
      showAllCars(autoHouse);
      break;
    case 2 :
      trySellAllCars(autoHouse);
      break;
    case 3 :
      tryBuyCar(autoHouse);
      break;
    default:
      throw std::invalid_argument("Unknown command " + std::to_string(command));
    }
  }
  return 0;
}

std::vector<int> getCommands() {
  std::vector<int> commands{ };

  int command;
  while (std::cin >> command && command != 0) {
    commands.emplace_back(command);
  }

  //This requirement is not mentioned in task description, but is required for Judge
  std::sort(commands.begin(), commands.end(), std::greater<int>());

  return commands;
}

void showAllCars(const AutoHouse& autoHouse) {
  for (const Car& car : autoHouse.cars) {
    std::cout << "Make : " << car.getMake() << std::endl
              << "Year : " << car.getYear() << std::endl
              << "Price : " << car.getPrice() << std::endl;
  }
}

void trySellAllCars(AutoHouse& autoHouse) {
  std::cout << "Capital before sell : " << autoHouse.getCapital() << std::endl;
  autoHouse.sellAllCars();
  std::cout << "Capital after sell : " << autoHouse.getCapital() << std::endl;
}

void tryBuyCar(AutoHouse& autoHouse) {
  std::string make;
  int year;
  double price;
  std::cin >> make >> year >> price;
  autoHouse.buyCar(Car{ make, year, price });
}
