class Solution {
public:
    
    // kmp
    vector<int> prefix_function(string s) {
        int n = (int)s.length();
        vector<int> pi(n);
        for (int i = 1; i < n; i++) {
            int j = pi[i-1];
            while (j > 0 && s[i] != s[j])
                j = pi[j-1];
            if (s[i] == s[j])
                j++;
            pi[i] = j;
        }
        return pi;
    }
    
    
    // dp
    int dp[4100];
    
    
    int helper(string s){
        int m = s.size();
        
        
        // dp memo
        if(dp[m]!=-1){
            return dp[m];
        }
        vector<int> prefix = prefix_function(s);
        bool check = false;
        int ans = 0;
        for(int j = 1 ; j < m ; j++){
            
            // checking if prefix[i] == half of length of string s at that particular time
            int val = (j+1)/2;
            if(j%2==1 and prefix[j] == val){
                check = true;
                ans = max(ans,1+helper(s.substr(prefix[j])));
            }
        }
            
        
        // if no prefix found in string s
        if(check==false){
            return 1;
        }
        return dp[m] = ans;
    }
    
    
    int deleteString(string s) {
        memset(dp,-1,sizeof(dp));
        return helper(s);
    }
};
