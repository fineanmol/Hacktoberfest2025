/*
Difficulty: Hard
Topic: Arrays, Two Pointers
Description:
Given n non-negative integers representing an elevation map where the width of each bar is 1, find how much rainwater it can trap after raining.
*\
function trap(height) {
  let left = 0, right = height.length - 1;
  let leftMax = 0, rightMax = 0, totalWater = 0;

  while (left < right) {
    if (height[left] < height[right]) {
      if (height[left] >= leftMax) {
        leftMax = height[left];
      } else {
        totalWater += leftMax - height[left];
      }
      left++;
    } else {
      if (height[right] >= rightMax) {
        rightMax = height[right];
      } else {
        totalWater += rightMax - height[right];
      }
      right--;
    }
  }

  return totalWater;
}

console.log(trap([4,2,0,3,2,5])); // 9
