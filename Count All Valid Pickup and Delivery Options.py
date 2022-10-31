class Solution:
    def countOrders(self, n: int) -> int:
        ans = a = x = 1
        for i in range(n):
            ans*=a
            a+=x+1+x+2
            x+=2
        return ans%1000000007