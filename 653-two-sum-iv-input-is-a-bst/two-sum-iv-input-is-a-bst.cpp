class Solution {
public:
    unordered_set<int> st;

    bool solve(TreeNode *root, int k) {
        if(!root) {
            return false;
        }    
        if(st.find(k - root -> val) != st.end()) {
            return true;
        }
        st.insert(root -> val);
        return solve(root -> left, k) || solve(root -> right, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return solve(root, k);
    }
};