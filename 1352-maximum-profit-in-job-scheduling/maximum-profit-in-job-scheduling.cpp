class Solution {
public:
    int n;
    int ans = 0;
    vector<int> dp;

    int solve(vector<vector<int>> &v, int pos) {
        if(pos >= n) {
            return 0;
        }
        if(dp[pos] != -1) {
            return dp[pos];
        }
        int skip = solve(v, pos+1);
        vector<int> location = {v[pos][1], 0, 0};
        int nextPos = lower_bound(v.begin(), v.end(), location) - v.begin();
        int take = v[pos][2] + solve(v, nextPos);
        return dp[pos] = max(take, skip);
    }

    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        n = profit.size();
        vector<vector<int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({start[i], end[i], profit[i]});
        }
        sort(v.begin(), v.end());
        dp.resize(50001, -1);
        return solve(v, 0);
    }
};