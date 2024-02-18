class Solution {
public:
    using ll = long long;
    int ans = 0;

    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> rooms(n);
        int m = meetings.size();
        sort(meetings.begin(),meetings.end());
        priority_queue<int,vector<int>,greater<int>> avail;
        for(int i =0;i<n;i++) {
            avail.push(i);
        }
        priority_queue<pair<ll ,int>, vector<pair<ll,int>>, greater<pair<ll ,int>>> current;
        for(vector<int> v : meetings){
            while(!current.empty() && current.top().first <= v[0]){
                avail.push(current.top().second);
                current.pop();
            }
            ll duration = v[1] - v[0];
            ll start;
            if(avail.empty()){
                start = current.top().first;
            } 
            else {
                start = v[0];
            }
            int room = avail.empty() ? current.top().second : avail.top();
            if(avail.empty()) {
                current.pop();
            }
            else {
                avail.pop();
            }
            rooms[room]++;

            current.push({start + duration , room});
        }
        int mx = 0;
        for(int i =0;i<n;i++){
            if(rooms[i] > mx){
                mx = rooms[i];
                ans = i;
            }
        }
        return ans;
    }
};