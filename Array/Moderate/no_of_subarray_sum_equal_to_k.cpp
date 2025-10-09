#include <bits/stdc++.h>
using namespace std;

// brute force time->o(n)  and space->O(1)
int findAllSubarraysWithGivenSum01(vector<int> &arr, int k)
{
          int n = arr.size();
          int count = 0;
          int sum;
          for (int i = 0; i < n; i++)
          {

                    for (int j = i; j < n; j++)
                    {
                              sum = 0;
                              for (int k = i; k <= j; k++)
                              {
                                        sum += arr[k];
                              }
                              if (sum == k)
                              {
                                        count++;
                              }
                    }
          }
          return count;
}

// better solution time->O(n^2 space->O(1).
int findAllSubarraysWithGivenSum02(vector<int> &arr, int k)
{
          int n = arr.size();
          int count = 0;
          int sum;
          for (int i = 0; i < n; i++)
          {
                    sum = 0;
                    for (int j = i; j < n; j++)
                    {
                              sum += arr[j];
                              if (sum == k)
                              {
                                        count++;
                              }
                    }
          }
          return count;
}

int main()
{

          return 0;
}