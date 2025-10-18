// Pattern 7: Pyramid pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
//       * 
//     * * *
//   * * * * *
// * * * * * * *

void pyramid(int n){
    for(int i=1;i<=n;i++){
        //print leading spaces
        for(int l=1;l<=n-i;l++){
            cout<<"  ";
        }
        //print stars
        for(int j=1;j<=2*i-1;j++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    pyramid(n);
    return 0;
}