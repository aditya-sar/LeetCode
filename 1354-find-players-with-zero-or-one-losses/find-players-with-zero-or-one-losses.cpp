class Solution {
public:
    int n;
    vector<vector<int>> ans;
    unordered_map<int, int> losers, winners;

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        n = matches.size();
        for(int i=0; i<n; i++) {
            winners[matches[i][0]]++;
            losers[matches[i][1]]++;
        }
        vector<int> v1, v2;
        for(pair<int, int> pr : winners) {
            if(losers.find(pr.first) == losers.end()) {
                v1.push_back(pr.first);
            }
        }
        for(pair<int, int> pr : losers) {
            if(pr.second == 1) {
                v2.push_back(pr.first);
            }
        }
        stable_sort(v1.begin(), v1.end());
        stable_sort(v2.begin(), v2.end());
        return {v1, v2};
    }
};