#include <bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>> &mat, int i, int m)
{
          for (int j = 0; j < m; j++)
          {
                    if (mat[i][j] != 0)
                    {
                              mat[i][j] = -1;
                    }
          }
}
void markColumn(vector<vector<int>> &mat, int j, int n)
{
          for (int i = 0; i < n; i++)
          {
                    if (mat[i][j] != 0)
                    {
                              mat[i][j] = -1;
                    }
          }
}

// brute force approach :::status -> not working
// time ->O(n^3) and space->O(1)
vector<vector<int>> zeroMatrix01(vector<vector<int>> &matrix, int n, int m)
{
          // Write your code here.
          for (int i = 0; i < n; i++)
          {
                    for (int j = 0; j < m; j++)
                    {
                              if (matrix[i][j] == 0)
                              {
                                        markRow(matrix, i, m);
                                        markColumn(matrix, j, n);
                              }
                    }
          }
          for (int i = 0; i < n; i++)
          {
                    for (int j = 0; j < m; j++)
                    {
                              if (matrix[i][j] == -1)
                              {
                                        matrix[i][j] = 0;
                              }
                    }
          }
          return matrix;
}

// better solution  time->O(n^2) space->O(m+n)
vector<vector<int>> zeroMatrix02(vector<vector<int>> &matrix, int n, int m)
{
          // Write your code here.
          int row[n] = {0};
          int column[m] = {0};
          for (int i = 0; i < n; i++)
          {
                    for (int j = 0; j < m; j++)
                    {
                              if (matrix[i][j] == 0)
                              {
                                        row[i] = 1;
                                        column[j] = 1;
                              }
                    }
          }
          for (int i = 0; i < n; i++)
          {
                    for (int j = 0; j < m; j++)
                    {
                              if (row[i] == 1 || column[j] == 1)
                              {
                                        matrix[i][j] = 0;
                              }
                    }
          }
          return matrix;
}

int main()
{

          return 0;
}