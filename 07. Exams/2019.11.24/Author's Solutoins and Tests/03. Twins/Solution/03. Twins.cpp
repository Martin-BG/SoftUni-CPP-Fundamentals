#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <cstdlib>

enum Defines {
  PEPI = 0,
  MIMI,

  TWINS_COUNT
};

struct ClientData {
  ClientData() : minutesToProcess(0) {

  }

  std::string name;
  int minutesToProcess;
};

struct InputData {
  InputData() : totalWorkingMinutes(0) {

  }

  std::queue<ClientData> clientQueue[TWINS_COUNT];
  int totalWorkingMinutes;
};

static InputData readInput() {
  //return value optimisation will kick in
  InputData data;

  int customersToProcess = 0;
  std::cin >> customersToProcess;
  std::cin.ignore();

  std::string customerCommand;
  std::string twinIdentifier;
  std::istringstream istr;

  ClientData clientData;

  for (int i = 0; i < customersToProcess; ++i) {
    std::getline(std::cin, customerCommand);
    istr.clear();
    istr.str(customerCommand);

    istr >> twinIdentifier
         >> clientData.name
         >> clientData.minutesToProcess;

    if ("Pepi" == twinIdentifier) {
      data.clientQueue[PEPI].push(clientData);
    } else //"Mimi" == twinIdentifier
    {
      data.clientQueue[MIMI].push(clientData);
    }
  }

  std::cin >> data.totalWorkingMinutes;

  return data;
}

int main() {
  InputData data = readInput();

  const std::string twinNames[TWINS_COUNT]
      {
          "Pepi", "Mimi"
      };

  for (int i = 0; i < data.totalWorkingMinutes; ++i) {
    for (int twinId = PEPI; twinId < TWINS_COUNT; ++twinId) {
      std::cout << twinNames[twinId];

      if (!data.clientQueue[twinId].empty()) {
        --data.clientQueue[twinId].front().minutesToProcess;

        std::cout << " processing "
                  << data.clientQueue[twinId].front().name
                  << '\n';

        if (0 == data.clientQueue[twinId].front().minutesToProcess) {
          data.clientQueue[twinId].pop();
        }
      } else {
        std::cout << " Idle\n";
      }
    }
  }

  return EXIT_SUCCESS;
}


