class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> nums;
        vector<int> comb;
        
        for(int i=1;i<=n;i++)
        {
            nums.push_back(i);
        }
        
        combine(k,0,ans,nums,comb);
        
        return ans;
    }
    
    void combine(int k, int idx,vector<vector<int>> &ans, vector<int> &nums, vector<int> &comb)
    {
        if(comb.size()==k)
        {
            ans.push_back(comb);
            return;
        }
        
        for(int i=idx;i<nums.size();i++)
        {
            comb.push_back(nums[i]);
            combine(k,i+1,ans,nums,comb);
            comb.pop_back();
        }
        
        return;
    }
};
