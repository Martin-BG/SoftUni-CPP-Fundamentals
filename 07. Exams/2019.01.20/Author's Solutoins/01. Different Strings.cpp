#include <iostream>
#include <cctype>

using namespace std;
const int MAX_SIZE = 150;

int main()
{
    char first[MAX_SIZE];
    char second[MAX_SIZE];

    int actualSize;
    cin >> actualSize;

    for (int i = 0; i < actualSize; i++) {
        cin >> first[i];
    }

    for (int i = 0; i < actualSize; i++) {
        cin >> second[i];
    }
    int sumOfNumbers = 0;
    int numDifferences = 0;
    int numTheSame = 0;

    for (int i = 0; i < actualSize; i++)
    {
        char a = first[i];
        char b = second[i];
        if (a == b)
        {
            cout << a;
            numTheSame++;
        }
        else if ( toupper(a) == toupper(b) )
        {
            /// NOTE: toupper doesn't change the value if it is not a letter
            cout << (char)toupper(a);
            numTheSame++;
        }
        else
        {
            numDifferences++;
            cout << '#';
        }
        if ( a >= '0' && a <= '9' )
        {
            sumOfNumbers += (int)a - '0';
        }
        if ( b >= '0' && b <= '9' )
        {
            sumOfNumbers +=(int)b - '0';
        }
    }
    cout << endl;

    cout << numDifferences << endl;

    cout << numTheSame << endl;
    
    cout << sumOfNumbers << endl;

    return 0;
}
