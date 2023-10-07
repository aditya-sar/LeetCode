class Solution {
public:
    int dp[51][101][51], prefix[51][101][51];
    int mod = 1e9 + 7;
        
    int numOfArrays(int n, int m, int k) {
        for (int i=0; i<=m; i++) {
            dp[1][i][1] = 1;
            prefix[1][i][1] = i;
        }
        for (int len=2; len<=n; len++) {
            for (int mx=1; mx<=m; mx++) {
                for (int cost=1; cost<=k; cost++) {
                    dp[len][mx][cost] = 
                    (static_cast<long long>(1) * mx * dp[len-1][mx][cost]) % mod;

                    dp[len][mx][cost] = 
                    (dp[len][mx][cost] + prefix[len-1][mx-1][cost-1]) % mod;             
                    
                    prefix[len][mx][cost] = 
                    (prefix[len][mx-1][cost] + dp[len][mx][cost]) % mod;
                }
            }
        }
        return prefix[n][m][k];
    }
};