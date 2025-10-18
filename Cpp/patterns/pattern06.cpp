// Pattern 6: Number inverse triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// 1 2 3 4 
// 1 2 3
// 1 2
// 1

void numberInverseTriangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    numberInverseTriangle(n);
    return 0;
}