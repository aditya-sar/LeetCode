class Solution {
public:
    void dfs(vector<int> adj[], int n, int node, int prev, vector<int> &height, vector<int> &subtree) {
        subtree[node]++;
        for(auto &edge:adj[node]) {
            if(edge!=prev){
                height[edge] = 1 + height[node];
                dfs(adj,n,edge,node,height,subtree);
                subtree[node] += subtree[edge];
            }
        }
    }

    void rec(vector<int> adj[], int n, int node, int prev, vector<int> &subtree, vector<int> &dp) {
        for(auto &edge:adj[node]) {
            if(edge!=prev) {
                dp[edge] = dp[node] - subtree[edge] + (n-subtree[edge]);
                rec(adj, n, edge, node, subtree, dp);
            }
        }
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &edge : edges){
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> height(n,0), subtree(n,0); 
        vector<int> dp(n,0); 

        dfs(adj,n,0,-1,height,subtree);

        for(int i=0; i<n; i++) {
            dp[0] += height[i];
        }

        rec(adj,n,0,-1,subtree,dp);

        return dp;
    }
};