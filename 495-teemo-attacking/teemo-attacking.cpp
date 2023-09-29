class Solution {
public:
    int n, ans = 0;

    int findPoisonedDuration(vector<int>& time, int d) {
        n = time.size();
        int end = -1;
        for(int i=0; i<n; i++) {
            ans += d;
            if(end >= time[i]) {
                ans -= (end-time[i] + 1);
            }
            end = time[i]+d-1;
        }
        return ans;
    }
};