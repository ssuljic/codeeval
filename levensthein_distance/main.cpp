#include <iostream>
#include <fstream>
#include <vector>
#include <set>

using namespace std;

int minimum(int n1, int n2, int n3) {
    int min = n1;
    if(n2 < min) min = n2;
    if(n3 < min) min = n3;
    return min;
}

int levenshtein_distance(const string& s, const string& t) {
    if (s == t) return 0;
    if (s.length() == 0) return t.length();
    if (t.length() == 0) return s.length();

    vector<int> v0(t.length() + 1);
    vector<int> v1(t.length() + 1);

    for (int i = 0; i < v0.size(); i++) {
        v0[i] = i;
    }
    for (int i = 0; i < s.length(); i++) {
        v1[0] = i + 1;
        for (int j = 0; j < t.length(); j++) {
            int cost = (s[i] == t[j]) ? 0 : 1;
            v1[j + 1] = minimum(v1[j] + 1, v0[j + 1] + 1, v0[j] + cost);
        }
        for (int j = 0; j < v0.size(); j++) {
            v0[j] = v1[j];
        }
    }

    return v1[t.length()];
}

void add_recursive(const string& word, set<string> &bag, const vector<string> &words) {
    bag.insert(word);
    for(int i=0; i<words.size(); i++) {
        if(words[i] == word) continue;
        if(bag.count(words[i])) continue;
        int distance = levenshtein_distance(words[i], word);
        if(distance == 1) {
            add_recursive(words[i], bag, words);
        }
    }
}

int main(int argc, char *argv[]) {
    vector<string> test_cases;
    vector<string> words;
    bool read_test_cases = true;
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        if(line == "END OF INPUT") {
            read_test_cases = false;
            continue;
        }
        if(read_test_cases) {
            test_cases.push_back(line);
        } else {
            words.push_back(line);
        }
    }

    for(int i=0; i<test_cases.size(); i++) {
        set<string> bag;
        add_recursive(test_cases[i], bag, words);
        cout << bag.size() << endl;
    }
    return 0;
}
