class Solution {
public:
    
    int helper(vector<int>& nums, int i ,int n, vector<int>&dp){
        if(i==n) return nums[i];
        if(i>n) return 0;
        if(dp[i]!=-1)return dp[i];
           return dp[i] = max( helper(nums,i+1,n,dp) , nums[i] + helper(nums,i+2,n,dp));
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
        int ans = helper(nums,0,n-1,dp);
        return ans;
    }
};