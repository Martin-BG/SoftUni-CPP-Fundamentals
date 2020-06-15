#include <iostream>
#include <map>
#include <iomanip>

class Sale {
private:
  std::string town;
  std::string product;
  double price;
  double quantity;
  double profit;
public:
  Sale(std::string town, std::string product, double price, double quantity) :
      town(std::move(town)),
      product(std::move(product)),
      price(price),
      quantity(quantity),
      profit(price * quantity) { }

  const std::string& getTown() const {
    return town;
  }

  const std::string& getProduct() const {
    return product;
  }

  double getPrice() const {
    return price;
  }

  double getQuantity() const {
    return quantity;
  }

  double getProfit() const {
    return profit;
  }
};

int main() {
  std::map<std::string, double> profitsByTown{ };

  size_t salesCount;
  std::cin >> salesCount;

  while (salesCount-- != 0) {
    std::string townName, product;
    double price, quantity;
    std::cin >> townName >> product >> price >> quantity;

    profitsByTown[townName] += Sale{ townName, product, price, quantity }.getProfit();
  }

  std::cout << std::fixed << std::setprecision(2);
  for (auto const& pair: profitsByTown) {
    std::cout << pair.first << " -> " << pair.second << std::endl;
  }

  return 0;
}
