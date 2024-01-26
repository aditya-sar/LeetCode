class Solution {
public:
    vector<vector<vector<int>>> dp;
    int mod = 1e9 + 7;
    int m, n;

    int solve(int maxMove, int x, int y, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) {
            return 1;
        }
        if (maxMove <= 0) {
            return 0;
        }
        if (dp[x][y][maxMove] != -1) {
            return dp[x][y][maxMove];
        }
        int count = 0;
        count = (count + solve(maxMove - 1, x + 1, y, n, m)) % mod;
        count = (count + solve(maxMove - 1, x, y - 1, n, m)) % mod;
        count = (count + solve(maxMove - 1, x - 1, y, n, m)) % mod;
        count = (count + solve(maxMove - 1, x, y + 1, n, m)) % mod;
        dp[x][y][maxMove] = count;
        return count;
    }
    

    int findPaths(int n, int m, int maxMove, int startRow, int startColumn) {
        dp = vector<vector<vector<int>>>(n, vector<vector<int>>(m, vector<int>(maxMove + 1, -1)));
        return solve(maxMove, startRow, startColumn, n, m);
    }
};