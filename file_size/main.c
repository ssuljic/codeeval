#include <stdio.h>

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    fseek(file, 0, SEEK_END);
    unsigned long len = (unsigned long)ftell(file);
    fclose(file);
    printf("%lu\n", len);
    return 0;
}