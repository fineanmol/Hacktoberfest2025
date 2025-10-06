class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
          int n = nums2.length;
        int m = nums1.length;
        int [] ansall = new int [m];
        int [] ans = new int [n];
        Stack<Integer>st = new Stack<>();
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums2[i]> st.peek()) {
                st.pop();
            }
            if(st.empty())
            {
                ans[i]=-1;
            }
            else
            {
                ans[i]=st.peek();
            }
            st.push(nums2[i]);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(nums1[i]==nums2[j])
                {
                    ansall[i]= ans[j];
                }
            }
        }
        return ansall;
    
    }
}
