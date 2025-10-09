from typing import List 
class Solution:
    def minTime(self, skill: List[int], mana: List[int]) -> int:
        n, m = len(skill), len(mana)
        times = [0] * n
        for j in range(m):
            cur_time = 0
            for i in range(n):
                cur_time = max(cur_time, times[i]) + skill[i] * mana[j]
            times[n - 1] = cur_time
            for i in range(n - 2, -1, -1):
                times[i] = times[i + 1] - skill[i + 1] * mana[j]
        return times[n - 1]

'''
Approach: Dynamic Programming
Intuition
The requirement is that each potion must be brewed by every wizard, and each wizard can brew only one potion at a time. Once the brewing of a potion begins, it cannot be paused midway and must be completed continuously by all wizards.

First, the brewing of the first potion begins at time 0, so the time each wizard takes to brew it is fixed and easy to calculate. However, the starting time for subsequent potions is not immediately clear.

We may allow the brewing process of the j-th potion to be non-continuous (while the first j−1 potions still require continuity) and let the time for the i-th wizard to finish brewing the j-th potion be times[i][j]. Then we have:

times[i][j]=max(times[i−1][j],times[i][j−1])+skill[i]×mana[j]

After one round of recursion, we obtain the completion time of the j-th potion, times[n−1][j]. At this point, we traverse backwards to update the completion times of the j-th potion for the previous wizards, eliminating the gaps introduced by the earlier allowance of discontinuous brewing.

During implementation, times can be optimized to a one-dimensional array.
'''    