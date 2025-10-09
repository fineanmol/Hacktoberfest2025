#include <bits/stdc++.h>
using namespace std;
long long nCr(long long n, long long r)
{
     long long ans = 1;
     for (int i = 1; i <= r; i++)
     {
          ans = ans * (n - i + 1);
          ans = ans / i;
     }
     return ans;
}

vector<int> rowGenerate(int n)
{
     n--;
     vector<int> ans;
     for (int i = 0; i <= n; i++)
     {
          int x = nCr(n, i);
          ans.push_back(x);
     }
     return ans;
}

vector<vector<int>> generate(int numRows)
{

     vector<vector<int>> ans;
     int c = nCr(6, 3);
     vector<int> se = rowGenerate(1);
     for (int i = 0; i < se.size(); i++)
     {
          cout << se[i] << " ";
     }

     return ans;
}

int main()
{

     vector<int> se = rowGenerate(5);
     for (int i = 0; i < se.size(); i++)
     {
          cout << se[i] << " ";
     }

     return 0;
}