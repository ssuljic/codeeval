#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      int num = atoi(line.c_str());
      string binary = bitset<64>(num).to_string();
      int sum = 0;
      for(int i=0; i<binary.size(); i++) {
        if(binary[i] == '1') sum++;
      }
      cout << sum << endl;
    }
    return 0;
}