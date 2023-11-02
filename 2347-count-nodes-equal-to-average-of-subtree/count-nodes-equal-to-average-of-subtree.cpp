class Solution {
public:
    int ans = 0;

    vector<int> solve(TreeNode *root) {
        if(!root) {
            return {0, 0};
        }

        vector<int> left = solve(root -> left);
        vector<int> right = solve(root -> right);

        int sum = left[0] + right[0] + root -> val;
        int n = left[1] + right[1] + 1;

        if(sum / n == root -> val) {
            ans++;
        }

        return {sum, n};
    }

    int averageOfSubtree(TreeNode* root) {
        vector<int> ansV = solve(root);
        return ans;
    }
};