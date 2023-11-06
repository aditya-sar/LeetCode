class Solution {
public:
    int ans = INT_MAX;

    void solve(TreeNode *root, int &prev) {
        if(root -> left) {
            solve(root -> left, prev);
        }
        if(prev >= 0) {
            ans = min(ans, root -> val - prev);
        }
        prev = root -> val;
        if(root -> right) {
            solve(root -> right, prev);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        solve(root, prev);
        return ans;
    }
};