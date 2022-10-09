class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int u=nums.size()-1;
        int l=0;
        int mid=(l+u)/2;
        
        while(l<=u && nums[mid]!=target)
        {
            if(target<nums[mid])
                u=mid-1;
            else
                l=mid+1;
            
            mid=(l+u)/2;
        }
        
        if(l>u)
            return l;
        else
            return mid;
    }
};
