#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

void move_Zero_to_end(int arr[], int n)
{
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if (j == -1)
    {
        return;
    }
    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}
int main()
{
    int n;
    cout << "Enter the number of element : ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << (i + 1) << " value : ";
        cin >> arr[i];
    }
    move_Zero_to_end(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << ", ";
    }
    

    return 0;
}