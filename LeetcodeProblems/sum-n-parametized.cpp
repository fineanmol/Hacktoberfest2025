#include <bits/stdc++.h>
using namespace std;

void printSum(int n, int sum){
    if(n<1){
        cout<<sum<<endl;
        return;
    }
    printSum(n-1, sum+n);
}

int main()
{
    int n;
    cin>>n;
    printSum(n,0);
    return 0;
}