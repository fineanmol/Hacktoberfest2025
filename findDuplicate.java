class Solution {
    public int findDuplicate(int[] nums) {
        HashMap<Integer,Integer> m1=new HashMap<>();

        for(int a:nums){
            m1.put(a,m1.getOrDefault(a,0)+1);
        }

        for(int i:m1.keySet()){
            if(m1.get(i)>1){
                return i;
            }
        }
        return -1;
    }
