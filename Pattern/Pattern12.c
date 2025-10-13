/*
123
 23
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
        // Print numbers from i+1 to rows
        for (int j = i + 1; j <= rows; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
