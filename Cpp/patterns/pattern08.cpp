// Pattern 8: Inverted pyramid pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// * * * * * * * 
//   * * * * *
//     * * *
//       *

void invertedPyramid(int n){
    for(int i=0;i<n;i++){
        //leading spaces
        for(int j=0;j<=i-1;j++){
            cout<<"  ";
        }
        //stars
        for(int j=0;j<2*(n-i)-1;j++){
            cout<<"* ";
        }
        
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    invertedPyramid(n);
    return 0;
}