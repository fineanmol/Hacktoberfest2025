// Pattern 17: Alphabet pyramid pattern
#include<bits/stdc++.h>
using namespace std;

// n=4
//       A 
//     A B A
//   A B C B A 
// A B C D C B A

void alphabetPyramid(int n){
    for(int i=1;i<=n;i++){
        //leading spaces
        for(int j=1;j<=n-i;j++){
            cout<<"  ";
        }

        char ch='A';
        //breakpoint to get symmetry
        int breakpoint=(2*i-1)/2;

        for(int j=1;j<=2*i-1;j++){        
            cout<<ch<<" ";
            
            if(j<=breakpoint) ch++;
            else ch--;
        }

        cout<<endl;
    }
}

int main(){
    int n;
    cin>>n;
    alphabetPyramid(n);
    return 0;
}