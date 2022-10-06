class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& triangle,int n,vector<vector<int>>&dp){
        if(i==n-1)
            return triangle[i][j];
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int diag=triangle[i][j]+helper(i+1,j+1,triangle,n,dp);
        int down=triangle[i][j]+helper(i+1,j,triangle,n,dp);
        return dp[i][j]= min(diag,down);
        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        // vector<vector<int>>dp(size,vector<int>(size,-1));
        vector<int>cur(n),prev(n);
        // vector<vector<int>>dp(n,vector<int>(n,0));
        for(int j=0;j<n;j++)prev[j]=triangle[n-1][j];
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int diag=triangle[i][j]+prev[j+1];
                int down=triangle[i][j]+prev[j];
                cur[j]=min(diag,down);
                
            }
            prev=cur;
        }
        return prev[0];
        

        // return helper(0,0,triangle,size,dp);
        
    }
};
