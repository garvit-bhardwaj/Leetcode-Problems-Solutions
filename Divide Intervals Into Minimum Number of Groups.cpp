class Solution {
public:
    int minGroups(vector<vector<int>>& a) {
        int ans=0, i, n=1000011;
        vector<int> A(n, 0); // Taken the Array of Big Size
        for(auto x: a) {
            A[x[0]]++; 
            A[x[1]+1]--;
        }
        for(i=1;i<n-1;i++) A[i] += A[i-1]; // Prefix Sum
        for(auto x: A) ans=max(ans, x); // Take maximum of Prefix Sums
        return ans; // Return Maximum Value
    }
};
