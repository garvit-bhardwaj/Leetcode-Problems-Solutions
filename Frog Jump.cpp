class Solution {
   public:
    int dp[3000][3000];
    map<int, int> mp;
    bool fun(int i, int k, vector<int>& s) {
        // cout<<i<<" "<<k<<" "<<s[i]<<"\n";
        if (i == s.size() - 1)
            return true;
        else if (i > s.size())
            return false;
        if (dp[i][k] != -1) return dp[i][k];
        if (!k) {
            if (!mp[s[i] + 1]) return false;
            return dp[i][k] = fun(mp[s[i] + 1], k + 1, s);
        } else {
            bool a1 = false, a2 = false, a3 = false;
            if (k > 1) {
                if (mp[s[i] + k - 1]) a1 = fun(mp[s[i] + k - 1], k - 1, s);
            }
            if (mp[s[i] + k]) a2 = fun(mp[s[i] + k], k, s);
            if (mp[s[i] + k + 1]) a3 = fun(mp[s[i] + k + 1], k + 1, s);
            // cout<<i<<" "<<a1<<" "<<a2<<" "<<a3<<"\n";
            return dp[i][k] = a1 | a2 | a3;
        }
    }

    bool canCross(vector<int>& st) {
        set<int> s(st.begin(), st.end());
        for (int i = 0; i < st.size(); i++) mp[st[i]] = i;
        memset(dp, -1, sizeof(dp));
        return fun(0, 0, st);
    }
};