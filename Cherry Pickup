class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // dp holds maximum # of cherries two k-length paths can pickup.
        // The two k-length paths arrive at (i, k - i) and (j, k - j), 
        // respectively.
        vector<vector<int>> dp(n, vector<int>(n, -1));

        dp[0][0] = grid[0][0]; // length k = 0
        
        // maxK: number of steps from (0, 0) to (n-1, n-1).
        const int maxK = 2 * (n - 1); 
        
        for (int k = 1; k <= maxK; k++) { // for every length k
            vector<vector<int>> curr(n, vector<int>(n, -1));
        
            // one path of length k arrive at (i, k - i) 
            for (int i = 0; i < n && i <= k; i++) {
                if ( k - i >= n) continue;
                // another path of length k arrive at (j, k - j)
                for (int j = 0; j < n && j <= k; j++) {
                    if (k - j >= n) continue;
                    if (grid[i][k - i] < 0 || grid[j][k - j] < 0) { // keep away from thorns
                        continue;
                    }
                    
                    int cherries = dp[i][j]; // # of cherries picked up by the two (k-1)-length paths.
                    
                    // See the figure below for an intuitive understanding
                    if (i > 0) cherries = std::max(cherries, dp[i - 1][j]);
                    if (j > 0) cherries = std::max(cherries, dp[i][j - 1]);
                    if (i > 0 && j > 0) cherries = std::max(cherries, dp[i - 1][j - 1]);
                    
                    // No viable way to arrive at (i, k - i)-(j, k-j).
                    if (cherries < 0) continue;
                    
                    // Pickup cherries at (i, k - i) and (j, k -j ) if i != j.
                    // Otherwise, pickup (i, k-i). 
                    cherries += grid[i][k - i] + (i == j ? 0 : grid[j][k - j]);
                
                    curr[i][j] = cherries;
                }
            }
            dp = std::move(curr); 
        }
        
        return std::max(dp[n-1][n-1], 0); 
    }
};
