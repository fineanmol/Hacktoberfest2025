class Solution {
    public int countSubstr(String s, int k) {
        //  code here
       int n=s.length();
       int ans=0;
       for(int i=0;i<n;i++){
           HashSet<Character> set=new HashSet<>();
           for(int j=i;j<n;j++){
               set.add(s.charAt(j));
               if (set.size() == k) {
                    ans++;
                } else if (set.size() > k) {
                    break; // no need to expand further
                }
           }
       }
       return ans;
    }
}
