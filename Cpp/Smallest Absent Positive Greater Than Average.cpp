class Solution {
public:
    int smallestAbsent(vector<int>& nums) {
        int avg = 0;
        for(int x: nums){
            avg += x;
        }
        avg = avg / (int)nums.size();
        cout<<"Average"<<avg;
        int check = avg + 1;
        if(avg < 0)check = 1;
        while(true){
            if(find(nums.begin(),nums.end(),check) == nums.end())
            {
                return check;
            }
            check++;
        }
        
        return 0;
    }   
};
