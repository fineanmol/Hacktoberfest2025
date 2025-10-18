//Pattern 1: Square block
#include<bits/stdc++.h>
using namespace std;

// n=4
// * * * * 
// * * * *
// * * * *
// * * * *
void squareblock(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    squareblock(n);
    return 0;
}
