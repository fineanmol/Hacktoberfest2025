// Meeting Rooms II - LeetCode #253

/**
 * @param {number[][]} intervals
 * @return {number}
 */
var minMeetingRooms = function(intervals) {
    if (intervals.length === 0) return 0;
    
    intervals.sort((a, b) => a[0] - b[0]);
    
    const heap = [intervals[0][1]];
    
    for (let i = 1; i < intervals.length; i++) {
        if (intervals[i][0] >= heap[0]) {
            heap[0] = intervals[i][1];
        } else {
            heap.push(intervals[i][1]);
        }
        heap.sort((a, b) => a - b); // Simulate min-heap
    }
    
    return heap.length;
};
