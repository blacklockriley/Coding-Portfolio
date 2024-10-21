#include <stdio.h>

int main(int argc, char *argv[]) {
    unsigned short array[7] = {12, 1003, 6543, 24680, 789, 30123, 32766};
    unsigned short even[7] = {0};
    unsigned long rsi = 0;
    unsigned long rdi = 0;

    while (rsi < 7) {
        if (array[rsi] % 2 == 0) {
            even[rdi] = array[rsi];
            rdi++;
        }
        rsi++;
    }
    printf("array: ");
    for (int i = 0; i < 7; i++) {
        printf("%d ", array[i]);
    }
    printf("\neven: ");
    for (int i = 0; i < rdi; i++) {
        printf("%d ", even[i]);
    }
    printf("\n");
    return 0;
}