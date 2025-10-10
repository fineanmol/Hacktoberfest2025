import java.util.Arrays;

class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        Arrays.sort(potions);
        int n = spells.length;
        int m = potions.length;
        int[] ans = new int[n];

        for (int i = 0; i < n; i++) {
            int spell = spells[i];
            int left = 0, right = m - 1, idx = m;

            while (left <= right) {
                int mid = left + (right - left) / 2;
                if ((long) spell * potions[mid] >= success) {
                    idx = mid;         // potential first valid potion
                    right = mid - 1;   // try to find earlier one
                } else {
                    left = mid + 1;
                }
            }
            ans[i] = m - idx; // number of successful pairs
        }

        return ans;
    }
}
