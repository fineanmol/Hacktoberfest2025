import java.util.HashMap;

class LC76_MinimumWindowSubstring {
    public String minWindow(String s, String t) {
        if (s.length() == 0 || t.length() == 0) return "";

        HashMap<Character, Integer> dictT = new HashMap<>();
        for (char c : t.toCharArray()) dictT.put(c, dictT.getOrDefault(c, 0) + 1);

        int required = dictT.size();
        int left = 0, right = 0, formed = 0;
        HashMap<Character, Integer> windowCounts = new HashMap<>();
        int[] ans = {-1, 0, 0}; // length, left, right

        while (right < s.length()) {
            char c = s.charAt(right);
            windowCounts.put(c, windowCounts.getOrDefault(c, 0) + 1);

            if (dictT.containsKey(c) && windowCounts.get(c).intValue() == dictT.get(c).intValue()) {
                formed++;
            }

            while (left <= right && formed == required) {
                c = s.charAt(left);

                if (ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                windowCounts.put(c, windowCounts.get(c) - 1);
                if (dictT.containsKey(c) && windowCounts.get(c) < dictT.get(c)) {
                    formed--;
                }

                left++;
            }

            right++;
        }

        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }
}
