#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <sstream>

class SocialNetwork {
private:
  std::unordered_map<std::string, std::vector<std::string>> professionPeople; // profession -> people
  std::unordered_map<std::string, std::unordered_set<std::string>> personFriends; // person -> friends
  std::unordered_map<std::string, std::string> personProfession; // person -> profession
  std::unordered_map<std::string, size_t> personGroup; // person -> groupId - Union-Find algorithm
  size_t nextGroup = 0;

  void updateConnections(std::string const& personA, std::string const& personB) {
    size_t from, to;
    if (this->personFriends[personA].size() > this->personFriends[personB].size()) {
      from = this->personGroup[personB];
      to = this->personGroup[personA];
    } else {
      from = this->personGroup[personA];
      to = this->personGroup[personB];
    }

    if (from == to) {
      return;
    }

    for (auto& pair : this->personGroup) {
      if (pair.second == from) {
        pair.second = to;
      }
    }
  }

public:
  void addPerson(std::string const& name, std::string const& profession) {
    this->professionPeople[profession].emplace_back(name);
    this->personProfession[name] = profession;
    this->personFriends[name] = { };
    this->personGroup[name] = this->nextGroup++;
  }

  void makeFriends(std::string const& personA, std::string const& personB) {
    this->personFriends[personA].emplace(personB);
    this->personFriends[personB].emplace(personA);
    this->updateConnections(personA, personB);
  }

  std::set<std::string> suggestFriends(std::string const& forPerson) const {
    std::set<std::string> suggestions;
    std::string profession = this->personProfession.at(forPerson);
    size_t group = this->personGroup.at(forPerson);
    auto const& friends = this->personFriends.at(forPerson);
    for (auto const& person : this->professionPeople.at(profession)) {
      if (person != forPerson && this->personGroup.at(person) == group && friends.find(person) == friends.end()) {
        suggestions.emplace(person);
      }
    }
    return suggestions;
  }
};

void parsePeople(SocialNetwork& socialNetwork) {
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

  SocialNetwork socialNetwork;

  parsePeople(socialNetwork);
  parseFriendships(socialNetwork);

  std::string result = processSuggestionRequests(socialNetwork);

  std::cout << result;

  return 0;
}
