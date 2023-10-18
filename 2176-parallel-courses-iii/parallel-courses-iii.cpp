class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& a, vector<int>& time) {
        unordered_map<int, vector<int>> graph;
        vector<int> dict(n+1, 0);
        for(auto& v : a) {
            graph[v[0]].push_back(v[1]);
            dict[v[1]]++;
        }
        vector<int> distance = time;
        distance.insert(distance.begin(), 0);
        queue<int> q;
        for(int i=1; i<=n; i++) {
            if(dict[i] == 0) {
                q.push(i);
            }
        }
        while(!q.empty()) {
            int course = q.front(); q.pop();
            for(int c : graph[course]) {
                distance[c] = max(distance[c], distance[course] + time[c - 1]);
                dict[c]--;
                if(dict[c] == 0) {
                    q.push(c);
                }
            }
        }
        return *max_element(distance.begin(), distance.end());
    }
};