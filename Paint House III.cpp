class Solution {
public:
    
    vector<vector<vector<int>>> memo;
    vector<int> houses;
    vector<vector<int>> cost;
    int target, n, m;
    #define inf 2000000000
    
    int dp(int idx, int prev, int cnt){
        if(idx >= m){
            return cnt == target ? 0 : inf;
        }
        
        int& ret = memo[idx][prev][cnt];
        if(~ret)
            return ret;
        
        ret = inf;
        
        if(houses[idx]){
            ret = dp(idx + 1, houses[idx], cnt + (houses[idx] != prev));
        }else{
            for(int i = 0; i < n; i++){
                ret = min(ret, cost[idx][i] + dp(idx + 1, i + 1, cnt + (i + 1 != prev)));
            }
        }
        return ret;
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memo = vector<vector<vector<int>>>(m, vector<vector<int>>(n + 1, vector<int>(m + 1, -1)));
        this -> cost = cost;
        this ->  houses = houses;
        this -> target = target;
        this -> n = n;
        this -> m = m;
        
        int ans = dp(0, 0, 0);
        
        return ans == inf ? -1 : ans;
    }
};