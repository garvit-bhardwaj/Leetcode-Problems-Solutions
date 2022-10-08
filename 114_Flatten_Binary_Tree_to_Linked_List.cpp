class Solution {
public:
   TreeNode* prev =NULL;
    void flatten(TreeNode* node) {
     if(node==NULL){
         return ;
     }
        
        flatten(node->right);
        flatten(node->left);
        
        node->right=prev;
        node->left=NULL;
        
        prev=node;
    }
};
