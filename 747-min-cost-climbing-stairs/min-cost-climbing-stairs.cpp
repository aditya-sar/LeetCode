class Solution {
public:
    int n, ans = 0;

    int minCostClimbingStairs(vector<int>& a) {
        n = a.size();
        for(int i=2; i<n; i++) {
            a[i] += min(a[i-1], a[i-2]);
        }  
        return min(a[n-1], a[n-2]);
    }
};