// Pattern 15: Inverted alphabet triangle pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// A B C D 
// A B C
// A B
// A

void invertedAlphabetTriangle(int n){
    for(int i=1;i<=n;i++){
        for(char ch='A';ch<='A'+(n-i);ch++){
            cout<<ch<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    invertedAlphabetTriangle(n);
    return 0;
}