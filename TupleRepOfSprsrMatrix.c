#include <stdio.h>
#include <stdlib.h>

int main() {
    int row, col;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &row, &col);

    int arr[5][5], tuple[25 + 1][3];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("Enter the element at position %d %d: ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
    int count=0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] != 0) {
                tuple[count][0] = i;
                tuple[count][1] = j;
                tuple[count][2] = arr[i][j];
                count++;
            }
        }
    }
    tuple[0][0] = row;
    tuple[0][1] = col;
    tuple[0][2] = count - 1;
    printf("\nTuple Representation:\n");
    printf("Row Col Value\n");
    for (int i = 0; i < count; i++) {
        printf("%d   %d   %d\n", tuple[i][0], tuple[i][1], tuple[i][2]);
    }

    return 0;
}
