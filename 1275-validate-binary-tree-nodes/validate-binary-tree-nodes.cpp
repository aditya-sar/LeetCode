class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& left, vector<int>& right) {
        vector<int> v(n);
        for(int i=0; i<n; ++i) {
            if(left[i] != -1) {
                v[left[i]]++;
            }
            if(right[i] != -1) {
                v[right[i]]++;
            }
        }
        int root = -1;
        for(int i=0; i<n; ++i) {
            if(v[i] == 0) {
                if (root == -1) {
                    root = i;
                }
                else return false;
            }
        }
        if(root == -1) {
            return false;
        }
        vector<bool> vis(n, false);
        queue<int> queue;
        queue.push(root);
        while(!queue.empty()) {
            int node = queue.front(); 
            queue.pop();
            if(vis[node]) {
                return false;
            }
            vis[node] = true;
            if(left[node] != -1) {
                queue.push(left[node]);
            }
            if(right[node] != -1) {
                queue.push(right[node]);
            }
        }
        return accumulate(vis.begin(), vis.end(), 0) == n;
    }
};