class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
          long long window=(k*2)+1;
        int i=0,j=0;
        long long sum=0;
       while(j<n){
           sum+=nums[j];
           if(j-i+1==window){
               long long temp=floor(sum/window);
               ans[k]=temp;
               k++;
               sum-=nums[i];
               i++;
           }
           j++;
       }
        return ans;
    }
};
