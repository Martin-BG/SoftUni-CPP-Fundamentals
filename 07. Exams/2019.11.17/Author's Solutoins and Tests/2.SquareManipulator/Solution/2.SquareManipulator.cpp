#include <iostream>
#include <vector>
#include <algorithm>


static std::vector<std::vector<int>> parseRectangle()
{
    //enable return value optimisation (RVO)
    std::vector<std::vector<int>> rect;

    int rectWidth  = 0;
    int rectHeight = 0;

    std::cin >> rectHeight >> rectWidth;

    rect.resize(rectHeight);
    for(int row = 0; row < rectHeight; ++row)
    {
        rect[row].resize(rectWidth);
        for(int col = 0; col < rectWidth; ++col)
        {
            std::cin >> rect[row][col];
        }
    }

    return rect;
}

static int getSquareSum(const std::vector<std::vector<int>> & rect,
                        const size_t                          squareSide,
                        const size_t                          startRow,
                        const size_t                          startCol)
{
    int sum = 0;

    const size_t END_ROW = startRow + squareSide;
    const size_t END_COL = startCol + squareSide;
    for(size_t row = startRow; row < END_ROW; ++row)
    {
        for(size_t col = startCol; col < END_COL; ++col)
        {
            sum += rect[row][col];
        }
    }

    return sum;
}

int main()
{
    std::vector<std::vector<int>> rect = parseRectangle();

    size_t squareSide = 0;
    int targetSum = 0;
    std::cin >> squareSide >> targetSum;

    if((rect.empty()) ||
       (squareSide > rect.size()) ||
       (squareSide > rect[0].size()))
    {
        std::cerr << "Error, invalid input" << std::endl;
        return EXIT_FAILURE;
    }

    std::vector<int> targetSumResults;

    const size_t ROWS_TO_CHECK = rect.size() - squareSide;
    const size_t COLS_TO_CHECK = rect.empty() ? 0 : rect[0].size() - squareSide;

    int currSum = 0;
    const int DIVISOR = squareSide * squareSide;

    //the nested loop ensure proper boundaries
    for(size_t row = 0; row <= ROWS_TO_CHECK; ++row)
    {
        for(size_t col = 0; col <= COLS_TO_CHECK; ++col)
        {
            currSum = getSquareSum(rect, squareSide, row, col);
            if(currSum >= targetSum)
            {
                targetSumResults.emplace_back(currSum / DIVISOR);
            }
        }
    }

    std::sort(targetSumResults.begin(), targetSumResults.end());

    for(const int number : targetSumResults)
    {
        std::cout << number << ' ';
    }
    std::cout << '\n';

    return EXIT_SUCCESS;
}

