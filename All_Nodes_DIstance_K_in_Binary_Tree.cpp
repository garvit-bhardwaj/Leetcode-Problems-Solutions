class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parent_track;
        
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            if(current->left) {
                parent_track[current->left] = current;
                q.push(current->left);
            }
            if(current->right) {
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
        q.push(target);
        visited[target]=true;
        int cur_level = 0;
        
        while(!q.empty()) {
            int size = q.size();
            if(cur_level == k) break;
            cur_level++;
            for(int i=0; i<size; i++) {
                TreeNode* current = q.front();
                q.pop();
                if(current->left && !visited[current->left]) {
                    q.push(current->left);
                    visited[current->left] = true;
                }
                if(current->right && !visited[current->right]) {
                    q.push(current->right);
                    visited[current->right] = true;
                }
                if(parent_track[current] && !visited[parent_track[current]]) {
                    q.push(parent_track[current]);
                    visited[parent_track[current]] = true;
                }
            }
        }
        
        vector<int> result;
        while(!q.empty()) {
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->val);
        }
        
        return result;
    }
};
