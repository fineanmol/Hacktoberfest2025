//Pattern 4: Repeated number triangle
#include<bits/stdc++.h>
using namespace std;

// n=4
// 1 
// 2 2
// 3 3 3
// 4 4 4 4

void repeatedNumberTriangle(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    repeatedNumberTriangle(n);
    return 0;
}