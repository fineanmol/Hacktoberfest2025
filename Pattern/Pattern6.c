/*
  1
 22
333
*/

#include <stdio.h>

int main() {
    int rows = 3;

    for (int i = 1; i <= rows; i++) {
        // Print spaces for right alignment
        for (int s = 1; s <= rows - i; s++) {
            printf(" ");
        }
        // Print the current row number i, i times
        for (int j = 1; j <= i; j++) {
            printf("%d", i);
        }
        printf("\n");
    }

    return 0;
}
