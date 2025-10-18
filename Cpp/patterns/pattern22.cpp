// Pattern 22: Number concentric square pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4

void concentricSquare(int n){
    for(int i=0;i<2*n-1;i++){
        for(int j=0;j<2*n-1;j++){
            int top=i;
            int left=j;
            int bottom=(2*n-2)-i;
            int right=(2*n-2)-j;
            cout<<(n-min(min(top,bottom),min(left,right)))<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    concentricSquare(n);
    return 0;
}