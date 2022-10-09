# 2348. Number of Zero-Filled Subarrays
    def zeroFilledSubarray(self, nums: List[int]) -> int:
        cnt = local = 0
        for num in nums:
            if num == 0:
                local += 1
                cnt += local
            else:
                local = 0
        return cnt
