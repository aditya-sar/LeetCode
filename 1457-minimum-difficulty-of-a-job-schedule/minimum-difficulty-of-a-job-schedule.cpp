class Solution {
public:
    vector<vector<int>> dp;
    int n;

    int solve(vector<int> &a, int n, int pos, int d){
        if(d==1) {
            int mx = 0;
            for(int i = pos; i<n; i++){
                mx = max(mx, a[i]);
            }
            return mx;
        }
        if(dp[pos][d]!=-1) {
            return dp[pos][d];
        }
        int mx = 0, mn = INT_MAX;
        for(int i=pos; i<=n-d; i++){
            mx = max(mx, a[i]);
            int temp = solve(a, n, i+1, d-1);
            mn = min(mn, mx+temp);
        }
        return dp[pos][d] = mn;
    }
    int minDifficulty(vector<int>& a, int d) {
        n = a.size();
        dp.resize(400);
        for(int i=0; i<400; i++) {
            dp[i] = vector<int>(20, -1);
        }
        if(n < d) {
            return -1;
        }
        int ans = solve(a, n, 0, d);
        return ans;
    }
};