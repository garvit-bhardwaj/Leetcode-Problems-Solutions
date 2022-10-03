/*

PROBLEM STATEMENT

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lowercase English letters.

*/

vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Base case
		if(strs.size() == 1)
            return {{strs[0]}};
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> M;
        for(int  i = 0; i < strs.size(); i++)
        {
            string str = strs[i];
            sort(strs[i].begin(), strs[i].end()); // Sorting the string
            M[strs[i]].push_back(str);  // Sorted string is the key and the value is the initial string
        }
        for(auto i = M.begin(); i != M.end(); i++)
            ans.push_back(i -> second);  // Traversing the map and adding the vectors of string to ans
        return ans;
    }
    
    
    
    
    
    
