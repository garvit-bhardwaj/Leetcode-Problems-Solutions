class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> v1;
        
        for(int i=0;i<nums.size();i++)
        {
            v1.push_back({nums[i],i});
        }
        sort(v1.begin(),v1.end());
        int n=nums.size();
        int i=0,j=n-1;
        vector<int> ans;
        while(i<j)
        {
            int sum=v1[i].first+v1[j].first;
            if(sum==target)
            {
                return {v1[i].second,v1[j].second};
            }
            else if(sum>target)
            {
                j--;
            }
            else
            {
                i++;
            }
        }
        
        return {};
            
    }
};
