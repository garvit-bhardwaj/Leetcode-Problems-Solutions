class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int sol=0;
        int temp=0;
        while(i<j)
        {
            temp=(min(height[i],height[j])*(j-i));
            sol=max(temp,sol);
            if(height[i]>height[j])
            {
                j--;
            }
            else i++;
        }
        return sol;
    }
};
