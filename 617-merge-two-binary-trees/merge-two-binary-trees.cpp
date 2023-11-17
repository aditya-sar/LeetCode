class Solution {
public:
    TreeNode* merge(TreeNode *root1, TreeNode *root2) {
        if(!root1 or !root2) {
            return root1 ? root1 : root2;
        }
        root1 -> val += root2 -> val;
        root1 -> left = merge(root1 -> left, root2 -> left);
        root1 -> right = merge(root1 -> right, root2 -> right);
        return root1;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(!root1 or !root2) {
            return root1 ? root1 : root2;
        }
        merge(root1, root2);
        return root1;
    }
};