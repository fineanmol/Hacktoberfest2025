//Intersection of two sorted array

#include<bits/stdc++.h>
using namespace std;
vector<int> intersection(vector<int> &arr1, vector<int> &arr2){
        int n1=arr1.size();
        int n2=arr2.size();
        vector<int> inter;
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                i++;
            }
            else if(arr1[i]>arr2[j]){
                j++;
            }
            else{
                if(inter.size()==0 || inter.back()!=arr1[i])
                inter.push_back(arr1[i]);
                i++;
                j++;
            }
        }
        return inter;
    }

int main(){
    vector<int> a={1,3,5,7,8,9,99,99},b={3,5,7,8,8,8};
    vector<int> inter=intersection(a,b);
    for(auto it:inter){
        cout<<it<<" ";
    }
}