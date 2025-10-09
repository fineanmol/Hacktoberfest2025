#include <bits/stdc++.h>
using namespace std;

// problems : to find the missing number from 1 to n;

// brute force approach time->O(n^2) && space->O(1)
int missing_number01(vector<int> vec, int N)
{
    int flag;
    for (int i = 1; i <= N; i++)
    {
        flag = 0;
        for (int j = 0; j < vec.size(); j++)
        {
            if (vec[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            return i;
        }
    }
    return -1;
}
// by use of hash table
// better solution  time->O(n) && space->O(n)
int missing_number02(vector<int> arr, int N)
{
    int hash[N + 1] = {0};
    for (int i = 0; i <= N; i++)
    {
        hash[arr[i]] = 1;
    }
    for (int i = 1; i <= N; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// optimal solution 01 by sum
// time->O(n) && space->O(1);
int missing_number03(vector<int> arr, int N)
{
    int Tsum = (N * (N + 1)) / 2;
    int Fsum = 0;
    for (int i = 0; i < N - 1; i++)
    {
        Fsum += arr[i];
    }
    return Tsum - Fsum;
}
// XOR approach  example-> 0^n=n, n^n=0;
int missing_number04(vector<int> arr, int N)
{
    int n = arr.size(); // n=N-1;
    int xor1 = 0, xor2 = 0;
    // for (int i = 1; i <= N; i++)
    // {
    //     xor1 = xor1 ^ i;
    // }
    for (int i = 0; i < n; i++) // n=N-1
    {
        xor1 = xor1 ^ (i + 1);
        xor2 = xor2 ^ arr[i];
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main()
{
    vector<int> v;
    int n, miss_num;
    cout << "Enter n -> no. of element  : ";
    cin >> n;
    cout << " Enter element \n";
    for (int i = 0; i < n - 1; i++)
    {
        int m;
        cout << (i + 1) << " value : ";
        cin >> m;
        v.push_back(m);
    }
    miss_num = missing_number02(v, n);
    cout << "Missing number : " << miss_num;
    return 0;
}