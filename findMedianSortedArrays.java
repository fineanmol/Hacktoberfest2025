class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int i = 0, j = 0, k = 0;

        int[] merged = new int[m + n];
        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                merged[k++] = nums1[i++];
            else
                merged[k++] = nums2[j++];
        }
        while (i < m) {
            merged[k++] = nums1[i++];

        }
        while (j < n) {
            merged[k++] = nums2[j++];

        }
        int s = 0, e = m + n - 1;
        while (s < e) {
            s++;
            e--;
        }
        if (s == e)
            return (double) merged[s];
        return (double) (merged[s] + merged[e]) / 2;
    }
}
