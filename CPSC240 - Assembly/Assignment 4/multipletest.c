#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned short num = 65535;
    unsigned short mul_3 = 0;
    unsigned short other = 0;

    if ((num % 3 == 0) && (num % 5 != 0)) {
        mul_3++;
    } else {
        other++;
    }
    printf("num: %d, mul_3: %d, other: %d\n", num, mul_3, other);
    return 0;
}