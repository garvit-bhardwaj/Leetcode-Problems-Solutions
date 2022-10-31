const vector<string> mp = {
    "", "", "abc", "def", "ghi", "jkl",
    "mno", "pqrs", "tuv", "wxyz"};

class Solution {
    vector<string> res;
    void getCombinationsRecursively(int index,string &digits,string &temp){
        if(index==digits.size()) {res.push_back(temp);return;}
        
        for(auto c:mp[digits[index] -'0']){
            temp.push_back(c);
            getCombinationsRecursively(index+1,digits,temp);
            temp.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return res;
        string temp = "";
        getCombinationsRecursively(0,digits,temp);
        return res;
    }
};
