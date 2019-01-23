#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>

using namespace std;

class User {
  string id;
  string profession;
  set<string> friendIds;

public:
  User() {
  }

  User(string id, string profession)
      : id(id), profession(profession) {
  }

  string getId() const {
    return this->id;
  }

  void addFriend(string id) {
    this->friendIds.insert(id);
  }

  set<string> getFriends() const {
    return this->friendIds;
  }

  bool hasFriend(User other) {
    return this->friendIds.find(other.id) != this->friendIds.end();
  }

  bool hasCommonProfessionWith(User other) {
    return this->profession == other.profession;
  }
};

set<string> suggestFriends(string userId, map<string, User> usersById) {
  set<string> suggested;
  set<string> scheduled;

  queue<string> toCheck;

  User user = usersById[userId];

  /// NOTE: we don't really want to check this user's friends (or the user themself),
  /// but the code is easier to read this way and the performance hit isn't that big.
  /// If we want to optimize, we should start from the friends of the user (or even
  /// better - their friends) and mark them as checked
  toCheck.push(userId);
  scheduled.insert(userId);

  while (!toCheck.empty()) {
    string checkId = toCheck.front();
    toCheck.pop();
    User checkUser = usersById[checkId];

    if (checkId != userId && user.hasCommonProfessionWith(checkUser) && !user.hasFriend(checkUser)) {
      suggested.insert(checkUser.getId());
    }

    for (string friendId : checkUser.getFriends()) {
      if (scheduled.find(friendId) == scheduled.end()) {
        toCheck.push(friendId);
        scheduled.insert(friendId);
      }
    }
  }

  return suggested;
}

int main() {
  cin.sync_with_stdio(false);
  cout.sync_with_stdio(false);

  map<string, User> usersById;

  string line;
  while (getline(cin, line) && line != "---") {
    istringstream in(line);

    string id, profession;
    in >> id >> profession;

    usersById[id] = User(id, profession);
  }

  while (getline(cin, line) && line != "---") {
    istringstream in(line);
    string userA, userB;
    in >> userA >> userB;

    usersById[userA].addFriend(userB);
    usersById[userB].addFriend(userA);
  }

  ostringstream output;
  while (getline(cin, line) && line != "---") {
    istringstream in(line);

    string userId;
    in >> userId;

    set<string> suggested = suggestFriends(userId, usersById);

    if (!suggested.empty()) {
      for (string id : suggested) {
        output << id << " ";
      }
    } else {
      output << "-";
    }

    output << endl;
  }

  cout << output.str();

  return 0;
}
