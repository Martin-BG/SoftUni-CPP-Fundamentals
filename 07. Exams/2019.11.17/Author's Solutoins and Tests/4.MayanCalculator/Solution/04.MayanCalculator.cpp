#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef std::vector<std::string> MayanLetter;

enum Defines
{
    LETTERS_COUNT = 10
};

static std::vector<std::string> readInput()
{
    std::vector<std::string> inputRows;

    int numberOfRows  = 0;
    std::cin >> numberOfRows;
    std::cin.ignore();

    inputRows.resize(numberOfRows);
    for(int row = 0; row < numberOfRows; ++row)
    {
        std::getline(std::cin, inputRows[row]);
    }

    return inputRows;
}

static std::vector<MayanLetter> getMayanLetters()
{
    std::vector<MayanLetter> mayanLetters(LETTERS_COUNT);

    const std::vector<std::string> inputRows = readInput();
    const size_t INPUT_ROWS_SIZE = inputRows.size();

    const int LETTER_WIDTH =
                     INPUT_ROWS_SIZE ? inputRows[0].size() / LETTERS_COUNT : 0;

    for(MayanLetter & mayanLetter : mayanLetters)
    {
        mayanLetter.resize(INPUT_ROWS_SIZE);
    }

    for(size_t row = 0; row < INPUT_ROWS_SIZE; ++row)
    {
        for(int i = 0; i < LETTERS_COUNT; ++i)
        {
            mayanLetters[i][row] =
                          inputRows[row].substr(i * LETTER_WIDTH, LETTER_WIDTH);
        }
    }

    return mayanLetters;
}

static int readPrintNumber()
{
    int num = 0;

    std::cin >> num;
    std::cin.ignore();

    return num;
}

static std::vector<int> getDigitsFromNumber(int number)
{
    std::vector<int> digits;

    if(0 != number)
    {
        while(number)
        {
            digits.emplace_back(number % 10);
            number /= 10;
        }

        std::reverse(digits.begin(), digits.end());
    }
    else
    {
        digits.emplace_back(0);
    }

    return digits;
}

static void printMayanNumber(const std::vector<MayanLetter> & mayanLetters,
                             const std::vector<int> &         digitsToPrint)
{
    //sanity check
    if(mayanLetters.empty() || mayanLetters[0].empty())
    {
        return;
    }

    const size_t ROWS = mayanLetters[0].size();

    for(size_t row = 0; row < ROWS; ++row)
    {
        for(const int digit : digitsToPrint)
        {
            std::cout << mayanLetters[digit][row];
        }
        std::cout << '\n';
    }
}

int main()
{
    const std::vector<MayanLetter> mayanLetters = getMayanLetters();

    const std::vector<int> digitsToPrint =
                                        getDigitsFromNumber(readPrintNumber());

    printMayanNumber(mayanLetters, digitsToPrint);

	return EXIT_SUCCESS;
}


