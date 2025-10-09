#include <bits/stdc++.h>
using namespace std;

// brute force approach time->O(n^2) and  space->O(1)
int number_that_appear_once01(vector<int> nums)
{
          int temp, count;
          int n = nums.size();
          for (int i = 0; i < n; i++)
          {
                    temp = nums[i];
                    count = 0;
                    for (int j = 0; j < n; j++)
                    {
                              if (temp == nums[j])
                              {
                                        count++;
                              }
                    }
                    if (count == 1)
                    {
                              return temp;
                    }
          }
          // return 0;
}

// better solution using hashed tabled time->O(n) and space->O(n);
// this solution will fail in large input  and also depends upon input
int number_that_appear_once02(vector<int> nums)
{
          int maxi = 0;
          for (int i = 0; i < nums.size(); i++)
          {
                    maxi = max(maxi, nums[i]);
          }
          int hash[maxi + 1] = {0};
          for (int i = 0; i < nums.size(); i++)
          {
                    hash[nums[i]]++;
          }
          for (int i = 0; i <= maxi; i++)
          {
                    if (hash[i] == 1)
                    {
                              return i;
                    }
          }
          // for (int i = 0; i <=nums.size(); i++) // works similiar but  depend upon input which for for should be used.
          // {
          //           if (hash[i] == 1)
          //           {
          //                     return i;
          //           }
          // }
}

// using map  time->O(nlogn) in case of map and O(n) is case of unordered map except in worst case of unordered map in thar case time->O(n^2)((but very rarely happen))
int number_that_appear_once03(vector<int> nums)
{
          unordered_map<long long, int> mpp;
          for (int i = 0; i < nums.size(); i++)
          {
                    mpp[nums[i]]++;
          }
          for (auto it : mpp)
          {
                    if (it.second == 1)
                    {
                              return it.first;
                    }
          }
}
// optimal solution but req element should occur only once and other member occur twice(or even) to (satisfy the XOR and makes n^n=0 and m(single will remain))
// time->O(n) and space->O(1).
int number_that_appear_once04(vector<int> nums)
{
          int n = nums.size();
          int req_element = 0;
          for (int i = 0; i < n; i++)
          {
                    req_element = req_element ^ nums[i];
          }
          return req_element;
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
          int num = number_that_appear_once04(v);
          cout << endl;
          cout << "Number that appears once :  " << num;

          return 0;
}