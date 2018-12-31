#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <sstream>

class SocialNetwork {
private:
  std::unordered_map<std::string, std::vector<std::string>> byPersonsByProfession; // profession -> persons
  std::unordered_map<std::string, std::unordered_set<std::string>> byFriends; // person -> friends
  std::unordered_map<std::string, std::string> byProfession; // person -> profession
  std::unordered_map<std::string, std::string> byConnection; // person -> group "leader" - Union-Find algorithm

  void updateConnections(std::string const& personA, std::string const& personB) {
    std::string from, to;
    if (this->byFriends[personA].size() > this->byFriends[personB].size()) {
      from = this->byConnection[personB];
      to = this->byConnection[personA];
    } else {
      from = this->byConnection[personA];
      to = this->byConnection[personB];
    }

    for (auto& pair : this->byConnection) {
      if (pair.second == from) {
        pair.second = to;
      }
    }
  }

public:
  void addPerson(std::string const& name, std::string const& profession) {
    this->byPersonsByProfession[profession].emplace_back(name);
    this->byProfession[name] = profession;
    this->byFriends[name] = { };
    this->byConnection[name] = name;
  }

  void makeFriends(std::string const& personA, std::string const& personB) {
    this->byFriends[personA].emplace(personB);
    this->byFriends[personB].emplace(personA);
    this->updateConnections(personA, personB);
  }

  std::set<std::string> suggestFriends(std::string const& forPerson) const {
    std::set<std::string> suggestions;
    std::string profession = this->byProfession.at(forPerson);
    std::string group = this->byConnection.at(forPerson);
    auto const& friends = this->byFriends.at(forPerson);
    for (auto const& person : this->byPersonsByProfession.at(profession)) {
      if (person != forPerson && this->byConnection.at(person) == group && friends.find(person) == friends.end()) {
        suggestions.emplace(person);
      }
    }
    return suggestions;
  }
};

void parsePersons(SocialNetwork& socialNetwork) {
  std::istringstream iss;
  std::string line, name, profession;
  while (getline(std::cin, line) && line != "---") {
    iss.clear();
    iss.str(line);
    iss >> name >> profession;
    socialNetwork.addPerson(name, profession);
  }
}

void parseFriendships(SocialNetwork& socialNetwork) {
  std::istringstream iss;
  std::string line, personA, personB;
  while (getline(std::cin, line) && line != "---") {
    iss.clear();
    iss.str(line);
    iss >> personA >> personB;
    socialNetwork.makeFriends(personA, personB);
  }
}

std::string processSuggestionRequests(const SocialNetwork& socialNetwork) {
  std::ostringstream oss;
  std::string person;
  while (getline(std::cin, person) && person != "---") {
    auto suggestions = socialNetwork.suggestFriends(person);
    if (suggestions.empty()) {
      oss << '-';
    } else {
      for (auto const& suggestion : suggestions) {
        oss << suggestion << ' ';
      }
    }
    oss << std::endl;
  }
  return oss.str();
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  SocialNetwork socialNetwork{ };

  parsePersons(socialNetwork);
  parseFriendships(socialNetwork);

  std::string result = processSuggestionRequests(socialNetwork);

  std::cout << result;

  return 0;
}
