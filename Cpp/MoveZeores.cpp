//Move zeroes to the end of the array
#include<bits/stdc++.h> 
using namespace std;
 void moveZeroes(vector<int>& nums) {
        int i=0;
        for (int j=0;j<nums.size(); j++){
            if(nums[j]==0){
                i=j;
                break;
            }
        }
        for(int j=i+1;j<nums.size();j++){
            if(nums[i]!=nums[j]){
                swap(nums[i],nums[j]);
                i++;
            }
            
        }

    }
int main(){
    vector<int> nums={0,1,0,3,12};  
    moveZeroes(nums);
    for(auto i : nums){
        cout<<i<<" ";   
    }
    return 0;
}