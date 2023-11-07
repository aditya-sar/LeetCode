class Solution {
public:
    bool compare(TreeNode *root, TreeNode *subroot) {
        if(!root && !subroot) {
            return true;
        }
        if(!root || !subroot) {
            return false;
        }
        if(root -> val != subroot -> val) {
            return false;
        }
        return compare(root -> left, subroot -> left) &&
            compare(root -> right, subroot -> right);
    }

    bool solve(TreeNode *root, TreeNode *subroot) {
        if(!root) {
            return false;
        }
        if(compare(root, subroot)) {
            return true;
        }
        return solve(root -> left, subroot) || solve(root -> right, subroot);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return solve(root, subRoot);
    }
};