/*
 * Function to find the maximum sliding window in a given array.
  * Uses a deque to maintain the indices of potential maximums.
 */
#include <deque>
#include <vector>
using namespace std;
vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> d;
        vector<int> ret;
        for (int i = 0; i < k; i++) {//initilize the dequeue
                while (!d.empty() && nums[i] > nums[d.back()]) { d.pop_back(); }
                d.push_back(i);
        }
        for (int i = k; i < nums.size(); i++) {
                ret.push_back(nums[d.front()]);//record answer for each sliding window
                if (!d.empty() && d.front() <= i - k) { d.pop_front(); }//pop if out of bounds
                while (!d.empty() && nums[i] >= nums[d.back()]) { d.pop_back(); }
                d.push_back(i);
        }
        ret.push_back(nums[d.front()]);
        return ret;
}