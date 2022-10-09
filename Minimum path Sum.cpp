class Solution {
public:
    int f(int i, int j, vector<vector<int>> & grid, vector<vector<int>> & dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1000;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int up = grid[i][j] + f(i-1, j, grid, dp);
        int left = grid[i][j] + f(i, j-1, grid, dp);
        
        return dp[i][j] = min(up, left);
    }
    
    
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        //Memoization
        //vector<vector<int>> dp(m, vector<int>(n, -1));
        
        //Tabulation

        // int dp[m][n];
        
        vector<vector<int>> dp(m, vector<int>(n, 0));

        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j] = grid[i][j];
                else {
                    int up= grid[i][j];
                    if(i>0) up += dp[i-1][j];
                    else up = 1000;
                    int left = grid[i][j];
                    if(j>0) left += dp[i][j-1];
                    else left = 1000;
                
                    dp[i][j] = min(up, left);
                }
            }
        }
        
        
        return dp[m-1][n-1];
    }
};
