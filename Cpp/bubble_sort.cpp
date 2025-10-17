#include <bits/stdc++.h>
using namespace std;

void bubble_sort(vector<int> v){
    int n=v.size();
    for(int i=0;i<n-1;i++){
        for (int j=0;j<n-i-1;j++){
            if(v[j]>v[j+1])
                swap(v[j],v[j+1]);
        }
    }
    for(auto it:v){
        cout<<it<<" ";
    }
}
int main(){
    vector<int> v={55,44,33,22,11};
    bubble_sort(v);
    return 0;
}