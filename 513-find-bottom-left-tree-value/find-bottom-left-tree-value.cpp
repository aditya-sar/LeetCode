class Solution {
public:
    int ans = 0;

    void bfs(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            ans = node -> val;
            if(node -> right) {
                q.push(node -> right);
            }
            if(node -> left) {
                q.push(node -> left);
            }
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        bfs(root);
        return ans;
    }
};