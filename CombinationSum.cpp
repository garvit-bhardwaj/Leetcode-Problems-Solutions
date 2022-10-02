class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> sum;
        combinationSumHelper(candidates, target, 0, sum, ans);
        return ans;
    }
    
     void combinationSumHelper(vector<int>& candidates, int target, int idx, vector<int>& sum, vector<vector<int>>& ans)
     {
         if(target==0 && idx<candidates.size())
         {
             ans.push_back(sum);
             return;
         }
         
         if(target<0 || idx>=candidates.size())
         {
             return;
         }
         
         sum.push_back(candidates[idx]);
         combinationSumHelper(candidates,target-candidates[idx],idx,sum,ans);
         sum.pop_back();
         combinationSumHelper(candidates,target,idx+1,sum,ans);   
     }
};
