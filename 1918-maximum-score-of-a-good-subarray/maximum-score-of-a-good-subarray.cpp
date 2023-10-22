class Solution {
public:
    int n;

    int maximumScore(vector<int>& a, int k) {
        n = a.size();
        int left = k, right = k, mn = a[k], ans = a[k];
        while(left > 0 || right < n - 1) {
            if(left == 0 || (right < n - 1 && a[right + 1] > a[left - 1])) {
                right++;
            } 
            else {
                left--;
            }
            mn = min({mn, a[left], a[right]});
            ans = max(ans, mn * (right - left + 1));
        }
        return ans;
    }
};