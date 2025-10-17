#include<bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        int n1=a.size();
        int n2=b.size();
        vector<int> un;
        int i=0,j=0;
        while(i<n1 && j<n2){
           if(a[i]<=b[j]){
               if(un.size()==0 || un.back()!=a[i]){
                   un.push_back(a[i]);
               }
               i++;
           } 
           else{
              if(un.size()==0 || un.back()!=b[j]){
                   un.push_back(b[j]);
               }
               j++; 
           }
        }
        
        while(i<n1){
            if(un.size()==0 || un.back()!=a[i]){
                   un.push_back(a[i]);
               }
            i++;
        }
        while(j<n2){
            if(un.size()==0 || un.back()!=b[j]){
                   un.push_back(b[j]);
               }
            j++;
        }
        return un;
    }
int main(){
    vector<int> a={4,5,7,8,8,8},b={1,2,3,5,6,6,6};
    vector<int> un=findUnion(a,b);
    for(auto it:un){
        cout<<it<<" ";
    }
}