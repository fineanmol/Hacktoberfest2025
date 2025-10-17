#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> v){
    int n = v.size();
    int key,j;
    for (int i=1;i<n-1;i++){
        key=v[i];
        j=i-1;
        while(j>=0 && v[j]>key){
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
    }
    for (auto it:v){
        cout<<it<<" ";
    }
}
int main(){
    vector<int> v={11,22,66,44,99,23,76};
    insertion_sort(v);
    return 0;
}