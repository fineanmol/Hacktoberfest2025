// Pattern 10: Double half triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// * 
// * *
// * * *
// * * * *
// * * *
// * *
// *

void doubleHalfTriangle(int n){
    for(int i=1;i<=2*n-1;i++){
        //if else condition for stars=i and stars=2*n-i
        if(i<=n){
            for(int j=1;j<=i;j++){
                cout<<"* ";
            }
        }
        else{
            for(int j=1;j<=2*n-i;j++){
                cout<<"* ";
            }
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    doubleHalfTriangle(n);
    return 0;
}