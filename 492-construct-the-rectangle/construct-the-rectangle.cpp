class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> ans;
        int maxDiff = INT_MAX, dividend, divisor;
        for(int i=1; i<=area/2+1; i++) {
            if(area%i == 0) {
                if(abs(i - area/i) < maxDiff) {
                    maxDiff = abs(i - area/i);
                    dividend = max(i, area/i);
                    divisor = min(i, area/i);
                }
            }
        }
        return {dividend, divisor};
    }
};