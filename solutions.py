# 2333. Minimum Sum of Squared Difference
from sortedcontainers import SortedDict
class Solution:
    def minSumSquareDiff(self, nums1: List[int], nums2: List[int], k1: int, k2: int) -> int:
        
        n = len(nums1)
        abs_diff = [abs(x - y) for x, y in zip(nums1, nums2) if x != y]
        abs_diff_cnt = SortedDict(collections.Counter(abs_diff))
        
        k = k1 + k2
        while abs_diff_cnt and abs_diff_cnt.peekitem()[-1] > 0 and k > 0:
            abs_diff, cnt = abs_diff_cnt.popitem()
            tmp = min(cnt, k)
            if cnt - tmp > 0:
                abs_diff_cnt[abs_diff] = cnt - tmp
                
            if abs_diff - 1 > 0:
                abs_diff_cnt[abs_diff - 1] = abs_diff_cnt.get(abs_diff - 1, 0) + tmp
        
            k -= tmp
        return sum(cnt * diff ** 2 for diff, cnt in abs_diff_cnt.items() if diff > 0)
