class Solution {
public:
    int n, m;

    int solve(vector<int> &cost, vector<int> &time, int pos, int bank, vector<vector<int>> &dp){
        if(bank <= 0) {
            return 0;
        }
        if(pos >= n) {
            return 1e9;   
        }
        if(dp[pos][bank] != -1){
            return dp[pos][bank];
        }
        int skip = solve(cost, time, pos+1, bank, dp);
        int take = cost[pos] + solve(cost, time, pos+1, bank-time[pos]-1, dp); 
        return dp[pos][bank] = min(skip, take);      
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        n = cost.size();
        m = time.size();
        vector<vector<int>> dp(501, vector<int>(501, -1));
        return solve(cost, time, 0, m, dp);
    }
};