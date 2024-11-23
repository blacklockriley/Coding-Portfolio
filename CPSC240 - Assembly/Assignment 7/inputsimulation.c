#include <stdio.h>
#include <stdlib.h>

int main() {
    char msg1[] = "Input a number (1~9): ";
    char msg2[] = " is a Multiple of 3.";
    char buffer[2];
    char ascii[10];
    int r10 = 0;

    do {
        printf("%s", msg1);
        scanf("%1s", buffer);
        ascii[r10] = buffer[0];
        r10++;
    } while (r10 < 9);

    r10 = 0;
    do {
        int num = ascii[r10];
        if (num % 3 == 0) {
            printf("%c%s\n", ascii[r10], msg2);
        }
        r10++;
    } while (r10 < 9);

    return 0;
}