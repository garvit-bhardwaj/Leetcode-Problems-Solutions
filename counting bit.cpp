class Solution {
public:
    int numSquares(int n) {
        vector<int> v;
        for(int i=1;i<=sqrt(n);i++){
            if(i*i<=n){
                v.push_back(i*i);
            }
        }
        int k=v.size()+1;
        vector<vector<int>> dp(v.size()+1,vector<int>(n+1,0));
        for(int i=0;i<k;i++){
            for(int j=0;j<n+1;j++){
                if(i==0){
                    dp[i][j]=INT_MAX-1;
                }
                else if(j==0&&i!=0){
                    dp[i][j]=0;
                }
            }
        }
        for(int i=1;i<n+1;i++){
           dp[1][i]=i;
        }
        for(int i=2;i<k;i++){
            for(int j=1;j<n+1;j++){
                 if(v[i-1]<=j){
                    dp[i][j]=min(1+dp[i][j-v[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[k-1][n];
    }
};