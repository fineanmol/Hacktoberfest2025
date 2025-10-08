#include<bits/stdc++.h>
using namespace std;

int printFibo(int n){
    if(n<=1) return n;
    return printFibo(n-1)+printFibo(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<printFibo(n)<<" ";
    return 0;
}

// tc :- (2)pow n. -> exponential 
