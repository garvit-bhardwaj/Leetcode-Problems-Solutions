class Solution {
public:
    bool isPowerOfFour(int n) {
        int ans = 1;
        
        if(n == 0){
            return false;
        }
        
        for(int i = 0; i <= 30; i++){
            if(ans == n){
                return true;
            }
            
            if(ans > INT_MAX/4){
                return false;
            }
            
            ans *= 4;
        }
        
        return false;
    }
};
