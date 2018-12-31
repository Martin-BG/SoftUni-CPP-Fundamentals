#include <iostream>
#include <stack>

typedef std::stack<std::string> Clipboard;

void copyToClipboard(Clipboard& clipboard, const std::string& text, size_t start, size_t end) {
  start = text.find_last_of(' ', start);
  if (start == std::string::npos) {
    start = 0;
  } else {
    ++start;
  }
  end = text.find_first_of(' ', end);
  if (end == std::string::npos) {
    end = text.length();
  }
  clipboard.push(text.substr(start, end - start));
}

void pasteFromClipboard(Clipboard& clipboard, std::string& text, size_t start) {
  if (!clipboard.empty()) {
    std::string str = clipboard.top();
    clipboard.pop();
    if (text[start] == ' ') {
      str.insert(0, " ");
    }
    text.insert(start, str);
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  Clipboard clipboard;
  std::string text, command;
  size_t start, end;

  getline(std::cin, text);
  std::cin >> command;
  while (command != "end") {
    if (command == "copy") {
      std::cin >> start >> end;
      copyToClipboard(clipboard, text, start, end);
    } else if (command == "paste") {
      std::cin >> start;
      pasteFromClipboard(clipboard, text, start);
    }
    std::cin >> command;
  }

  std::cout << text;

  return 0;
}
