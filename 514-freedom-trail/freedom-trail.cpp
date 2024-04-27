class Solution 
{
public:
    int method(int ringPos,int keyPos, string ring, string key,int m,int n, vector<vector<int>>&dp) {
        if(keyPos==n) {
          return 0;
        }
        if(dp[ringPos][keyPos]!=-1) {
          return dp[ringPos][keyPos];
        }
        int ans = INT_MAX;
        for(int i=0; i<m; i++) {
            if(ring[i] == key[keyPos]) {
                int count = min(abs(ringPos-i), m-abs(ringPos - i));
                ans = min(ans, count + method(i, keyPos+1, ring, key, m, n,dp));
            }
        }
        return dp[ringPos][keyPos] = ans;
    }
    int findRotateSteps(string ring, string key) {
        int ringPos=0,keyPos=0;
        int n = key.size();
        int m = ring.size();
        vector<vector<int>>dp(m, vector<int>(n,-1));
        return method(ringPos,keyPos,ring, key,m,n,dp)+n;
    }
};