// Pattern 9: Diamond pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
//       * 
//     * * *
//   * * * * *
// * * * * * * *
//   * * * * *
//     * * *
//       *

void diamond(int n){
    //upper pyramid
    for(int i=1;i<=n;i++){
        for(int l=1;l<=n-i;l++){
            cout<<"  ";
        }
        for(int j=1;j<=2*i-1;j++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
    
    //lower inverted pyramid
    for(int i=1;i<=n;i++){
        for(int j=0;j<=i-1;j++){
            cout<<"  ";
        }
        for(int j=0;j<2*(n-i)-1;j++){
            cout<<"* ";
        }
    
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    diamond(n);
    return 0;
}