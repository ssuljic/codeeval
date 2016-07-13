#include <stdio.h>
#include <inttypes.h>
int main(int argc, const char * argv[]) {
    volatile uint32_t i=0x01234567;
    if(((*((uint8_t*)(&i))) == 0x67) == 0) {
        printf("BigEndian");
    } else {
        printf("LittleEndian");
    }
}