/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans = INT_MIN;

    void solve(Node *root, int depth) {
        ans = max(ans, depth);
        if(!root) {
            return;
        }
        vector<Node *> v = root -> children;
        for(int i=0; i<v.size(); i++) {
            solve(v[i], depth+1);
        }
    }

    int maxDepth(Node* root) {
        if(!root) {
            return 0;
        }
        int depth = 1;
        solve(root, depth);
        return ans;
    }
};