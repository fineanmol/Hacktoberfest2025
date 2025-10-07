class MedianFinder:

    def __init__(self):
        self.left = [] # max-heap (negative store)
        self.right = [] # min-heap
        

    def addNum(self, num: int) -> None:
        #First add to min heap [Assuming right can have >= left]
        heapq.heappush(self.right,num)
        #Put the min of right to left so that we can be sure max left <= min of right
        heapq.heappush(self.left,-heapq.heappop(self.right))
        #Balancing act
        if len(self.left) > len(self.right):
            heapq.heappush(self.right,-heapq.heappop(self.left))        

    def findMedian(self) -> float:
        if len(self.right) > len(self.left):
            return self.right[0]
        return (-self.left[0] + self.right[0]) / 2 
        


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()
