#include <bits/stdc++.h>
using namespace std;

bool checkPalidrome(int i, string &str){
    if(i>=str.size()/2) return true;
    if(str[i] != str[str.size()-i-1]) return false;
    return checkPalidrome(i+1, str);
}

int main()
{
    string str;
    cin>>str;
    cout<<checkPalidrome(0, str)<<endl;
    
    return 0;
}

// tc :- n/2   sc:- auxilary stack space n/2