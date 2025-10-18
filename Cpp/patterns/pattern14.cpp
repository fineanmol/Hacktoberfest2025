// Pattern 14: Alphabet triangle pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// A 
// A B
// A B C
// A B C D

void alphabetTriangle(int n){
    
    for(int i=1;i<=n;i++){
        char temp='A';
        for(int j=1;j<=i;j++){
            cout<<temp<<" ";
            temp++;
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    alphabetTriangle(n);
    return 0;
}