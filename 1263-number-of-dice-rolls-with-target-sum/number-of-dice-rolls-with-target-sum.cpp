class Solution {
public:
    using ll = long long;
    int mod = 1e9 + 7;
    
    int numRollsToTarget(int n, int k, int target) {
        if(n * k < target) {
            return 0;
        }
        vector<vector<ll>> dp(n+1, vector<ll>(target+1));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=i; j <= min(i * k, target); j++) {
                for(int l=1; l <= min(k, j); l++) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % mod;
                }
            }
        }
        return int(dp[n][target]);
    }
};