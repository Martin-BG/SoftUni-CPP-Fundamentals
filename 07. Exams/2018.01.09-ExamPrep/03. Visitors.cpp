#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>

class Database {
private:
  std::unordered_set<std::string> ids;
  std::unordered_map<std::string, size_t> nameCount; // name -> count of users with the name
  std::map<size_t, size_t> ageCount; // age -> count of users of that age
public:
  void add(std::string id, const std::string& name, size_t age) {
    if (this->ids.find(id) != this->ids.end()) {
      return;
    }

    this->ids.emplace(id);
    ++this->nameCount[name];
    ++this->ageCount[age];
  }

  size_t countByName(const std::string& name) const {
    auto const& pair = this->nameCount.find(name);
    return (pair == this->nameCount.end()) ? 0 : pair->second;
  }

  size_t countByAgeRange(size_t startAge, size_t endAge) const {
    size_t count = 0;
    auto const& end = this->ageCount.lower_bound(endAge);
    for (auto it = this->ageCount.lower_bound(startAge); it != end; ++it) {
      count += it->second;
    }
    return count;
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Database db;

  std::string command, id, name;
  size_t age, ageStart, ageEnd;

  while ((std::cin >> command) && command != "end") {
    if (command == "entry") {
      std::cin >> id >> name >> age;
      db.add(id, name, age);
    } else if (command == "name") {
      std::cin >> name;
      std::cout << db.countByName(name) << std::endl;
    } else if (command == "age") {
      std::cin >> ageStart >> ageEnd;
      std::cout << db.countByAgeRange(ageStart, ageEnd) << std::endl;
    }
  }

  return 0;
}
