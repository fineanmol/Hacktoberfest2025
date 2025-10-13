/*
321
32
3
*/

#include <stdio.h>

int main() {
    int rows = 3;

    for (int i = 1; i <= rows; i++) {
        for (int j = rows; j >= i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
