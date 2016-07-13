#include <iostream>
#include <fstream>
using namespace std;

int fibonacci(int n) {
  if(n == 0) return 0;
  if(n == 1) return 1;
  int first = 0, second = 1, res = 0;
  for(int i=1; i<n; i++) {
    res = second + first;
    first = second;
    second = res;
  }

  return res;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      int num = atoi(line.c_str());
      cout << fibonacci(num) << "\n";
    }
    return 0;
}