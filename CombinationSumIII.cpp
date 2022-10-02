class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> num{1,2,3,4,5,6,7,8,9};
        vector<vector<int>> res;
        vector<int> ans;
        helper(k,n,0,ans,num,res);
        return res;
    }
    
    void helper(int k,int n, int idx, vector<int> &ans,vector<int> &num, vector<vector<int>> &res)
    {
        if(n==0 && ans.size()==k)
        {
            res.push_back(ans);
            return;
        }
        
        for(int i=idx;i<num.size();i++)
        {
            ans.push_back(num[i]);
            helper(k,n-num[i],i+1,ans,num,res);
            ans.pop_back();
        }
    }
};
