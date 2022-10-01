class Solution {
public:
    int maxArea(vector<int> &height) {

        int maxArea = 0;
        // two pointers scan from two sides to middle
        int left = 0; 
        int right = height.size()-1;

        int area; 
        while ( left < right ){
            // calculate the area
            area = (right - left) * ( height[left] < height[right] ? height[left] : height[right]);
            // tracking the maxium area
            maxArea = area > maxArea ? area : maxArea;
            // because the area is decided by the shorter edge
            // so we increase the area is to increase the shorter edge
            //
            //     height[left] < height[right] ? left++ : right-- ;
            //
            // However, the above code could cause the unnecessary `area` cacluation
            // We can do some improvement as below:
            if (height[left] < height[right]) {
                do {
                    left++;
                } while (left < right && height[left-1] >= height[left]);
            } else {
                do {
                    right--;
                } while (right > left && height[right+1] >= height[right]);
            }
        }
        
        return maxArea;
    }
};