// Pattern 12: Number mirror pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// 1             1 
// 1 2         2 1
// 1 2 3     3 2 1
// 1 2 3 4 4 3 2 1

void numberMirror(int n){
    for(int i=1;i<=n;i++){
        //left side numbers
        for(int j=1;j<=i;j++){
            cout<<j<<" ";
        }

        //middle spaces
        for(int j=1;j<=2*(n-i);j++){
            cout<<"  ";
        }

        //right side numbers(in reverse)
        for(int j=i;j>=1;j=j-1){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    numberMirror(n);
    return 0;
}