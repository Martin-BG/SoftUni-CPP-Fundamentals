#include <iostream>
#include <string>
#include <vector>
#include <climits>

const long sec = 299792;

class Planet
{
    std::string name;
    long distance;
    long diametur;
    long masa;
public:
    Planet( std::string n, double dis, double diam, double m )
    {
        name = n;
        distance = dis;
        diametur = diam;
        masa = m;
    }

    void Print()
    {
        std::cout << name << " " << distance << " " << diametur << " " << masa << std::endl;
    }

    long CalculateTime()
    {
        return distance / sec;
    }

    long GetMasa()
    {
        return masa;
    }

    long GetDiametur()
    {
        return diametur;
    }
};

void CalculateMinMasa(std::vector<Planet> myVec)
{
    long minMasa = myVec.at(0).GetMasa();
    for ( int i = 1; i < myVec.size(); ++i )
    {
        if ( minMasa > myVec[i].GetMasa() )
        {
            minMasa = myVec[i].GetMasa();
        }
    }
    std::cout << minMasa << std::endl;
}

void CalculateMaxDiametur( std::vector<Planet> myVec )
{
    long maxDiametur = myVec.at(0).GetDiametur();
    for ( int i = 1; i < myVec.size(); ++i )
    {
        if ( maxDiametur < myVec.at(i).GetDiametur() )
        {
            maxDiametur = myVec.at(i).GetDiametur();
        }
    }
    std::cout << maxDiametur << std::endl;
}



int main()
{

    std::vector<Planet> myVec;
    int number = 0;
    std::cin >> number;

    for (int i = 0; i < number; ++i )
    {
        std::string name;
        double distance;
        double diametur;
        double masa;
        std::cin >> name >> distance >> diametur >> masa;

        Planet temp ( name , distance, diametur, masa );
        myVec.push_back( temp );
    }

    for (int i = 0; i < myVec.size(); ++i )
    {
        myVec.at(i).Print();
        std::cout << myVec.at(i).CalculateTime();
        std::cout <<std::endl;
    }

    CalculateMinMasa(myVec);
    CalculateMaxDiametur(myVec);
    return 0;
}

