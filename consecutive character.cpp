class Solution {
public:
    int maxPower(string s) {
        int res = 0, i = 0, j, len = s.size(), curr = s[0];
        while (i < len) {
            j = i + 1;
            while (j < len && curr == s[j]) j++;
            res = max(res, j - i);
            curr = s[j];
            i = j;
        }
        return res;
    }
};
