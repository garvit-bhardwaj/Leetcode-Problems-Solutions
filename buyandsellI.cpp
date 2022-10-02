class Solution {
    public int maxProfit(int[] p) {
        int n=p.length;
        int[][][] dp=new int[n+1][2][3];
        for(int[][] a:dp){
            for(int[] x:a){
                Arrays.fill(x,-1);
            }
        }
        return helper(p,0,p.length,1,2,dp);
    }
    public int helper(int[] p,int i,int n,int bool,int k,int[][][] dp){
        if(k==0 || i==n) return 0;
        if(dp[i][bool][k]!=-1) return dp[i][bool][k];
        if(bool==1){
           int x=-p[i]+helper(p,i+1,n,0,k,dp);
           int y=helper(p,i+1,n,1,k,dp);
           return dp[i][bool][k]= Math.max(x,y);
        }
        else{
            int x=p[i]+helper(p,i+1,n,1,k-1,dp);
            int y=helper(p,i+1,n,0,k,dp);
           return dp[i][bool][k] = Math.max(x,y);
        }
    }
}