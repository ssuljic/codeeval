#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool properlyClosed(string line) {
  vector<char> stack;
  char closing[] = { '}', ']', ')' };
  char opening[] = { '{', '[', '(' };

  for(int i=0; i<line.length(); i++) {
    bool open = false;
    for(int j=0; j<3; j++) {
      if(line[i] == opening[j]) {
        open = true;
        break;
      }
    }

    if(open) {
      stack.push_back(line[i]);
    } else {
      if(stack.size() == 0) return false;
      char par = stack.back();
      stack.pop_back();
      int index;
      for(index = 0; index<3; index++) {
        if(par == opening[index]) {
          break;
        }
      }
      if(line[i] != closing[index]) return false;
    }
  }

  if(stack.size() != 0) return false;
  return true;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      if(properlyClosed(line)) {
        cout << "True\n";
      } else {
        cout << "False\n";
      }
    }
    return 0;
}