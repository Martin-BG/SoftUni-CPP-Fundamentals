#include <iostream>
#include <vector>
#include <string>
#include <sstream>

typedef std::vector<std::string> Field;

enum CommandType {
  POWER_UP = 0,
  POWER_DOWN,
  BOMB,

  UNKNOWN = 255
};

struct Command {
  Command() : type(CommandType::UNKNOWN), bombRow(-1), bombCol(-1) {

  }

  CommandType type;

  //used only if command is of type BOMB
  int bombRow;
  int bombCol;
};

static Field readField() {
  Field field;

  size_t rows = 0;
  size_t cols = 0;
  std::cin >> rows >> cols;
  std::cin.ignore();

  field.resize(rows);
  for (std::string& row : field) {
    std::getline(std::cin, row);
  }

  return field;
}

static std::vector<Command> readCommands() {
  std::vector<Command> commands;

  size_t commandsCount = 0;
  std::cin >> commandsCount;
  std::cin.ignore();

  std::string commandStr;
  std::istringstream istr;
  commands.resize(commandsCount);
  for (size_t i = 0; i < commandsCount; ++i) {
    std::getline(std::cin, commandStr);

    istr.clear();
    istr.str(commandStr);

    //the commandStr is no longer needed -> reuse the std::string variable
    istr >> commandStr;
    if ("bomb" == commandStr) {
      commands[i].type = BOMB;
      istr >> commands[i].bombRow >> commands[i].bombCol;
    } else //"power" == commandStr
    {
      //extract the next word (up or down)
      istr >> commandStr;

      if ("up" == commandStr) {
        commands[i].type = POWER_UP;
      } else //"down" == commandStr)
      {
        commands[i].type = POWER_DOWN;
      }
    }
  }

  return commands;
}

static void transformAsciiToDigits(Field& field) {
  for (std::string& row : field) {
    for (char& tile : row) {
      tile -= '0';
    }
  }
}

//returns how many points placing the bomb gives
static int placeBomb(Field& field,
                     const int bombPower,
                     const int bombRow,
                     const int bombCol) {
  int score = 0;

  //we will learn about C++ specific casts in C++Advanced
  //for now use C cast style
  const int MAX_ROWS = (int) field.size();
  const int MAX_COLS = field.empty() ? 0 : (int) field[0].size();

  int startRow = bombRow - bombPower;
  if (0 > startRow) {
    startRow = 0;
  }

  int startCol = bombCol - bombPower;
  if (0 > startCol) {
    startCol = 0;
  }

  int endRow = bombRow + bombPower;
  if (endRow >= MAX_ROWS) {
    endRow = MAX_ROWS - 1;
  }

  int endCol = bombCol + bombPower;
  if (endCol >= MAX_COLS) {
    endCol = MAX_COLS - 1;
  }

  for (int row = startRow; row <= endRow; ++row) {
    score += field[row][bombCol];
    field[row][bombCol] = 0;
  }

  for (int col = startCol; col <= endCol; ++col) {
    score += field[bombRow][col];
    field[bombRow][col] = 0;
  }

  return score;
}

//the field parameter is going to be modified -> it will not be const
static void playGame(Field& field,
                     const std::vector<Command>& commands) {
  int bombPower = 0;

  for (const Command& command : commands) {
    switch (command.type) {
    case CommandType::POWER_UP:
      ++bombPower;
      std::cout << "Increased bomb power to " << bombPower << '\n';
      break;

    case CommandType::POWER_DOWN:
      --bombPower;
      std::cout << "Decreased bomb power to " << bombPower << '\n';
      break;

    case CommandType::BOMB:
      std::cout << placeBomb(field,
                             bombPower,
                             command.bombRow,
                             command.bombCol) << " points\n";
      break;

    default:
      std::cerr << "Received invalid command type: "
                << command.type << '\n';
      break;
    }
  }
}

int main() {
  Field field = readField();
  std::vector<Command> commands = readCommands();

  transformAsciiToDigits(field);
  playGame(field, commands);

  return EXIT_SUCCESS;
}


