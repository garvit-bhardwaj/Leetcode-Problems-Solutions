class Solution {
public:
    int leastOpsExpressTarget(int x, int target) {
        int r = target%x, c = x - r;
        // Get number of x's used to express residual
        int nr = min(2*r, 1 + 2*(x - r));
        int nc = min(2*c, 1 + 2*(x-c));
        return min(nr + dfs(target - r, x), nc + dfs(target + c, x)) - 1;
    }
private:
    // Memorization
    unordered_map<long, int> dp;
    int dfs(long target, int x) {
        if (target == 0)
            return 0;
        if (dp.find(target) != dp.end())
            return dp[target];
        
        long num = target;
        int c = 0;
        long lowestPower = 1;
        
        // Get least significant x-git of target
        while (num && (num%x == 0)) {
            num /= x;
            ++c;
            lowestPower *= x;
        }

        int lowestPowerCoeff = (target/lowestPower)%x;
        int distToHigherPower = lowestPower*(x - lowestPowerCoeff);
        
        // If target only has one x-git, exit
        if (lowestPowerCoeff*lowestPower == target) {
            dp[target] = min(lowestPowerCoeff*c, (x - lowestPowerCoeff)*c + c + 1);
            return dp[target];
        }
        
        int dp1 = lowestPowerCoeff*c + dfs(target - lowestPowerCoeff*lowestPower, x);
        int dp2 = (x - lowestPowerCoeff)*c + dfs(target + distToHigherPower, x);
        
        dp[target] = min(dp1, dp2); 
        return dp[target];
    }
};
