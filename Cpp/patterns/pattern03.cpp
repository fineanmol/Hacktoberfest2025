// Pattern 3: Left number triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// 1 
// 1 2
// 1 2 3
// 1 2 3 4

void leftNumberTriangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
             cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    leftNumberTriangle(n);
    return 0;
}