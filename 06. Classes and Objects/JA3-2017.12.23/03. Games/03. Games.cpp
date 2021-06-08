#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>

class Player {
  const std::string name;
  int score = 0;
public:
  explicit Player(std::string name) :
      name(std::move(name)) { }

  void win() {
    ++score;
  }

  int getScore() const {
    return score;
  }
};

class Team {
  const std::string name;
  const std::vector<Player*> members;
public:
  Team(std::string name, std::vector<Player*> members) :
      name(std::move(name)), members(std::move(members)) { }

  void win() {
    for (auto& pPlayer : members) {
      pPlayer->win();
    }
  }
};

int main() {
  std::istream::sync_with_stdio(false);
  std::ostream::sync_with_stdio(false);

  std::map<std::string, Player> players{ };
  std::unordered_map<std::string, Team> teams{ };

  size_t teamsCount;
  std::cin >> teamsCount;
  for (size_t i = 0; i < teamsCount; ++i) {
    std::string teamName;
    size_t membersCount;
    std::cin >> teamName >> membersCount;
    std::vector<Player*> members{ };
    for (size_t j = 0; j < membersCount; ++j) {
      std::string playerName;
      std::cin >> playerName;
      if (players.find(playerName) == players.cend()) {
        players.emplace(playerName, playerName);
      }
      members.emplace_back(&players.at(playerName));
    }
    teams.emplace(teamName, Team{ teamName, members });
  }

  size_t gamesCount;
  std::cin >> gamesCount;
  for (size_t i = 0; i < gamesCount; ++i) {
    std::string winnerTeamName;
    std::cin >> winnerTeamName;
    teams.at(winnerTeamName).win();
  }

  for (const auto& kvp : players) {
    std::cout << kvp.second.getScore() << " ";
  }

  return 0;
}
