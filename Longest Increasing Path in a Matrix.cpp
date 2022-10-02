class Solution {
public:
    
    int n, m;
    
    vector<int> dx = {0, 0, 1, -1}, dy = {1, -1, 0, 0};
    
    bool is_valid(int x, int y){
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    
    vector<vector<int>> memo;
    
    int backtrack(int x, int y, vector<vector<int>>& matrix){
        int& ret = memo[x][y];
        
        if(~ret)
            return ret;
        
        ret = 1;
        for(int i = 0; i < 4; i++){
            int new_x = x + dx[i], new_y = y + dy[i];
            
            if(is_valid(new_x, new_y) and matrix[new_x][new_y] > matrix[x][y]){
                ret = max(ret, 1 + backtrack(new_x, new_y, matrix));
            }
        }
        
        return ret;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        n = int(matrix.size()), m = int(matrix.front().size());
        
        memo.assign(n + 1, vector<int>(m + 1, -1));
        
        int ans = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans, backtrack(i, j, matrix));
            }
        }
        return ans;
    }
};