// Pattern 19: Hourglass pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// * * * * * * * * 
// * * *     * * *
// * *         * * 
// *             *
// *             *
// * *         * *
// * * *     * * *
// * * * * * * * *

void hourglass(int n){

    //upper half
    for(int i=1;i<=n;i++){

        for(int j=1;j<=n-i+1;j++){
            cout<<"* ";
        }
        for(int j=1;j<=2*(i-1);j++){
            cout<<"  ";
        }
        for(int j=n-i+1;j>=1;j--){
            cout<<"* ";
        }
        cout<<endl;
    }

    //lowerhalf
    for(int i=1;i<=n;i++){
        
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        for(int j=1;j<=2*(n-i);j++){
            cout<<"  ";
        }
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    hourglass(n);
    return 0;
}