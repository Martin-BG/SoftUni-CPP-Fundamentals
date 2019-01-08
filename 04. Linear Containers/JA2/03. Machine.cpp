#include <iostream>
#include <stack>

class Machine {
private:
  std::stack<int> stack;

  int extract() {
    if (this->stack.empty()) {
      throw std::runtime_error("Nothing to extract!");
    }
    int a = this->stack.top();
    this->stack.pop();
    return a;
  }

  void add(int n) {
    this->stack.push(n);
  }

  void removeLast() {
    if (!this->stack.empty()) {
      this->stack.pop();
    }
  }

  bool empty() const {
    return this->stack.empty();
  }

public:

  void insert(int n) {
    this->add(n);
  }

  void sum() {
    int a = this->extract();
    int b = this->extract();
    this->add(a + b);
  }

  void subtract() {
    int a = this->extract();
    int b = this->extract();
    this->add(a - b);
  }

  void concat() {
    int a = this->extract();
    int b = this->extract();
    this->add(stoi(std::to_string(b) + std::to_string(a)));
  }

  void discard() {
    this->removeLast();
  }

  bool hasNext() const {
    return !this->empty();
  }

  int next() {
    return this->extract();
  }
};

int main() {
  Machine machine;

  std::string input;

  while (std::cin >> input && input != "end") {
    if (input == "sum") {
      machine.sum();
    } else if (input == "subtract") {
      machine.subtract();
    } else if (input == "concat") {
      machine.concat();
    } else if (input == "discard") {
      machine.discard();
    } else {
      machine.insert(stoi(input));
    }
  }

  std::stack<int> reversed;
  while (machine.hasNext()) {
    reversed.push(machine.next());
  }

  while (!reversed.empty()) {
    std::cout << reversed.top() << std::endl;
    reversed.pop();
  }

  return 0;
}
