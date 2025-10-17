#include<bits/stdc++.h>
using namespace std;
int largest(vector<int> &arr) {
        int largest=INT_MIN;
        for(int i=0; i< arr.size(); i++){
            if(arr[i]>largest){
                largest = arr[i];
            }
        }
        return largest;
    }
int main(){
    vector<int> arr = {2,3,1,5,4};
    cout<<largest(arr);
    return 0;
}