class Solution {
public:
    int ans = 0;

    void solve(TreeNode *root, int low, int high) {
        if(!root) {
            return;
        }
        if(root -> val >= low && root -> val <= high) {
            ans += root -> val;
        }
        solve(root -> left, low, high);
        solve(root -> right, low, high);
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        solve(root, low, high);    
        return ans;
    }
};