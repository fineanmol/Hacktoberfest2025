#include <bits/stdc++.h>

using namespace std;
/*********--------- n Queen Problem ---------********* */
#define m 4
#define n 4

bool isSafe(int i, int j, int arr[][m])
{
    int n1 = i, m1 = j;
    // row
    for (int k = i - 1; k >= 0; k--)
    {
        if (arr[k][j] == 1)
            return false;
    }

    // left- daigonal
    while (i >= 0 && j >= 0)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j--;
    }
    i = n1;
    j = m1;
    // left- daigonal
    while (i >= 0 && j <= n-1)
    {
        if (arr[i][j] == 1)
            return false;
        i--;
        j++;
    }
    return true;
}

bool maxNumofQueens(int i, int arr[][m])
{
    if (i == n)
    {
    
        cout << " resultant array : " << endl;
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                if(arr[k][l] == 1){
                    cout<<"Q ";
                }else{
                    cout<<"_ ";
                }
            }
            cout << endl;
        }
        cout << endl;
        return false;
    }

    for (int j = 0; j < n; j++)
    {
        if (isSafe(i, j, arr))
        {
            arr[i][j] = 1;
            
            bool isPlace = maxNumofQueens(i + 1, arr);

            if (isPlace)
            {
                return true;
            }
            arr[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int arr[n][m] = {0};

    bool ans = maxNumofQueens(0, arr);
}