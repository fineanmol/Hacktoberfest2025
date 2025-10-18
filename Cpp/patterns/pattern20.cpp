// Pattern 20: Butterfly pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// *             * 
// * *         * *
// * * *     * * *
// * * * * * * * *
// * * *     * * *
// * *         * *
// *             *

void butterflyPattern(int n){
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n) stars=2*n-i;

        //left wing
        for(int j=1;j<=stars;j++){
            cout<<"* ";
        }
        //middle spaces
        for(int j=1;j<=2*(n-stars);j++){
            cout<<"  ";
        }
        //right wing
        for(int j=1;j<=stars;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    butterflyPattern(n);
    return 0;
}