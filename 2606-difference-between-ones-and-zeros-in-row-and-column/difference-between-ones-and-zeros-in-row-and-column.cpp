class Solution {
public:
    int n, m;

    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<int> rows(m), cols(n);
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                rows[j] += grid[i][j];
                cols[i] += grid[i][j];
            }
        }
        for(int j=0; j<m; j++) {
            for(int i=0; i<n; i++) {
                grid[i][j] = 2 * rows[j] + 2 * cols[i] - m - n;
            }
        }
        return grid;
    }
};