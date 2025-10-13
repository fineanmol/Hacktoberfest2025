/*
  1
 23
456  
*/

#include <stdio.h>

int main() {
    int num = 1;
    int rows = 3;

    for (int i = 1; i <= rows; i++) {
        // Print spaces before numbers
        for (int s = 1; s <= rows - i; s++) {
            printf(" ");
        }
        // Print numbers in each row
        for (int j = 1; j <= i; j++) {
            printf("%d", num);
            num++;
        }
        printf("\n");
    }

    return 0;
}
