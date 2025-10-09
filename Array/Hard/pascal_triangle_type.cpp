#include <bits/stdc++.h>
using namespace std;

// type-I return return the element of n rows and i element j
// first way is to used factorial formula  by (n-1Ci-1) and reduce time Comp. by using reduce formula of combination

long long nCr(long long n, long long r)
{
          long long res = 1;
          for (int i = 0; i < r; i++)
          {
                    res = res * (n - i);
                    res = res / (i + 1);
          }
          return res;
}

// time-> O(r)  and space-> O(1)
long long pascal_triangles_type01(long long row, long long ele)
{
          return nCr(row - 1, ele - 1);
}

// type-2  ->  return the entire rows
// brute force approach timeO(n*r)i.e approach O(n^2). space-> O(n) (O(n) in returning the value we can say it O(1) also)
vector<int> pascal_triangles_type02_01(long long row)
{
          vector<int> nums;
          for (int i = 1; i <= row; i++)
          {
                    nums.push_back(pascal_triangles_type01(row, i));
          }
          return nums;
}
// optimal solution  time ->O(n) and  space->O(1)
vector<int> pascal_triangles_type02_02(long long row)
{
          vector<int> nums;
          int ans = 1;
          nums.push_back(ans);
          for (int i = 1; i <= row; i++)
          {
                    ans = ans * (row - i);
                    ans = ans / i;
                    nums.push_back(ans);
          }
          return nums;
}

// type-> 3 generating entire pascal triangle
// brute force approach  time->O(n*n*r) i.e O(n^3) and space->O(n^2)(in returning  otherwise O(1))
vector<vector<int>> pascal_triangles_type03_01(long long row)
{
          vector<vector<int>> vec;
          for (int i = 1; i <= row; i++)
          {
                    vector<int> v;
                    for (int j = 1; j <= i; j++)
                    {
                              v.push_back(nCr(i - 1, j - 1));
                    }
                    vec.push_back(v);
                    v.clear();
          }

          return vec;
}
// optimal soution  time->O(n^2) space ->O(n^2)(in returning  otherwise O(1))
vector<vector<int>> pascal_triangles_type03_02(long long row)
{
          vector<vector<int>> vec;
          for (int i = 1; i <= row; i++)
          {
                    vec.push_back(pascal_triangles_type02_02(i));
          }
          return vec;
}

int main()
{
          // type 1
          // long long res = pascal_triangles_type01(6, 4);
          // cout << res;
          // type 2
          // int n;
          // cout << "Enter row : ";
          // cin >> n;
          // vector<int> vec;
          // vec = pascal_triangles_type02_02(n);
          // for (int i = 0; i < vec.size() - 1; i++)
          // {
          //           cout << vec[i] << "  ";
          // }

          // type 3
          int n;
          cout << "Enter row : ";
          cin >> n;
          vector<vector<int>> num = pascal_triangles_type03_01(n);
          
          for (auto it1 : num)
          {
                    for (auto it2 : it1)
                    {
                              cout << it2 << " ";
                    }
                    cout << endl;
          }
          return 0;
}