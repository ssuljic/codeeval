#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      int num = atoi(line.c_str());
      if(num % 2 == 0) {
        cout << 1 << "\n";
      } else {
        cout << 0 << "\n";
      }
    }
    return 0;
}