// Pattern 5: Inverse left triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// * * * * 
// * * *
// * *
// *

void inverseLeftHalfTriangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    inverseLeftHalfTriangle(n);
    return 0;
}