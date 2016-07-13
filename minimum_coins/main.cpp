#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Knapsack {
    int capacity;
    int weight;
    vector<int> items;
public:
    Knapsack(int c) : capacity(c), weight(0) {};

    void add_item(int item) {
        if(weight + item > capacity) throw "Capacity overflow";
        items.push_back(item);
        weight += item;
    }

    int size() {
        return items.size();
    }

    void greedy_add(vector<int> elems) {
        int index = 0;
        for(;;) {
            if(weight == capacity) break;
            int item = elems[index];
            if(weight + item <= capacity) {
                add_item(item);
            } else {
                index++;
            }
        }
    }
};

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    vector<int> elems;
    elems.push_back(5);
    elems.push_back(3);
    elems.push_back(1);
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
        Knapsack k = Knapsack(num);
        k.greedy_add(elems);
        cout << k.size() << endl;
    }
    return 0;
}