class Solution {
public:
    
    int solve(TreeNode *root, unordered_map<TreeNode*, int> &dp) {
        if(!root) {
            return 0;
        }
        
        if(dp.count(root)) {
            return dp[root];
        }
        
        int take = root->val, not_take = 0;
        
        if(root->left) {
            take += solve(root->left->left, dp);
            take += solve(root->left->right, dp);
        }
        if(root->right) {
            take += solve(root->right->left, dp);
            take += solve(root->right->right, dp);
        }
        
        not_take += solve(root->right, dp) + solve(root->left, dp);
        
        return dp[root] = max(take, not_take);            
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return solve(root, dp);
    }
};
