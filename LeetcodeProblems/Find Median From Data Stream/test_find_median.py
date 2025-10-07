import heapq
import pytest

# --------------------- Code ---------------------
class MedianFinder:

    def __init__(self):
        self.left = []   # max-heap (as negatives)
        self.right = []  # min-heap

    def addNum(self, num: int) -> None:
        heapq.heappush(self.right, num)
        heapq.heappush(self.left, -heapq.heappop(self.right))
        if len(self.left) > len(self.right):
            heapq.heappush(self.right, -heapq.heappop(self.left))

    def findMedian(self) -> float:
        if len(self.right) > len(self.left):
            return self.right[0]
        return (-self.left[0] + self.right[0]) / 2
# -------------------------------------------------


# ------------------- Test Cases ------------------
@pytest.mark.parametrize("sequence, expected_medians", [
    # 1. Odd number of elements, incremental
    ([1, 2, 3], [1, 1.5, 2]),

    # 2. Even number of elements, mix order
    ([2, 1, 5, 7], [2, 1.5, 2, 3.5]),

    # 3. All same elements
    ([4, 4, 4, 4], [4, 4.0, 4, 4.0]),

    # 4. Increasing values
    ([10, 20, 30, 40, 50], [10, 15.0, 20, 25.0, 30]),

    # 5. Decreasing values
    ([9, 8, 7, 6, 5], [9, 8.5, 8, 7.5, 7]),

    # 6. Negative numbers
    ([-1, -2, -3, -4], [-1, -1.5, -2, -2.5]),

    # 7. Mixed signs
    ([5, -1, 3, 8, 0], [5, 2.0, 3, 4.0, 3]),

    # 8. Only one element
    ([42], [42]),

    # 9. Two elements
    ([1, 100], [1, 50.5]),

    # 10. Alternating high/low
    ([1000, 1, 999, 2], [1000, 500.5, 999, 500.5]),
])
def test_median_finder(sequence, expected_medians):
    mf = MedianFinder()
    actual = []
    for num in sequence:
        mf.addNum(num)
        actual.append(mf.findMedian())
    assert actual == expected_medians
# -------------------------------------------------
