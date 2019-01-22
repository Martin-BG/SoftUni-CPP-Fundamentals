#include <iostream>
#include <string>


const double dayEnergyPrice = 0.13;
const double nightEnergyPrice = 0.07;
const int NumberOfDay = 30;
const double cubicWater = 1.65;
const double cubicGas = 0.09;
class Costs
{
    double water;
    double gas;
    const unsigned int MoneyForChild = 40;
    int Rent;
    double energy;
    double salaryMother;
    double salaryFather;
public:
    Costs( int w, int g, unsigned int eD, unsigned int eN, int r, double sM, double sF)
    {
        SetWater( w );
        SetGas( g );
        SetEnergy(eD, eN);
        SetRent(r);
        this->salaryFather = sF;
        this->salaryMother = sM;
    }

    void SetWater( int w )
    {
        this->water = w*cubicWater;
    }

    void SetGas( int g )
    {
       this->gas = g*cubicGas;
    }

    void SetEnergy( int day, int night )
    {
        energy = day*dayEnergyPrice + night*nightEnergyPrice;
    }

    void SetRent ( int r )
    {
        this->Rent = r;
    }

    double GetWater()
    {
       return water;
    }

    double GetGas()
    {
       return gas;
    }

    double GetEnergy()
    {
       return energy;
    }

    void Print()
    {
        std::cout << "Water : " << GetWater() << std::endl;
        std::cout << "Gas : " << GetGas() << std::endl;
        std::cout << "Energy : " << GetEnergy() << std::endl;

    }

    double GetAllCosts()
    {
        return GetEnergy() + GetGas() + GetWater() + MoneyForChild + Rent;
    }

    double GetRemainingSalary( )
    {
        return (salaryFather + salaryMother) - GetAllCosts();
    }

    double GetMoneyForDay()
    {
        return GetRemainingSalary() / 30;
    }


};

int main()
{
    int water, gas, energyDay, energyNight, rent, salaryMother, salaryFather;
    do
    {
        //std::cout<< "Enter water ( water can not be negavite number or zero ) : ";
        std::cin >> water;

    } while( water <= 0 );

    do
    {
        //std::cout<< "Enter gas ( gas can not be negative number or zero ) : ";
        std::cin >> gas;

    } while( gas <= 0 );

    do
    {
        //std::cout<< "Enter energyDay ( energy can not be negative number or zero ) : ";
        std::cin >> energyDay;

    } while( energyDay <= 0 );

    do
    {
        //std::cout<< "Enter rent ( rent can not be negative number or zero ) : ";
        std::cin >> rent;

    } while( rent <= 0 );

    do
    {
        //std::cout<< "Enter energyNight ( enegry can not be negative number or zero ) : ";
        std::cin >> energyNight;

    } while( energyNight <= 0 );

    do
    {
        //std::cout<< "Enter mother salary ( salary can not be negative number or zero ) : ";
        std::cin >> salaryMother;

    } while( salaryMother <= 0 );

    do
    {
        //std::cout<< "Enter father salary ( salary can not be negative number or zero ) : ";
        std::cin >> salaryFather;

    } while( salaryFather <= 0 );

    Costs c(water, gas, energyDay, energyNight, rent, salaryMother, salaryFather);
    c.Print();

    std::cout << "All costs : " << c.GetAllCosts() << std::endl;

    std::cout << "Remaining Salary : " << c.GetRemainingSalary() << std::endl;
    if ( c.GetRemainingSalary() <= 0 )
    {
        std::cout<< "You should find new job !" << std::endl;
    }
    std::cout << "Money for one day : " << c.GetMoneyForDay() << std::endl;



    return 0;
}

