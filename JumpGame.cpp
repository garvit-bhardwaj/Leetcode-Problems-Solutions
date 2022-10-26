//You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

//Return true if you can reach the last index, or false otherwise.





class Solution {
public:
    bool canJump(vector<int>& nums) {
        int x=0;
        
        if(nums.size()==1) return true;
        for(int i=0;i<nums.size();i++)
        {
            if(x<i)
          {
              return false;
          }
            int v= i +nums[i];
             x= max(v,x);

        
        }
        return true;
            
           
        
        
    }
};