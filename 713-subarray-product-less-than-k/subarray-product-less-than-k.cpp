class Solution {
public:
    int n;

    int numSubarrayProductLessThanK(vector<int>& a, int k) {
        n = a.size();
        if(k == 0) {
            return 0;
        }
        int l = 0, r = 0;
        int prod = 1;
        int ans = 0;
        while(r < n) {
            prod *= a[r++];
            while(l < r && prod >= k) {
                prod /= a[l++];
            }
            ans += (r - l);
        }
        return ans;
    }
};