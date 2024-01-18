class Solution {
public:
    unordered_map<int, int> mp;

    int solve(int n) {
        if(n < 2) {
            return 1;
        }
        if(mp.find(n) != mp.end()) {
            return mp[n];
        }
        int ans = solve(n-1) + solve(n-2);
        return mp[n] = ans;
    }
    int climbStairs(int n) {
        if(n == 1) {
            return 1;
        }
        int ans = solve(n-1) + solve(n-2);
        return ans;
    }
};