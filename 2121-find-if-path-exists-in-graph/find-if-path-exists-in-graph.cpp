class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        queue<int> q;
        q.push(source);
        unordered_map<int, vector<int>> mp;
        for(vector<int> edge : edges) {
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
        }
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            if(x == destination) {
                return true;
            }
            vector<int> v = mp[x];
            for(int &node : v) {
                q.push(node);
            }
            mp.erase(x);
        }
        return false;
    }
};