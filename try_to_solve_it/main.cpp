#include <iostream>
#include <fstream>
using namespace std;

char decryptchar(char c) {
  if(c >= 'a' && c <= 'f') {
    return c + 'u' - 'a';
  }
  if(c >= 'g' && c <= 'm') {
    return c + 'n' - 'g';
  }
  if(c >= 'u' && c <= 'z') {
    return c - 'u' + 'a';
  }
  if(c >= 'n' && c <= 't') {
    return c - 'n' + 'g';
  }
  return c;
}

string decryptstring(string s) {
  string decrypted;
  for(int i=0; i<s.size(); i++) {
    decrypted.push_back(decryptchar(s[i]));
  }
  return decrypted;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      cout << decryptstring(line) << endl;
    }
    return 0;
}