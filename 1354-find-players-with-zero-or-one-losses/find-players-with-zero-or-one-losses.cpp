class Solution {
public:
    int n;
    unordered_map<int, pair<int, int>> mp;

    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        n = matches.size();
        for(int i=0; i<n; i++) {
            mp[matches[i][0]].first++;
            mp[matches[i][1]].second++;
        }
        set<int> notLost, lostOnly1;
        for(pair<int, pair<int, int>> pr : mp) {
            if(pr.second.second == 0) {
                notLost.insert(pr.first);
            }
            else if(pr.second.second == 1) {
                lostOnly1.insert(pr.first);
            }
        }
        return {
            vector<int>(notLost.begin(), notLost.end()), 
            vector<int>(lostOnly1.begin(), lostOnly1.end())
        };
    }
};


// Winner 
// Lost exactly 1 match 
        