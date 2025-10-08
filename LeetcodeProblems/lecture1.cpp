#include <bits/stdc++.h>
using namespace std;

void f(int n){
    if(n==4) return;
    cout<<n<<" ";
    n++;
    f(n);
}

int main()
{
    int n = 0;
    f(n);
    return 0;
}