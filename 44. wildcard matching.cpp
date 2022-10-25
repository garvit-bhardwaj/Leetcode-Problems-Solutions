class Solution {
public:
    bool isMatch(string s, string p) {
        int i=0,j=0,match=0,starIdx=-1;
        while(s[i]){
            if(p[j] && (p[j]=='?' || s[i]==p[j]))
                i++,j++;
            else if(p[j] && p[j]=='*')
                match=i,starIdx=j++;
            else if(starIdx!=-1)
                i=++match,j=starIdx+1;
            else
                return false;
        }
        while(p[j] && p[j]=='*')
            j++;
        return !p[j];
    }
};
