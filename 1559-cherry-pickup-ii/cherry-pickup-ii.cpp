class Solution {
public:
    int px[3] = {0,-1,1};
    int dp[71][71][71];

    int dfs(vector<vector<int>>& a, int pos, int c1, int c2, int n, int m) {
        if(pos == n) {
            return 0;
        }
        if(c1<0 || c2<0 || c1>=m || c2>=m) {
            return INT_MIN;
        }
        if(dp[pos][c1][c2] != -1) {
            return dp[pos][c1][c2];
        }
        int ans = 0;
        for(int k=0; k<3; k++){
            for(int r=0; r<3; r++){
                ans = max(ans, dfs(a, pos+1, c1 + px[k], c2 + px[r] , n, m));
            }
        }
        ans += (c1==c2) ? a[pos][c1] : a[pos][c1] + a[pos][c2];
        return dp[pos][c1][c2] = ans;
    }

    int cherryPickup(vector<vector<int>>& a) {
        int n = a.size(); 
        int m  = a[0].size(); 
        memset(dp,-1,sizeof dp);
        return dfs(a, 0, 0, m-1, n, m);
    }
};
