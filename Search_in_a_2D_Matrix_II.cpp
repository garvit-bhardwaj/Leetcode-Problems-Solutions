class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        //start = row index
        //col = column index
        int start = 0;
        int end = col - 1;
        
        while(start < row && end >= 0){
            int element = matrix[start][end];
            if(element == target){
                return true;
            }
            else if(element < target){
                start++;
            }
            else{
                end--;
            }
        }
        
        return false;
    }
};
