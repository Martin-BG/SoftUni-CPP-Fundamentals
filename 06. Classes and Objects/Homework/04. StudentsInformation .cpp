#include <iostream>
#include <vector>

class Student {
private:
  std::string name;
  std::string surname;
  double score;
public:
  Student(std::string name, std::string surname, double score) :
      name(std::move(name)),
      surname(std::move(surname)),
      score(score) { }

  void print() const {
    std::cout << this->name << " " << this->surname << " " << this->score << std::endl;
  }
};

int main() {
  int count;
  std::cin >> count;

  std::string name, surname;
  double score;

  std::vector<Student> students;

  while (--count >= 0) {
    std::cin >> name >> surname >> score;
    students.emplace_back(name, surname, score);
  }

  for (auto const& student : students) {
    student.print();
  }

  return 0;
}
