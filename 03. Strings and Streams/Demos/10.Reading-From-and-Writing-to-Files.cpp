#include <fstream>
using namespace std;

int main() {
    ifstream input;
    /// NOTE: the file input.txt should exist in the directory where the binary file is created and run!
    input.open("input.txt");
    int a, b;
    input >> a >> b;

    ofstream output;
    output.open("output.txt", fstream::app);
    output << a + b << endl;

    return 0;
}
