class Solution:
    def merge(self, intervals):
        # Step 1: Sort intervals based on start time
        intervals.sort(key=lambda x: x[0])
        merged = []

        for interval in intervals:
            # If merged is empty or no overlap
            if not merged or merged[-1][1] < interval[0]:
                merged.append(interval)
            else:
                # Overlap → merge intervals
                merged[-1][1] = max(merged[-1][1], interval[1])

        return merged

# Example usage:
solution = Solution()
print(solution.merge([[1,3],[2,6],[8,10],[15,18]]))  # Output: [[1,6],[8,10],[15,18]]
print(solution.merge([[1,4],[4,5]]))  # Output: [[1,5]]