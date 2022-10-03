class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string temp;
        int l = 0 , r = 0,i = 0;
        int maxs=0;
        while( r < s.size() && l < s.size())
        {
            if(find(temp.begin(), temp.end(),s[r]) == temp.end())
                {
                    temp.push_back(s[r]);
                    r++;
                }
            else 
                {
                    l++;
                    r = l;
                    temp.clear();
                }
                 maxs = max(maxs,r - l);
        }
        return maxs;
    }
};