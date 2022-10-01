class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int xr = 0;
        if(nums1.size() & 1){
            for(auto&i: nums2)
                xr ^= i;
        }
        
        if(nums2.size() & 1){
            for(auto&i: nums1)
                xr ^= i;
        }
        
        return xr;
    }
};
