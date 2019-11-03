#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>

using Teams = std::unordered_map<std::string, std::unordered_set<std::string>>;
using Players = std::map<std::string, int>;

Teams parseTeams(std::istream& in);

Players getPlayersFromTeams(Teams const& teams);

void processRounds(std::istream& in, Teams const& teams, Players& players);

void printPlayerScores(std::ostream& out, const Players& players);

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  Teams teams = parseTeams(in);
  Players players = getPlayersFromTeams(teams);

  processRounds(in, teams, players);

  printPlayerScores(out, players);

  return 0;
}

void printPlayerScores(std::ostream& out, const Players& players) {
  for (const auto& player : players) {
    out << player.second << " ";
  }
  out << std::endl;
}

void processRounds(std::istream& in, Teams const& teams, Players& players) {
  size_t rounds;
  in >> rounds;
  while (rounds-- > 0) {
    std::string victoriousTeam;
    in >> victoriousTeam;
    for (const auto& player: teams.at(victoriousTeam)) {
      ++players[player];
    }
  }
}

Teams parseTeams(std::istream& in) {
  Teams teams{ };

  size_t teamsCount;
  in >> teamsCount;
  while (teamsCount-- > 0) {
    std::string teamName;
    in >> teamName;
    size_t playersCount;
    in >> playersCount;
    while (playersCount-- > 0) {
      std::string playerName;
      in >> playerName;
      teams[teamName].emplace(playerName);
    }
  }

  return teams;
}

Players getPlayersFromTeams(Teams const& teams) {
  Players players{ };

  for (auto const& team : teams) {
    for (auto const& player : team.second) {
      players[player] = 0;
    }
  }

  return players;
}
