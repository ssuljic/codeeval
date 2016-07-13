#include <iostream>
#include <fstream>
using namespace std;

bool isPrime(int n) {
    if(n < 2) return false;
    if(n < 4) return true;
    if(n % 2 == 0 || n % 3 == 0) return false;

    int i = 5;
    while(i * i <= n) {
        if(n % i == 0 || n % (i+2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        int num = atoi(line.c_str());
        bool commaPrepended = false;
        for(int i=2; i<num; i++) {
            bool prime = isPrime(i);
            if(prime) {
                if(commaPrepended) {
                    cout << ",";
                } else {
                    commaPrepended = true;
                }
                cout << i;
            }
        }
        cout << "\n";
    }
    return 0;
}