class Solution {
public:
    set<int> st;

    void solve(TreeNode *root) {
        if(!root) {
            return;
        }
        st.insert(root -> val);
        solve(root -> left);
        solve(root -> right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        solve(root);    
        if(st.size() == 1) {
            return -1;
        }
        set<int>::iterator it = st.begin();
        advance(it, 1);
        return *it;
    }
};