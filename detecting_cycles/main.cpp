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

class List {
  struct Node {
    int el;
    Node* next;
  };
  Node* first;
  Node* last;
public:
  List() : first(0) {}
  ~List() {
    Node *p(first);
    while(p != last) {
      p = p->next;
      delete first;
      first = p;
    }
    delete last;
    first = 0;
    last = 0;
  }

  void add(int el) {
    if(first == 0) {
      first = new Node;
      last = first;
      first->el = el;
      first->next = 0;
      return;
    }
    Node* p(first);

    while(p != 0) {
      if(p->el == el) {
        if(last->next == 0) last->next = p;
        return;
      }
      p = p->next;
    }

    Node* k = new Node;
    k->el = el;
    k->next = 0;
    last->next = k;
    last = k;
  }

  void print_sequence() {
    Node* hare(first);
    Node* tortoise(first);

    for(;;) {
      if(hare->next == 0) return;
      hare = hare->next;
      if(hare->next == 0) return;
      hare = hare->next;
      tortoise = tortoise->next;
      if(hare == tortoise) break;
    }

    int mi = 0;
    tortoise = first;
    for(;;) {
      if(hare == tortoise) break;
      tortoise = tortoise->next;
      hare = hare->next;
      mi++;
    }

    int lambda = 1;
    hare = tortoise->next;
    for(;;) {
      if(hare == tortoise) break;
      hare = hare->next;
      lambda++;
    }

    Node* p(first);
    for(int i=0; i<mi; i++) {
      p = p->next;
    }
    for(int i=0; i<lambda; i++) {
      cout << p->el << " ";
      p = p->next;
    }
    cout << endl;
  }
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
      List list;
      vector<string> strings = split(line, ' ');
      for(int i=0; i<strings.size(); i++) {
        list.add(atoi(strings[i].c_str()));
      }
      list.print_sequence();
    }
    return 0;
}