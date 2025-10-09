/*
Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
*/

class Solution {
    public int trap(int[] arr) {
        int n  = arr.length;

        int[] left = new int[n];
        left[0] = arr[0];
        for (int i =1;i<n;i++){
            left[i] = Math.max(left[i-1],arr[i]);
        }

        int[] right = new int[n];
        right[n-1] = arr[n-1];
        for (int i =n-2;i>=0;i--){
            right[i] = Math.max(right[i+1],arr[i]);
        }

        int sum =0;

        for (int i =0;i<arr.length;i++){
            sum = sum + Math.min(left[i],right[i]) - arr[i];
        }

        return sum;
        
    }

     
}
