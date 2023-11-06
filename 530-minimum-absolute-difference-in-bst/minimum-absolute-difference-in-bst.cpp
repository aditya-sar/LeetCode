class Solution {
public:
    vector<int> v;

    void solve(TreeNode *root) {
        v.push_back(root -> val);
        if(root -> left) {
            solve(root -> left);
        }
        if(root -> right) {
            solve(root -> right);
        }
    }

    int getMinimumDifference(TreeNode* root) {
        solve(root);  
        sort(v.begin(), v.end());
        int ans = INT_MAX;
        for(int i=1; i<v.size(); i++) {
            ans = min(ans, v[i] - v[i-1]);
        }
        return ans;
    }
};