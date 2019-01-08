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

  friend void print(Student const& student);

  friend double calcAverage(std::vector<Student> const& students);
};

void print(Student const& student) {
  std::cout << student.name << " " << student.surname << " " << student.score << std::endl;
}

double calcAverage(std::vector<Student> const& students) {
  if (students.empty()) {
    return 0.0;
  }

  double total = 0.0;
  for (auto const& student : students) {
    total += student.score;
  }
  return total / students.size();
}

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
    print(student);
  }

  std::cout << static_cast<int>(calcAverage(students)) << std::endl;

  return 0;
}
