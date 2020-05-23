
#include <iostream>
#include <vector>
#include <string>
#include <map>

struct Student {
  std::string FirstName;
  std::string LastName;
  double Average;
};

int main() {
  std::vector<Student> stud;
  std::vector<double> averageScores;
  std::map<std::string, double> names;
  std::map<std::string, double>::iterator it = names.begin();
  int number;
  //std::cout << "Enter number of Student : ";
  std::cin >> number;
  for (int i = 0; i < number; i++) {
    double average;
    Student temp;

    //        std::cout << "Enter first name :";
    std::cin >> temp.FirstName;

    //        std::cout << "Enter Last name :";
    std::cin >> temp.LastName;

    //        std::cout << "Enter average :";
    std::cin >> average;
    temp.Average = average;

    stud.push_back(temp);

    averageScores.push_back(temp.Average);

    names[temp.FirstName + " " + temp.LastName] = temp.Average;

  }

  std::sort(averageScores.begin(), averageScores.end(), std::greater<double>());

  for (unsigned int i = 0; i < averageScores.size(); i++) {
    for (unsigned int j = 0; j < stud.size(); j++) {
      if (averageScores.at(i) == stud.at(j).Average) {
        std::cout << stud.at(j).FirstName << " " << stud.at(j).LastName << " " << stud.at(j).Average << std::endl;

        stud.erase(stud.begin() + j);
      }
    }
  }

  std::cout << std::endl;

  for (it = names.begin(); it != names.end(); it++) {
    std::cout << it->first << " " << it->second << std::endl;
  }
  return 0;
}
