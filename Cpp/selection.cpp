#include <bits/stdc++.h>
using namespace std;

void selection_sort(vector<int> v){
    int n = v.size();
    for (int i=0;i<n-1;i++){
        int minIndex=i;   // i th element is the smallest
        for(int j=i+1;j< n;j++){
            if (v[j]<v[minIndex])
                minIndex=j;
        }
        swap(v[i],v[minIndex]);
    }
    for (auto it:v){
        cout<<it<<" ";
    }
}

void display(vector<int> v){
    cout<<"Result: ";
    for (auto it:v){
        cout<<it<<" ";
    }
}
int main(){
    vector<int> v={11,22,66,44,99,23,76};
    selection_sort(v);
    //display(v);
    return 0;
}
