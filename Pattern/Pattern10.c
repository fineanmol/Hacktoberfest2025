/*
321
 32
  3
*/

#include <stdio.h>

int main() {
    int rows = 3;

    for (int i = 0; i < rows; i++) {
        // Print leading spaces
        for (int s = 0; s < i; s++) {
            printf(" ");
        }
        // Print numbers from 3 - i down to 1
        for (int j = rows - i; j >= 1; j--) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
