class Solution {
public:
    int ans = -1;

    void findMax(TreeNode *node, int rootVal) {
        if(!node) {
            return;
        }
        ans = max(ans, abs(rootVal - node -> val));
        findMax(node -> left, rootVal);
        findMax(node -> right, rootVal);
    }

    void solve(TreeNode *node) {
        if(!node) {
            return;
        }
        findMax(node, node -> val);
        solve(node -> left);
        solve(node -> right);
    }

    int maxAncestorDiff(TreeNode* root) {
        // starting from every node calculate all diff bet this node and child node
        solve(root);
        return ans;        
    }
};