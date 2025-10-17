//Print majority element > n/2 and if not present rerurn -1

#include<bits/stdc++.h>
using namespace std;

 int majorityElement(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        int el=arr[0];
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                el=arr[i];
            }
            else if(el==arr[i])
                cnt++;
            else
                cnt--;
            
        }
        cnt=0;
        for(int i=0;i<n;i++){
            if(el==arr[i])
                cnt++;
        }
        if(cnt>n/2)
            return el;
        
        return -1;
    }

int main(){
    vector<int> a={2,1,3};
    cout<<majorityElement(a);
    return 0;
}