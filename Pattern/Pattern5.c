/*
  1
 12
123
*/

#include <stdio.h>

int main() {
    int rows = 3;

    for (int i = 1; i <= rows; i++) {
        // Print spaces to right-align the numbers
        for (int s = 1; s <= rows - i; s++) {
            printf(" ");
        }
        // Print numbers from 1 up to the current row number
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }

    return 0;
}
