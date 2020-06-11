#include <iostream>
#include <vector>
#include <map>
#include <sstream>

struct EquationEntry
{
    EquationEntry() : result(0) {}

    std::string equation;
    int         result;
};

enum OperandDefines
{
    LEFT = 0,
    RIGHT,

    OPERANDS_COUNT
};

typedef std::map<int, std::vector<std::string>, std::greater<int>> EquationMap;

static EquationEntry readSingleEntry()
{
    EquationEntry entry;

    std::getline(std::cin, entry.equation);

    std::istringstream istr(entry.equation);
    int operands[OPERANDS_COUNT] { 0 };
    char operation = '\0';

    istr >> operands[LEFT] >> operation >> operands[RIGHT];

    switch(operation)
    {
        case '+':
            entry.result = operands[LEFT] + operands[RIGHT];
            break;

        case '-':
            entry.result = operands[LEFT] - operands[RIGHT];
            break;

        case '/':
            entry.result = operands[LEFT] / operands[RIGHT];
            break;

        case '*':
            entry.result = operands[LEFT] * operands[RIGHT];
            break;

        case '%':
            entry.result = operands[LEFT] % operands[RIGHT];
            break;

        default:
            std::cout << "Error, unsuported operation "
                      << operation << std::endl;
            break;
    }

    return entry;
}

static void printResult(const EquationMap & equationMap)
{
    std::map<int, std::vector<std::string>>::const_iterator mapIt;
    std::vector<std::string>::const_iterator vecIt;
    for(mapIt = equationMap.begin(); mapIt != equationMap.end(); ++mapIt)
    {
        for(vecIt = mapIt->second.begin(); vecIt != mapIt->second.end(); ++vecIt)
        {
            std::cout << *vecIt << '\n';
        }
    }
}

int main()
{
    EquationMap equationMap;
    EquationEntry entry;

    int32_t commandsCount = 0;
    std::cin >> commandsCount;
    std::cin.ignore();

    for(int i = 0; i < commandsCount; ++i)
    {
        entry = readSingleEntry();

        equationMap[entry.result].emplace_back(entry.equation);
    }

    printResult(equationMap);

	return EXIT_SUCCESS;
}
