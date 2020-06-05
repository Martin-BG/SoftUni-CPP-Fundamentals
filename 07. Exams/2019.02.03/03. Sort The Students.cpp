#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Student {
  std::string firstName;
  std::string lastName;
  double averageScores;
public:
  double getAverageScores() const {
    return averageScores;
  }

  std::string getFullName() const {
    return firstName + " " + lastName;
  }

  friend std::ostream& operator<<(std::ostream& out, const Student& student);

  friend std::istream& operator>>(std::istream& in, Student& student);
};

std::ostream& operator<<(std::ostream& out, const Student& student) {
  return out << student.getFullName() << " " << student.getAverageScores();
}

std::istream& operator>>(std::istream& in, Student& student) {
  return in >> student.firstName >> student.lastName >> student.averageScores;
}

int main() {
  size_t studentsCount;
  std::cin >> studentsCount;
  std::vector<Student> students{ studentsCount };

  for (size_t i = 0; i < studentsCount; ++i) {
    std::cin >> students[i];
  }

  // NOTE
  // This solution fails to pass all tests in Judge because of incorrect test
  // data caused by a bug in the custom sort implementation used by Author's reference solution.
  //
  // Here is a simple test to demonstrate the problem:
  // INPUT     Author's/Judge     Correct
  // a a 3     a a 3              a a 3
  // b b 3     c c 3 <- BUG       b b 3
  // c c 3     b b 3 <- BUG       c c 3
  std::sort(students.begin(), students.end(), [](const Student& lhs, const Student& rhs) {
    return lhs.getAverageScores() > rhs.getAverageScores();
  });
  std::copy(students.begin(), students.end(), std::ostream_iterator<Student>(std::cout, "\n"));

  std::cout << std::endl;

  std::sort(students.begin(), students.end(), [](const Student& lhs, const Student& rhs) {
    return lhs.getFullName() < rhs.getFullName();
  });
  std::copy(students.begin(), students.end(), std::ostream_iterator<Student>(std::cout, "\n"));

  return 0;
}
