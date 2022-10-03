/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void create( TreeNode* root,   map<int, vector<int>>&mp){
        if(root->left)
        {
             mp[root->left->val].push_back(root->val);
             mp[root->val].push_back(root->left->val);
             create(root->left, mp);
            
        }
        if(root->right)
        {
             mp[root->right->val].push_back(root->val);
             mp[root->val].push_back(root->right->val);
             create(root->right, mp);
            
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        map<int, vector<int>>mp;
        create(root, mp);
        queue<int>q;
        q.push(start);
        set<int>st;
        int time=0;
        st.insert(start);
        while(q.size()){
            int size= q.size();
            time++;
            while(size--){
                int node=q.front();q.pop();
                for(auto ch: mp[node]){
                    if(!st.count(ch)){
                        q.push(ch);
                        st.insert(ch);
                    }
                }
            }
        }
        return time-1;
        
    }
};