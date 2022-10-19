class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mp1;
        map<char,int> mp2;
        for(auto c:s){
            mp1[c]++;
        }
        for(auto x:t){
            mp2[x]++;
        }
        if(mp1==mp2)
            return true;
        return false;
    }
};