class Solution {
public:
    vector<int> ans;
    vector<int> findAllPeople(int n, vector<vector<int>>& a, int fp) { 
        vector<vector<pair<int,int>>> adjList(n);
        for(int i = 0; i < a.size(); ++i){
            adjList[a[i][0]].push_back({a[i][1],a[i][2]});
            adjList[a[i][1]].push_back({a[i][0],a[i][2]});
        }
        priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>>> pq;
        pq.push({0, fp});
        pq.push({0, 0});
        vector<bool> vis(n,false);
        while(!pq.empty()) {
            pair<int,int> elem = pq.top();
            pq.pop();
            int person = elem.second;
            int time = elem.first;
            if(vis[person]) {
                continue;
            }
            vis[person] = true;
            for(pair<int,int> adj : adjList[person]) {
                if(!vis[adj.first] && time <= adj.second){
                    pq.push({adj.second,adj.first});
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(vis[i]) {
                ans.push_back(i);        
            }
        }
        return ans;
    }
};