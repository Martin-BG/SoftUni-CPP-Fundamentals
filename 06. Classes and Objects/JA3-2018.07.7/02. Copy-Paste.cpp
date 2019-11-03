#include <iostream>
#include <stack>
#include <sstream>

class TextEditor {
private:
  std::stack<std::string> clipboard{ };
  std::string text;

  void copy(size_t start, size_t end) {
    start = this->text.find_last_of(' ', start);
    if (start == std::string::npos) {
      start = 0;
    } else {
      ++start;
    }

    end = this->text.find(' ', end);

    const size_t len = end - start;

    std::string copied = this->text.substr(start, len);

    clipboard.push(copied);
  }

  void paste(size_t index) {
    if (!clipboard.empty()) {
      std::string toPaste = clipboard.top();
      clipboard.pop();

      if (this->text[index] == ' ') {
        toPaste.insert(toPaste.begin(), ' ');
      }

      this->text.insert(index, toPaste);
    }
  }

public:
  explicit TextEditor(std::string text) : text(std::move(text)) { }

  void handleInput(const std::string& input) {
    std::istringstream iss(input);
    std::string command;
    iss >> command;
    if (command == "copy") {
      size_t start, end;
      iss >> start >> end;
      copy(start, end);
    } else if (command == "paste") {
      size_t index;
      iss >> index;
      paste(index);
    }
  }

  const std::string& getText() const {
    return text;
  }
};

int main() {
  std::istream& in = std::cin;
  std::ostream& out = std::cout;

  std::string text;
  std::getline(in, text);

  TextEditor textEditor{ text };

  std::string command;
  while (std::getline(in, command) && command != "end") {
    textEditor.handleInput(command);
  }

  out << textEditor.getText();

  return 0;
}
