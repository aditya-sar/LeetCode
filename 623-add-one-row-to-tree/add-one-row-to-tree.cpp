class Solution {
public:
    TreeNode * solve(TreeNode *root, int val, int depth, int level) {
        if(!root) {
            return NULL;
        }
        if(level == depth - 1) {
            TreeNode *leftNode = root -> left;
            TreeNode *rightNode = root -> right;
            root -> left = new TreeNode(val);
            root -> right = new TreeNode(val);
            root -> left -> left = leftNode;
            root -> right -> right = rightNode;
            return root;
        }
        root -> left = solve(root -> left, val, depth, level + 1);
        root -> right = solve(root -> right, val, depth, level + 1);
        return root;
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1) {
            TreeNode *newNode = new TreeNode(val);
            newNode -> left = root;
            return newNode;
        }
        int level = 1;
        return solve(root, val, depth, level);
    }
};