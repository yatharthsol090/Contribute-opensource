class Solution {
public:
    
    bool solve(TreeNode *root1, TreeNode *root2) {
        if(!root1 and !root2) return true;
        if(!root1 or !root2) return false;
        
        return (root1->val == root2->val) and solve(root1->left, root2->right) and solve(root1->right, root2->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return solve(root, root);
    }
};
