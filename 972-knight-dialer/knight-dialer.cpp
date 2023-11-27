class Solution {
public:
    int mod = 1e9 + 7;
    int dp[5001][10];
    vector<vector<int>> squares = {
        {4, 6},
        {8, 6},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4},
    };
    
    int knightDialer(int n, vector<int>& numbers) {
        if(n == 1) {
            return numbers.size();
        }
        int count = 0;
        for(int num : numbers) {
            int curr = dp[n][num];
            if(curr == 0) {
                curr = knightDialer(n - 1, squares[num]);
                dp[n][num] = curr;
            }
            count += curr;
            count %= mod;
        }
        return count;
    }

    int knightDialer(int n) {
        vector<int> numbers = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        return knightDialer(n, numbers);
    }

};