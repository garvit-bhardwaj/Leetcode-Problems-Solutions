class Solution {
public:
    vector<int> bit;
    void update(int x, int val, int m)
    {
        for(; x<=m; x+=(x&-x))
            bit[x]+=val;
    }
    
    int getsum(int x)
    {
        int sum=0;
        for(;x>0; x-=(x&-x))
            sum += bit[x];
        return sum;
    }
    vector<int> countSmaller(vector<int>& nums) {
        
        bit.resize(200009);
        int n = nums.size(), i;
        
        map<int,int> mp;
        for(i=0;i<n;i++)
        {
           mp[nums[i]]++;
        }
        int cnt=1;
        for(auto itr=mp.begin(); itr!=mp.end(); itr++)
        {
            itr->second = cnt++;
        }
        for(i=0;i<n;i++)
        {
            nums[i] = mp[nums[i]];
        }
        
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--)
        {
            ans[i] = getsum(nums[i]-1);
            update(nums[i], 1, 200007);
        }
        
        return ans;
        
        
        
        
    }
};