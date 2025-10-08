#include <bits/stdc++.h>
using namespace std;

void f(string name, int len){
    if(len>=5) return;
    cout<<name<<" ";
    len++;
    f(name, len);
}


int main()
{
    int len = 0;
    string name = "abc";
    f(name, len);
    return 0;
}