#include <bits/stdc++.h>
using namespace std;

int max_count_of_one(vector<int> nums)
{
          int maxi = 0;
          int count = 0;
          for (int i = 0; i < nums.size(); i++)
          {
                    if (nums[i] == 1)
                    {
                              count++;
                              maxi = max(maxi, count);
                    }
                    else
                    {
                              count = 0;
                    }
          }
          return maxi;
}

int main()
{
          vector<int> v;
          int n;
          cout << "enter n -> no. of element  : ";
          cin >> n;
          cout << " Enter element \n";
          for (int i = 0; i < n; i++)
          {
                    int m;
                    cout << (i + 1) << " value : ";
                    cin >> m;
                    v.push_back(m);
          }
          cout << endl;
          int maximum_one = max_count_of_one(v);
          cout << "maximum no. of one :  " << maximum_one;
          return 0;
}