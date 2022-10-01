class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        
        
        
        
        int dp[n][7][16];
        int mo=1e9+7;
        memset(dp,0,sizeof dp);
        int i,j,k;
        for(i=1;i<=6;i++)
        {
            dp[0][i][1]=1;
        }
        long long ans=0;
        for(i=1;i<n;i++)
        {
            
            
            for(j=1;j<=6;j++)
            {
                for(k=1;k<=6;k++)
                {
                    
                    for(int z=1;z<=rollMax[j-1];z++)
                    {
                     int rolls=0;
                        if(j==k)
                        {
                            rolls=z+1;
                        }
                        else
                            rolls=1;
                        if(rolls<=rollMax[k-1])
                        {
                            dp[i][k][rolls]=(dp[i][k][rolls]+dp[i-1][j][z])%mo;
                            
                        }
                    }
                }
            }
        }
        for(i=1;i<=6;i++)
        {
            for(j=1;j<=rollMax[i-1];j++)
            {
                ans=(ans+dp[n-1][i][j])%mo;
            }
        }
        return ans;
        
    }
};
