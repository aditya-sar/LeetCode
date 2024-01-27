class Solution {
public:
    int mod = 1e9 + 7;

    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(1005, vector<int>(1005));
        dp[0][0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=k; j++) {
                for(int l=0; l<=min(j, i - 1); l++) {
                    if(j - l >= 0) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j - l]) % mod;
                    }
                }
            }
        }
        return dp[n][k];
    }
};