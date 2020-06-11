#include <iostream>
#include <string>
#include <sstream>
#include <list>

enum GarbageType {
  GLASS = 0,
  METAL,
  PLASTIC,

  GARBAGE_TYPES,

  UNKNOWN = 255
};

enum class GarbageDir {
  FRONT = 0,
  BACK,

  UNKNOWN = 255
};

struct Garbage {
  Garbage() : type(GarbageType::UNKNOWN), direction(GarbageDir::UNKNOWN) {

  }

  GarbageType type;
  GarbageDir direction;
};

static Garbage readSingleGarbageEntry() {
  Garbage entry;

  std::string input;
  std::string material;
  std::string garbageDirection;
  std::istringstream istr;

  std::getline(std::cin, input);

  //reset the stream's internal flags
  istr.clear();
  istr.str(input);

  istr >> material >> garbageDirection;

  //strings can not be switched
  if ("glass" == material) {
    entry.type = GarbageType::GLASS;
  } else if ("metal" == material) {
    entry.type = GarbageType::METAL;
  } else if ("plastic" == material) {
    entry.type = GarbageType::PLASTIC;
  }

  if ("front" == garbageDirection) {
    entry.direction = GarbageDir::FRONT;
  } else //"back" == garbageDirection
  {
    entry.direction = GarbageDir::BACK;
  }

  return entry;
}

static void printResult(const std::list<int> entries[]) {
  const std::string materialNames[GARBAGE_TYPES]
      {
          "glass", "metal", "plastic"
      };

  for (int i = GLASS; i < GARBAGE_TYPES; ++i) {
    if (!entries[i].empty()) {
      std::cout << materialNames[i] << " - ";

      for (const int materialId : entries[i]) {
        std::cout << materialId << ' ';
      }

      std::cout << '\n';
    }
  }
}

int main() {
  std::list<int> entries[GARBAGE_TYPES];
  Garbage entry;
  int commands = 0;
  int garbageId = 0;

  std::cin >> commands;
  std::cin.ignore();

  for (int i = 0; i < commands; ++i) {
    entry = readSingleGarbageEntry();

    //invalid materials fall under the UNKNOWN category
    if (GarbageType::UNKNOWN != entry.type) {
      ++garbageId;

      if (GarbageDir::FRONT == entry.direction) {
        entries[entry.type].push_front(garbageId);
      } else //GarbageDir::BACK == entry.direction
      {
        entries[entry.type].push_back(garbageId);
      }
    }
  }

  printResult(entries);

  return 0;
}
