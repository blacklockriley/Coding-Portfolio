#include <stdio.h>

int main(int argc, char *argv[]) {
    char * string = "1+2+3+...+99=";
    int sum = 0;

    for(int i = 1; i < 100; i++) {
        sum += i;
    }

    printf("%s%d\n", string, sum);

    return 0;
}