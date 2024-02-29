class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* curr = root;
        bool even = true;
        while(!q.empty()) {
            int sz = q.size();
            int prev = INT_MAX;
            if(even) prev = INT_MIN;
            for(int i=0; i<sz; i++) {
                curr = q.front();
                q.pop();
                if(even && (curr->val % 2 == 0 || curr->val <= prev)) {
                    return false;
                }
                if(!even) {
                    if(curr->val % 2 != 0 || curr->val >= prev) {
                        return false;
                    }
                }
                prev = curr->val;
                if(curr->left) {
                    q.push(curr->left);
                }
                if(curr->right) {
                    q.push(curr->right);
                }
            }
            even = !even;
        }
        return true;
    }
};