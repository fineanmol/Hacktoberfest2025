/*
1
12
123
*/

#include <stdio.h>

int main() {
    for (int i = 1; i <= 3; i++) {       // For each row
        for (int j = 1; j <= i; j++) {   // Print numbers from 1 up to the current row number
            printf("%d", j);
        }
        printf("\n"); // Move to next line after each row
    }
    return 0;
}
