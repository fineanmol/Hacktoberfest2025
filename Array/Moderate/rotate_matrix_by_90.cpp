#include <bits/stdc++.h>
using namespace std;

// brute force approach
// complete this

// optimal solution time-> O(n^2)  space->O(1).
void rotateMatrix02(vector<vector<int>> &matrix)
{
          // Write your code here.
          int n = matrix.size();
          for (int i = 0; i < n - 1; i++)
          {
                    for (int j = i + 1; j < n; j++)
                    {
                              swap(matrix[i][j], matrix[j][i]);
                    }
          }
          for (int i = 0; i < n; i++)
          {
                    reverse(matrix[i].begin(), matrix[i].end());
          }
}

int main()
{

          return 0;
}