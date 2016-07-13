#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    int a = 'a';
    int z = 'z';
    int difference = 'a' - 'A';
    while (getline(stream, line)) {
      for(int i = 0; i < line.size(); i++) {
        if(line[i] >= a && line[i] <= z && (i == 0 || line[i-1] == ' ')) {
          line[i] -= difference;
        }
      }
      cout << line << "\n";
    }
    return 0;
}