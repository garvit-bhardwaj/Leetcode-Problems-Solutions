class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        a = set()
        for i in s:
            if i in a:
                return len(a)
            a.add(i)
        return len(a)


if __name__ == '__main__':
    print(Solution().lengthOfLongestSubstring("pwwkew"))
