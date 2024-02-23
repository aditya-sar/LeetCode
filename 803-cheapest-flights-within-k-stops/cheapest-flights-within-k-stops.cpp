int fastIO = []{cin.tie(0) -> sync_with_stdio(0); return 0;}();
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& a, int src, int dst, int k) {
        vector<pair<int, int>> v[n];
        for(vector<int> &flight : a) {
            v[flight[0]].push_back({flight[1], flight[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            pair<int, pair<int, int>> pr = q.front();
            q.pop();
            int stops = pr.first, node = pr.second.first, cost = pr.second.second;
            if(stops > k) {
                continue;
            }
            for(pair<int, int> &newPair : v[node]) {
                int adjNode = newPair.first;
                int weight = newPair.second;
                if(cost + weight < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + weight;
                    q.push({stops + 1, {adjNode, cost + weight}});
                }
            }
        }
        if(dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};