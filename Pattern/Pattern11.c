/*
123
 12
  1
*/

#include <stdio.h>

int main() {
    int rows = 3;

    for (int i = 0; i < rows; i++) {
        // Print leading spaces
        for (int s = 0; s < i; s++) {
            printf(" ");
        }
        // Print numbers from 1 to (rows - i)
        for (int j = 1; j <= rows - i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
