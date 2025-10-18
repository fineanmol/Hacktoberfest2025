//Pattern 2: Left triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// * 
// * *
// * * *
// * * * *

void leftTriangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<"* ";
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    leftTriangle(n);
    return 0;
}