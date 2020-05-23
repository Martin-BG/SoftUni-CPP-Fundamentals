#include<iostream>
#include<map>
#include<string>

int main() {
  std::map<std::string, std::pair<double, double> > myMap;
  std::map<std::string, std::pair<double, double> >::iterator it = myMap.begin();

  int number = 0;
  //std::cout << "Enter number of town : ";
  std::cin >> number;
  int count = 0;

  while (count < number) {
    bool keyFinded = false;

    std::string town;
    std::pair<double, double> myTemp;

    //std::cout << "Enter town : ";
    std::cin >> town;

    //std::cout <<"Enter min temperature : ";
    std::cin >> myTemp.first;

    //std::cout <<"Enter max temperature : ";
    std::cin >> myTemp.second;

    for (it = myMap.begin(); it != myMap.end(); it++) {
      if (it == myMap.find(town)) {
        if (myTemp.first < it->second.first) {
          it->second.first = myTemp.first;
        }
        if (myTemp.second > it->second.second) {
          it->second.second = myTemp.second;
        }
        keyFinded = true;
      }

    }

    if (!keyFinded) {
      myMap[town].first = myTemp.first;
      myMap[town].second = myTemp.second;
      count++;
    }

  }


  for (it = myMap.begin(); it != myMap.end(); it++) {
    std::cout << it->first << " " << it->second.first << " " << it->second.second << std::endl;
  }


  return 0;
}

