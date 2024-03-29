class Solution {
public:
    int n;

    unordered_set<int> solve(int n) {
        unordered_set<int> factors;
        for(int i=2; i<= sqrt(n); i++) {
            while(n%i == 0) {
                factors.insert(i);
                n /= i;
            }
        }
        if(n > 1) {
            factors.insert(n);
        }
        return factors;
    }

    void dfs(int i, unordered_set<int>& vis, vector<vector<int>>& adjList) {
        vis.insert(i);
        for(int node: adjList[i]) {
            if(vis.find(node) == vis.end()) {
                dfs(node, vis, adjList);
            }
        }
    }

    bool canTraverseAllPairs(vector<int> &nums) {
        n = nums.size();
        vector<vector<int>> adjList(n);
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++) {
            unordered_set<int> pf = solve(nums[i]);
            for(int x : pf){
                if(mp.find(x) != mp.end()) {
                    int prev = mp[x];
                    adjList[prev].push_back(i);
                    adjList[i].push_back(prev);
                }
                mp[x] = i;
            }
        }
        unordered_set<int> vis;
        dfs(0, vis, adjList);
        return vis.size() == n;
    }
};