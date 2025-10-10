class Solution {
    public int[] twoSum(int[] nums, int target) {
        int op[] = {-1,-1};
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<nums.length; i++){
            int diff = target - nums[i];
            if(map.containsKey(diff)){
                op[0] = map.get(diff);
                op[1] = i;
                return op;
            }

            map.put(nums[i], i);
        }

        return op;
    }
}
