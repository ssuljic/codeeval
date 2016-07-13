#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

vector<string> &split(const string &s, char delim, vector<string> &elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

vector<string> split(const string &s, char delim) {
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

void floyd(const vector<string> seq) {
  if(seq.size() < 1 || (seq.size() == 2 && seq[0] == seq[1])) return;

  int tortoise = 1;
  int hare = 2;
  while(seq[tortoise] != seq[hare]) {
    if(tortoise < seq.size() - 1) {
      tortoise++;
    } else {
      tortoise = seq.size() - 1;
    }
    if(hare < seq.size() - 1) {
      hare = tortoise * 2;
    } else {
      hare = seq.size() - 1;
    }
  }

  int mi = 0;
  tortoise = 0;
  while(seq[tortoise] != seq[hare]) {
    if(tortoise < seq.size() - 1) {
      tortoise++;
    } else {
      tortoise = seq.size() - 1;
    }
    if(hare < seq.size() - 1) {
      hare++;
    } else {
      hare = seq.size() - 1;
    }
    mi += 1;
  }

  int lambda = 1;
  hare = tortoise + 1;
  while(seq[tortoise] != seq[hare]) {
    if(hare < seq.size() - 1) {
      hare++;
    } else {
      hare = seq.size() - 1;
    }
    lambda += 1;
  }

  for(int i=0; i<lambda; i++) {
    cout << seq[mi + i] << " ";
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      vector<string> strings = split(line, ' ');
      floyd(strings);
    }
    return 0;
}