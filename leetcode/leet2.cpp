class Solution {
public:
    
    void solve(TreeNode *root, int val, int dep, int ind) {
        if(!root) return;
        if(ind == dep-1) {
            TreeNode *temp = new TreeNode(val);
            TreeNode *temp1 = new TreeNode(val);
            TreeNode *temp2 = root->left, *temp3 = root->right;
            
            root->left = temp;
            root->right = temp1;
            temp->left = temp2;
            temp1->right = temp3;
            return;
        }
        solve(root->left, val, dep, ind+1);
        solve(root->right, val, dep, ind+1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *temp = new TreeNode(val);
            temp->left = root;
            return temp;
        }
        
        solve(root, val, depth, 1);
        return root;
    }
};
