/*
1
22
333
*/

#include <stdio.h>

int main() {
    for (int i = 1; i <= 3; i++) {       // For each row
        for (int j = 1; j <= i; j++) {   // Print the current row number i, i times
            printf("%d", i);
        }
        printf("\n"); // Move to next line after each row
    }
    return 0;
}
