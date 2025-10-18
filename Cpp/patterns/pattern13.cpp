// Pattern 13: Continuous number pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// 1 
// 2 3
// 4 5 6
// 7 8 9 10

void continuousNumber (int n){
    int num=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<num<<" ";
            num++;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    continuousNumber(n);
    return 0;
}