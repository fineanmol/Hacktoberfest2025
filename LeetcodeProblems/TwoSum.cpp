class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        const int sz = nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;

        //One Pass
        for(int i = 0 ; i < sz ; i++){
            int lft = target - nums[i];
            //The complement exists in the map
            if(mp.find(lft) != mp.end()){
                ans.push_back(i);
                ans.push_back(mp[lft]);
                return ans;
            }
            mp[nums[i]] = i;
        }



        // //Two pass
        // for(int i = 0 ; i< sz ; i++){
        //     // insert element and its index
        //     mp[nums[i]] = i;
        // }

        // for(int i = 0 ; i< sz ; i++){
        //     // Check if the sum can be made 
        //    int lft = target - nums[i];
        //   if (mp.find(lft) != mp.end() &&  mp[lft] != i) {
        //    ans.push_back(i);
        //    ans.push_back(mp[lft]);
        //   return ans;

        //    }
        // }


    //     vector<int> twoSum(vector<int>& nums, int target) {
    //     const int sz = nums.size();
    //     vector<int>ans;
    //     for(int i =  0 ; i< sz ; i++){
    //         int lft = target - nums[i];
    //         for(int j = i+1 ; j< sz ; j++){
    //             if(nums[j] == lft){
    //                 ans.push_back(i);
    //                 ans.push_back(j);
    //             }
    //         }
    //     }

        return ans;
    }
};
