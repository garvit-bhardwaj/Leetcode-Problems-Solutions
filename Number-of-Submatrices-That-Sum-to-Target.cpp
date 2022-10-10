class Solution {
public:
        int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(),m=matrix[0].size(),count=0;
        vector<vector<int>>v(n+1,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[i+1][j]=v[i][j]+matrix[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<=n;j++){
                for(int k=0;k<m;k++){
                    int sum=0;
                    for(int l=k;l<m;l++){
                        sum+=v[j][l]-v[i][l];
                        if(sum==target){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
};