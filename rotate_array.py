def rotate_array(nums, k):
    n = len(nums)
    k %= n  # handle k > n
    nums[:] = nums[-k:] + nums[:-k]
    return nums

arr = [1, 2, 3, 4, 5, 6, 7]
k = 3
print(rotate_array(arr, k))  
