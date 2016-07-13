#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int sum = 0;
    while (getline(stream, line)) {
      sum += atoi(line.c_str());
    }
    cout << sum;
    return 0;
}