class Solution {
    public int searchInsert(int[] nums, int target) {
        int start = 0;
        int end = nums.length - 1;
        if(nums[start] >= target) return 0;
        if(nums[end] < target) return end + 1;
        if(nums[end] == target) return end;
        while(end - start >= 2){
            int mid = start + (end - start)/2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target){
                end = mid;
            }else{
                start = mid;
            }

        }
        return end;
    }
}
