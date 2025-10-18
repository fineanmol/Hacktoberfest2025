// Pattern 16: Repeated alphabet lines
#include<bits/stdc++.h>
using namespace std;

// n=4
// A 
// B B
// C C C
// D D D D

void repeatedAlphabetTriangle(int n){
    char temp='A';
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cout<<temp<<" ";
        }
        cout<<endl;
        temp=temp+1; 
    }
}

int main(){
    int n;
    cin>>n;
    repeatedAlphabetTriangle(n);
    return 0;
}