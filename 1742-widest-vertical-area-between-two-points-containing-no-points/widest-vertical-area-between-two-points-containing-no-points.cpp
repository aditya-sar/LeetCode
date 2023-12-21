class Solution {
public:
    int n; 

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end());
        int maxDiff = -1;
        for(int i=1; i<n; i++) {
            maxDiff = max(maxDiff, points[i][0] - points[i-1][0]);
        }
        return maxDiff;
    }
};