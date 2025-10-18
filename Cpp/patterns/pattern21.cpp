// Pattern 21: Hollow square pattern
#include<bits/stdc++.h>
using namespace std;

// 4
// * * * * 
// *     *
// *     *
// * * * *

void hollowSquare(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1||i==n||j==1||j==n){
                cout<<"* ";//boundary
            }
            else cout<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    hollowSquare(n);
    return 0;
}
