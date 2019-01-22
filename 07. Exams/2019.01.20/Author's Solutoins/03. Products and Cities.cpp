
#include <iostream>
#include <map>
#include <string>
int main() {
    
    bool exit = false;
    std::map<std::string,double>myMap;
    std::map<std::string,double>::iterator it = myMap.begin();
    
    int number;
    //std::cout << "Enter size : ";
    std::cin >> number;
    while( !exit )
    {
        std::string town = "";
        double price = 0;
        double quantity = 0;
        
        bool keyFinded = false;
        
        //std::cout <<"Enter Town : ";
        std::cin >> town;
        
        //std::cout << "Enter price : ";
        std::cin >> price;
        
        //std::cout << "Enter quantity : ";
        std::cin >> quantity;
        
        for( it = myMap.begin(); it != myMap.end(); it++ )
        {
            if( it == myMap.find( town ) )
            {
                it->second += price*quantity;
                
                keyFinded = true;
            }
            
        }
        
        if( !keyFinded )
        {
            myMap[town] = price*quantity;
        }
        
        if( myMap.size() >= number )
        {
            exit = true;
        }
        
        keyFinded = false;
    }
    
    for( it = myMap.begin(); it != myMap.end(); it++ )
    {
        std::cout << it->first << " " << it->second << std::endl;
    }
    return 0;
}

