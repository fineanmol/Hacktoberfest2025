class Solution(object):
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        left =0
        right=len(height)-1
        marea=0

        while left<right:
            minht=min(height[left],height[right])
            wid=right-left
            area=minht*wid
            marea=max(marea,area)

            if height[left]<height[right]:
                left+=1
            else:
                right-=1
        return marea
        
