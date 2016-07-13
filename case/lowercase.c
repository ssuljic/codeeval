// #include <iostream>
// #include <fstream>
// using namespace std;

// int main(int argc, char *argv[]) {
//     ifstream stream(argv[1]);
//     string line;
//     int a = 'a';
//     int z = 'z';
//     int difference = 'a' - 'A';
//     while (getline(stream, line)) {
//       for(int i = 0; i < line.size(); i++) {
//         if(line[i] >= a && line[i] <= z && (i == 0 || line[i-1] == ' ')) {
//           line[i] -= difference;
//         }
//       }
//       cout << line << "\n";
//     }
//     return 0;
// }

#include <stdio.h>
int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    int a = 'a';
    int z = 'z';
    int difference = 'a' - 'A';
    int i;

    while (fgets(line, 1024, file)) {
      for(i = 0; line[i]; i++) {
        if(line[i] >= a && line[i] <= z && (i == 0 || line[i-1] == ' ')) {
          line[i] -= difference;
        }
      }
      printf("%s", line);
    }
    return 0;
}