class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;
        int maxDiff = INT_MAX, larger, smaller;
        for(int i=1; i<=area/2+1; i++) {
            if(area%i == 0) {
                if(abs(i - area/i) < maxDiff) {
                    maxDiff = abs(i - area/i);
                    larger = max(i, area/i);
                    smaller = min(i, area/i);
                }
            }
        }
        return {larger, smaller};
    }
};