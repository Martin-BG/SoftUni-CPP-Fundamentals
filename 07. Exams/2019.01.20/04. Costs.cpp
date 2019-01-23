#include <iostream>
#include <vector>
#include <unordered_map>

static const char* const SALARY = "Remaining Salary";
static const char* const COSTS = "All costs";
static const char* const ENERGY = "Energy";
static const char* const WATER = "Water";
static const char* const GAS = "Gas";
static const char* const DAILY_MONEY = "Money for one day";

int main() {
  using Category = std::string;
  using CostForOne = double;
  using Total = double;

  const std::vector<Category> outputOrder{
      WATER,
      GAS,
      ENERGY,
      COSTS,
      SALARY,
      DAILY_MONEY
  };

  const std::vector<std::pair<Category, CostForOne>> inputOrder{
      { WATER,  1.65 },
      { GAS,    0.09 },
      { ENERGY, 0.13 }, // Daily energy
      { COSTS,  1.00 }, // Rent
      { ENERGY, 0.07 }, // Night energy
      { SALARY, 1.00 }, // Mother Salary
      { SALARY, 1.00 }, // Father Salary
  };

  std::unordered_map<Category, Total> budget{
      { COSTS, 40.0 } // Needed for child
  };

  for (auto& pair:inputOrder) {
    double amount;
    std::cin >> amount;
    budget[pair.first] += amount * pair.second;
  }

  budget[COSTS] += budget[WATER] + budget[GAS] + budget[ENERGY];
  budget[SALARY] -= budget[COSTS];
  budget[DAILY_MONEY] = budget[SALARY] / 30;

  for (auto const& category : outputOrder) {
    std::cout << category << " : " << budget[category] << std::endl;
    if (category == SALARY && budget[SALARY] < 0.0) {
      std::cout << "You should find new job !" << std::endl;
    }
  }

  return 0;
}
