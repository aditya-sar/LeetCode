class Solution {
public:
    int ans = 0;

    void solve(TreeNode *node, int count) {
        if(!node) {
            return;
        }
        count ^= (1 << node -> val);
        if(!node -> left && !node -> right && (count & (count - 1)) == 0) {
            ans++;
        }
        solve(node -> left, count);
        solve(node -> right, count);
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, 0);   
        return ans;
    }
};