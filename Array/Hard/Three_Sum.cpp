#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> Three_sum01(int n, vector<int> &arr)
{
          // Write your code here.

          set<vector<int>> st;
          for (int i = 0; i < n; i++)
          {
                    for (int j = i + 1; j < n; j++)
                    {
                              for (int k = j + 1; k < n; k++)
                              {
                                        if (arr[i] + arr[j] + arr[k] == 0)
                                        {
                                                  vector<int> temp = {arr[i], arr[j], arr[k]};
                                                  sort(temp.begin(), temp.end());
                                                  st.insert(temp);
                                        }
                              }
                    }
          }
          vector<vector<int>> ans(st.begin(), st.end());
          return ans;
}

// better solution
// status not working
// time->O(n^2 *logn)
// space->O(n)+O(n)
vector<vector<int>> Three_sum02(int n, vector<int> &arr) // not working runtime issue
{
          set<vector<int>> st;
          for (int i = 0; i < n; i++)
          {
                    set<int> hashset;
                    for (int j = i + 1; j < n; j++)
                    {
                              int thirdEle = -(arr[i] + arr[j]);
                              if (hashset.find(thirdEle) != hashset.end())
                              {
                                        vector<int> v = {arr[i], arr[j], thirdEle};
                                        sort(v.begin(), v.end());
                                        st.insert(v);
                              }
                              hashset.insert(thirdEle);
                    }
                    hashset.clear();
          }
          vector<vector<int>> ans(st.begin(), st.end());
          return ans;
}

// optimal solution
// time->O(nlogn) +O(n^2)
// space-> O(n)
vector<vector<int>> Three_sum03(int n, vector<int> &nums)
{
          vector<vector<int>> ans;
          sort(nums.begin(), nums.end());
          for (int i = 0; i < nums.size(); i++)
          {
                    if (i > 0 && nums[i] == nums[i - 1])
                    {
                              continue;
                    }
                    int j = i + 1;
                    int k = nums.size() - 1;
                    while (j < k)
                    {
                              int sum;
                              sum = nums[i] + nums[j] + nums[k];
                              if (sum < 0)
                              {
                                        j++;
                              }
                              else if (sum > 0)
                              {
                                        k--;
                              }
                              else
                              {
                                        vector<int> temp = {nums[i], nums[j], nums[k]};
                                        ans.push_back(temp);
                                        j++;
                                        k--;
                                        while (j < k && nums[j] == nums[j - 1])
                                        {
                                                  j++;
                                        }
                                        while (j < k && nums[k] == nums[k + 1])
                                        {
                                                  k--;
                                        }
                              }
                    }
          }
          return ans;
}

int main()
{
          int n;
          cout << "Enter n : ";
          cin >> n;
          vector<int> v;
          cout << "Enter the element :  ";
          for (int i = 0; i < n; i++)
          {
                    int temp;
                    cin >> temp;
                    v.push_back(temp);
          }
          vector<vector<int>> num = Three_sum02(n, v);
          cout << "Result are : ";
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