import heapq
from typing import List

class SlidingWindowMedian:
    def __init__(self):
        self.max_heap = []  # max heap for the lower half (store as negatives)
        self.min_heap = []  # min heap for the upper half

    def add_num(self, num: int):
        # Push into appropriate heap
        if not self.max_heap or num <= -self.max_heap[0]:
            heapq.heappush(self.max_heap, -num)
        else:
            heapq.heappush(self.min_heap, num)
        # Balance heaps
        self._balance_heaps()

    def remove_num(self, num: int):
        # Lazy removal using heaps
        try:
            if num <= -self.max_heap[0]:
                self.max_heap.remove(-num)
                heapq.heapify(self.max_heap)
            else:
                self.min_heap.remove(num)
                heapq.heapify(self.min_heap)
        except ValueError:
            pass
        self._balance_heaps()

    def _balance_heaps(self):
        # Keep size difference ≤ 1
        if len(self.max_heap) > len(self.min_heap) + 1:
            heapq.heappush(self.min_heap, -heapq.heappop(self.max_heap))
        elif len(self.min_heap) > len(self.max_heap):
            heapq.heappush(self.max_heap, -heapq.heappop(self.min_heap))

    def get_median(self) -> float:
        if len(self.max_heap) == len(self.min_heap):
            return (-self.max_heap[0] + self.min_heap[0]) / 2.0
        return float(-self.max_heap[0])

def medianSlidingWindow(nums: List[int], k: int) -> List[float]:
    window = SlidingWindowMedian()
    result = []

    for i, num in enumerate(nums):
        window.add_num(num)
        if i >= k:
            window.remove_num(nums[i - k])
        if i >= k - 1:
            result.append(window.get_median())
    return result


# 🧪 Example Run
if __name__ == "__main__":
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3
    print("Input:", nums, "k =", k)
    print("Sliding Window Medians:", medianSlidingWindow(nums, k))