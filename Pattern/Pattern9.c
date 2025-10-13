/*
123
23
3
*/

#include <stdio.h>

int main() {
    int rows = 3;

    for (int i = 0; i < rows; i++) {
        for (int j = i + 1; j <= rows; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
