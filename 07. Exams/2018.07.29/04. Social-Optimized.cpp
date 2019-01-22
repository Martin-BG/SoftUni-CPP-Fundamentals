#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <vector>
#include <sstream>

class SocialNetwork {
private:
  static const size_t ERROR = 0;

  using PersonId = size_t;
  using ProfessionId = size_t;
  using GroupId = size_t;
  using PersonName = std::string;
  using ProfessionName = std::string;

  GroupId nextGroupId = 0;
  PersonId nextPersonId = 0;
  ProfessionId nextProfessionId = 0;

  std::unordered_map<PersonName, PersonId> peopleIds;
  std::unordered_map<PersonId, PersonName> idsPeople;
  std::unordered_map<ProfessionName, ProfessionId> professionsIds;
  std::unordered_map<ProfessionId, std::vector<PersonId>> professionPeople;
  std::unordered_map<PersonId, std::unordered_set<PersonId>> personFriends;
  std::unordered_map<PersonId, ProfessionId> personProfession;
  std::unordered_map<PersonId, GroupId> personGroup;
  std::unordered_map<GroupId, std::vector<PersonId>> groupPeople;

  GroupId getNextGroupId() {
    return ++this->nextGroupId;
  }

  PersonId getNextPersonId() {
    return ++this->nextPersonId;
  }

  ProfessionId getNextProfessionId() {
    return ++this->nextProfessionId;
  }

  PersonId findPersonId(PersonName const& person) const {
    auto const& it = this->peopleIds.find(person);
    if (it != this->peopleIds.end()) {
      return it->second;
    }
    return ERROR;
  }

  ProfessionId findProfessionId(ProfessionName const& profession) const {
    auto const& it = this->professionsIds.find(profession);
    if (it != this->professionsIds.end()) {
      return it->second;
    }
    return ERROR;
  }

  PersonId addPerson(PersonName const& person) {
    if (this->peopleIds.find(person) == this->peopleIds.end()) {
      ProfessionId id = this->getNextPersonId();
      this->peopleIds.emplace(person, id);
      this->idsPeople.emplace(id, person);
      return id;
    }
    return ERROR;
  }

  ProfessionId addProfession(ProfessionName const& profession) {
    ProfessionId id = this->findProfessionId(profession);
    if (id == ERROR) {
      id = this->getNextProfessionId();
      this->professionsIds.emplace(profession, id);
    }
    return id;
  }

  // Union-Find algorithm
  void updateConnections(PersonId const& personA, PersonId const& personB) {
    GroupId from, to;
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

    for (auto& person : this->groupPeople[from]) {
      this->personGroup[person] = to;
    }

    this->groupPeople[to]
        .insert(this->groupPeople[to].end(), this->groupPeople[from].cbegin(), this->groupPeople[from].cend());

    this->groupPeople.erase(from);
  }

public:
  void addPerson(PersonName const& name, ProfessionName const& profession) {
    PersonId personId = this->addPerson(name);
    if (personId == ERROR) {
      return;
    }
    ProfessionId professionId = this->addProfession(profession);
    this->professionPeople[professionId].emplace_back(personId);
    this->personProfession[personId] = professionId;
    this->personFriends[personId] = { };
    GroupId groupId = this->getNextGroupId();
    this->personGroup[personId] = groupId;
    this->groupPeople[groupId] = { personId };
  }

  void makeFriends(PersonName const& personA, PersonName const& personB) {
    PersonId firstId = this->findPersonId(personA);
    PersonId secondId = this->findPersonId(personB);
    if (firstId == secondId || firstId == ERROR || secondId == ERROR) {
      return;
    }
    this->personFriends[firstId].emplace(secondId);
    this->personFriends[secondId].emplace(firstId);
    this->updateConnections(firstId, secondId);
  }

  std::set<std::string> suggestFriends(PersonName const& forPerson) const {
    std::set<std::string> suggestions;
    PersonId personId = this->findPersonId(forPerson);
    if (personId != ERROR) {
      GroupId groupId = this->personGroup.at(personId);
      ProfessionId professionId = this->personProfession.at(personId);
      auto const& friends = this->personFriends.at(personId);
      for (auto const& candidateId : this->professionPeople.at(professionId)) {
        if (candidateId != personId &&
            this->personGroup.at(candidateId) == groupId &&
            friends.find(candidateId) == friends.end()) {
          suggestions.emplace(this->idsPeople.at(candidateId));
        }
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
