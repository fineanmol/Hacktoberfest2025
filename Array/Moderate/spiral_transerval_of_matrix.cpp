#include <bits/stdc++.h>
using namespace std;

// only solution
vector<int> spiralMatrix(vector<vector<int>> &mat)
{
          int n = mat.size();
          int m = mat[0].size();
          vector<int> vec;
          int left = 0;
          int right = m - 1;
          int top = 0;
          int bottom = n - 1;
          while (left <= right && top <= bottom)
          {
                    for (int i = left; i <= right; i++)
                    {
                              vec.push_back(mat[top][i]);
                    }
                    top++;
                    for (int i = top; i <= bottom; i++)
                    {
                              vec.push_back(mat[i][right]);
                    }
                    right--;
                    if (top <= bottom)
                    {
                              for (int i = right; i >= left; i--)
                              {
                                        vec.push_back(mat[bottom][i]);
                              }
                              bottom--;
                    }
                    if (left <= right)
                    {
                              for (int i = bottom; i >= top; i--)
                              {
                                        vec.push_back(mat[i][left]);
                              }
                              left++;
                    }
          }
          return vec;
}

int main()
{

          return 0;
}