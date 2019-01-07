#include <iostream>

class Rectangle {
private:
  double sideA;
  double sideB;
public:
  Rectangle(double sideA, double sideB) : sideA(sideA), sideB(sideB) { }

  double perimeter() const {
    return (this->sideA + this->sideB) * 2.0;
  }

  double area() const {
    return this->sideA * this->sideB;
  }
};

int main() {
  double sideA, sideB;
  std::cin >> sideA >> sideB;

  Rectangle rectangle{ sideA, sideB };

  std::cout << rectangle.area() << std::endl << rectangle.perimeter() << std::endl;

  return 0;
}
