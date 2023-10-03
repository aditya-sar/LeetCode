/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> mp;
    vector<int> ans;

    void solve(TreeNode *root) {
        if(!root) {
            return;
        }
        mp[root -> val]++;
        solve(root -> left);
        solve(root -> right);
    }

    vector<int> findMode(TreeNode* root) {
        solve(root);
        int mx = -1;
        for(pair<int, int> pr : mp) {
            if(pr.second > mx) {
                mx = pr.second;
            }
        }
        for(pair<int, int> pr : mp) {
            if(pr.second == mx) {
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};