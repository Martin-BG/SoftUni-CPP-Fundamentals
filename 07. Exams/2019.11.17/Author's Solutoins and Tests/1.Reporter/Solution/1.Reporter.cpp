#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <cctype>

int main()
{
    std::string input;
    std::istringstream istr;
    std::string word;
    int inputRows = 0;

    std::set<std::string> uniqueWords;
    std::ostringstream answer;

    std::cin >> inputRows;
    std::cin.ignore();

    for(int i = 0; i < inputRows; ++i)
    {
        std::getline(std::cin, input);
        istr.clear();
        istr.str(input);

        while(istr >> word)
        {
            if("." == word)
            {
                uniqueWords.clear();
                answer << ". ";
            }
            else if(uniqueWords.end() == uniqueWords.find(word))
            {
                uniqueWords.insert(word);
                answer << word << ' ';
            }
        }
    }

    std::cout << answer.str();

    return 0;
}
