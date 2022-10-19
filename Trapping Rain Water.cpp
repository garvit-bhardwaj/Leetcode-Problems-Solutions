
/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it can trap after raining.*/




class Solution {
public:
    int trap(vector<int>& height) {
        
        // we keep record for very height's left biggest and it's right biggest height
        int n=height.size();
        vector<int> left(height);
        vector<int> right(height);
        
        int max=0;
        for(int i=0;i<n;i++){
            if(height[i]>max){
                max=height[i];
            }
            left[i]=max;
        }
        
        max=0;
        for(int i=n-1;i>=0;i--){
            if(height[i]>max){
                max=height[i];
            }
            right[i]=max;
        }
        
        for(int i=0;i<n;i++){
            cout<<left[i]<<" ";
        }
        cout<<"\n";
        
        for(int i=0;i<n;i++){
            cout<<right[i]<<" ";
        }
        
        // water on specific height's is min(MaxLeft,MaxRight)-height
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(left[i],right[i])-height[i];    
        }
        return water;
    }
};
