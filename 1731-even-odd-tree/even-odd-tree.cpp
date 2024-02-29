class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool even = true;
        while(!q.empty()) {
            int sz = q.size();
            int prev = even ? INT_MIN : INT_MAX;
            for(int i=0; i<sz; i++) {
                TreeNode *node = q.front();
                q.pop();
                if(even && (node->val % 2 == 0 || node->val <= prev)) {
                    return false;
                }
                if(!even) {
                    if(node->val % 2 != 0 || node->val >= prev) {
                        return false;
                    }
                }
                prev = node->val;
                if(node->left) {
                    q.push(node->left);
                }
                if(node->right) {
                    q.push(node->right);
                }
            }
            even = !even;
        }
        return true;
    }
};