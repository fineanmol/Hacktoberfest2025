class Solution {
    public boolean isPalindrome(int x) {
        String ans=String.valueOf(x);
        String rslt="";
        for(int i=ans.length()-1;i>=0;i--)
        {
            rslt=rslt+ans.charAt(i);
        }
        if(rslt.equals(ans))
        {
            return true;
        }
        return false;
    }
}
