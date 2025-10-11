/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

*/

#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &arr[i]);
    }
    int k;
    scanf("%d", &k);
    int max = arr[0];
    for (int i = 0; i < n; i++) 
    {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    int countarr[max + 1] = {0};
    for (int i = 0; i < n; i++) 
    {
        countarr[arr[i]]++;
    }
    for (int t = 0; t < k; t++) 
    {
        int maxFreq = 0;
        int num = -1;
        for (int i = 0; i <= max; i++) 
        {
            if (countarr[i] > maxFreq) 
            {
                maxFreq = countarr[i];
                num = i;
            }
        }
        if (num == -1) break; 
        printf("%d ", num);      
        countarr[num] = 0;       
    }
    return 0;
}

