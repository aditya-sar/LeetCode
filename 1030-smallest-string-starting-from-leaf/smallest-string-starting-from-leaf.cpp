class Solution {
public:
    set<string> st;

    void solve(TreeNode *root, string s) {
        s.push_back(root -> val + 'a');
        if(!root -> left && !root -> right) {
            reverse(s.begin(), s.end());
            st.insert(s);
            return;
        }
        if(root -> left) {
            solve(root -> left, s);
        }
        if(root -> right) {
            solve(root -> right, s);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        solve(root, "");
        return *st.begin();
    }
};