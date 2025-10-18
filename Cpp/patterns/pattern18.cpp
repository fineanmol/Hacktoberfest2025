// Pattern 18: Alphabet increasing sequence pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
// D 
// C D
// B C D
// A B C D

void alphabetIncreasingSequence(int n){

    for(int i=1;i<=n;i++){
        char ch='A';
        ch=ch+(n-i);

        for(int j=1;j<=i;j++){
            cout<<ch<<" ";
            ch=ch+1;
        }
        cout<<endl;
    }

}

int main(){
    int n;
    cin>>n;
    alphabetIncreasingSequence(n);
    return 0;
}