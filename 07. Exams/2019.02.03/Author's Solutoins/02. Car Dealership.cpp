//
//  main.cpp
//  ExcersirceExam
//
//  Created by Iliya Iliev on 19.01.19.
//  Copyright © 2019 Iliya Iliev. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

class Car {
private:

  std::string make = "";

  unsigned int year = 0;

  double price = 0;

public:

  Car() {
    make = "N/A";

    year = 0;

    price = 0.0;
  }

  void SetMake(std::string make) {
    this->make = make;
  }

  void SetYear(unsigned int year) {
    if (year < 1950 || year > 2019) {
      year = 2000;
    }

    this->year = year;
  }

  void SetPrice(double price) {
    if (price <= 0) {
      price = 1000;
    }

    this->price = price;
  }

  std::string GetMake() {
    return this->make;
  }

  unsigned int GetYear() {
    return this->year;
  }

  double GetPrice() {
    return this->price;
  }

  void PrintInfo() {
    std::cout << "Make : " << make << std::endl;
    std::cout << "Year : " << year << std::endl;
    std::cout << "Price : " << price << std::endl;
  }
};

class AutoHouse {

private:

  double initialCapital = 0;

  double overCharge = 0;

public:

  AutoHouse() {
    initialCapital = 0;

    overCharge = 0;

    vecOfCars.clear();
  }

  std::vector<Car> vecOfCars;

  void SetInitialCapital(double initialCapital) {
    if (initialCapital <= 0) {
      initialCapital = 10000;
    }

    this->initialCapital = initialCapital;
  }

  void SetOverCharge(double overCharge) {
    if (overCharge <= 0) {
      overCharge = 500;
    }

    this->overCharge = overCharge;
  }

  double GetInitialCapita() {
    return this->initialCapital;
  }

  double GetOverCharge() {
    return this->overCharge;
  }

  void ShowAllCars() {
    for (unsigned int i = 0; i < vecOfCars.size(); i++) {
      vecOfCars.at(i).PrintInfo();
    }
  }

  void BuyACar() {
    std::string make = "";
    unsigned int year = 0;
    double price = 0.0;

    std::cin >> make;
    std::cin >> year;
    std::cin >> price;

    Car carObj;

    carObj.SetMake(make);
    carObj.SetYear(year);
    carObj.SetPrice(price);

    if (initialCapital >= price) {
      initialCapital -= carObj.GetPrice();
      vecOfCars.push_back(carObj);
    }
  }

  void SellAllCars() {
    std::cout << "Capital before sell : " << initialCapital << std::endl;

    while (!vecOfCars.empty()) {
      for (unsigned int i = 0; i < vecOfCars.size(); i++) {
        initialCapital += (vecOfCars.at(i).GetPrice() + overCharge);

        vecOfCars.erase(vecOfCars.begin() + i);
      }
    }

    std::cout << "Capital after sell : " << initialCapital << std::endl;
  }

};

void Menu() {
  double initialCapital = 0;

  double overCharge = 0;

  int userChoice = -1;

  bool exitWhile = false;

  std::vector<int> vecOfChoices;

  //std::cout << "Welcome: " << std::endl;

  std::cin >> initialCapital;

  std::cin >> overCharge;

  AutoHouse houseObject;

  houseObject.SetInitialCapital(initialCapital);

  houseObject.SetOverCharge(overCharge);

  while (!exitWhile) {
    std::cin >> userChoice;

    switch (userChoice) {
    case 0: {
      exitWhile = true;
    }
      break;
    case 1:
    case 2:
    case 3: {
      vecOfChoices.push_back(userChoice);
    }
      break;

    default:
      break;

    }

  }

  std::sort(vecOfChoices.begin(), vecOfChoices.end(), std::greater<int>());

  for (unsigned int i = 0; i < vecOfChoices.size(); i++) {
    switch (vecOfChoices.at(i)) {
    case 1: {
      houseObject.ShowAllCars();
    }
      break;

    case 2: {
      houseObject.SellAllCars();
    }
      break;

    case 3: {
      houseObject.BuyACar();
    }
      break;

    default:
      break;
    }
  }


}

int main(int argc, const char* argv[]) {
  Menu();
  return 0;
}
