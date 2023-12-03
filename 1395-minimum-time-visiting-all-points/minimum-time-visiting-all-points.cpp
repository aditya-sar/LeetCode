class Solution {
public:
    int n, m;
    int ans = 0;

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        n = points.size();
        if(n == 1) {
            return 0;
        }
        for(int i=1; i<n; i++) {
            int x1 = points[i-1][0], y1 = points[i-1][1];
            int x2 = points[i][0], y2 = points[i][1];
            int mx = max(abs(x2 - x1), abs(y2 - y1));
            ans += mx;
        }
        return ans;
    }
};