class Solution {
public:
    int n;
    int ans = INT_MAX;
    vector<vector<int>> dp;

    int dfs(vector<vector<int>> &grid, int row, int col) {
        if(col < 0 || col >= n) {
            return INT_MAX;
        }
        if(row == n-1) {
            return grid[row][col];
        }
        if(dp[row][col] != -1) {
            return dp[row][col];
        }
        int total = INT_MAX;
        for(int c = 0; c < n; c++) {
            if(col == c) {
                continue;
            }
            total = min(total, grid[row][col] + dfs(grid, row + 1, c));
        }
        return dp[row][col] = total;
    }


    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();    
        dp = vector<vector<int>>(n+1, vector<int>(n+1, -1));
        for(int col = 0; col < n; col++) {
            ans = min(ans, dfs(grid, 0, col));
        }
        return ans;
    }
};