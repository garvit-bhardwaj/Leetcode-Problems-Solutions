class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        for i in range(n):
            for j in range(n):
                if i != j and target == nums[i] + nums[j]:
                    return [i, j]

    def twoSum1(self, nums: list[int], target: int) -> list[int]:
        n = len(nums)
        for i in range(n):
            if target - nums[i] in nums:
                ind = nums.index(target - nums[i])
                if ind != i:
                    return [i, ind]

    def twoSum2(self, nums: list[int], target: int) -> list[int]:
        lookup = {}
        for index, num in enumerate(nums):
            if target - num in lookup:
                return[lookup[target - num], index]
            lookup[num] = index
        return []


sol = Solution()
print(sol.twoSum1(list(range(1, 10001)), 19999))
