class Solution {
    public String multiplyStrings(String s1, String s2) {
        boolean neg = (s1.charAt(0) == '-') ^ (s2.charAt(0) == '-');
        if(s1.charAt(0) == '-') s1 = s1.substring(1);
        if(s2.charAt(0) == '-') s2 = s2.substring(1);

        int n = s1.length();
        int m = s2.length();
        int[] ans = new int[n + m];

        for(int i = n-1; i >= 0; i--){
            for(int j = m-1; j >= 0; j--){
                int p = (s1.charAt(i) - '0') * (s2.charAt(j) - '0') + ans[i+j+1];
                ans[i+j+1] = p % 10;
                ans[i+j] += p / 10;
            }
        }

        StringBuilder sb = new StringBuilder();
        int idx = 0;
        while(idx < ans.length && ans[idx] == 0) idx++; // skip leading zeros
        for(; idx < ans.length; idx++) sb.append(ans[idx]);

        if(sb.length() == 0) return "0";
        if(neg) sb.insert(0, '-');

        return sb.toString();
    }
}
