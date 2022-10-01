class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0 ,n = nums.size();
        for(int i = 0,j = n-1;i < j;)
        {
            int sum = nums[i] + nums[j];
            if(sum < k) i++;
            
            else if(sum > k ) j--;
            else 
            {
                count++;
                i++,j--;
            }


             
        }
        return count;
    }
};
