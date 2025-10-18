// Pattern 11: Binary triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// 1 
// 0 1
// 1 0 1
// 0 1 0 1

void binaryTriangle(int n){
    for(int i=1;i<=n;i++){
        //start=1 if i is odd else start is 0 and in for loop write start=1-start
        for(int j=1;j<=i;j++){
            if(i%2==0 && j%2==0 || i%2!=0 && j%2!=0){
                cout<<"1 ";
            }
            else{
                cout<<"0 ";
            }
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    binaryTriangle(n);
    return 0;
}