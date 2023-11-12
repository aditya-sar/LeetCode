class Solution {
public:
    int n;

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        n = routes.size();
        if(source == target) {
            return 0;
        }
        unordered_map<int,vector<int>> mp;
        for(int i=0; i<routes.size(); i++){
            for(int stop : routes[i]){
                mp[stop].push_back(i);
            }
        }
        vector<int> a(n, 0);
        queue<int> q;
        q.push(source);
        int buses = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                int stop = q.front(); 
                q.pop();
                if(stop == target) {
                    return buses;
                }
                for(int stn : mp[stop]){
                    if(a[stn]) {
                        continue;
                    }
                    a[stn] = 1;
                    for(int nextStn : routes[stn]){
                        q.push(nextStn);
                    }
                }
            }
            buses++;
        }
        return -1;
    }
};