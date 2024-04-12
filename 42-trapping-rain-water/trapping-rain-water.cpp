class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        vector<int> left(n), right(n);
        int maxLeft = 0, maxRight = 0;
        for(int i=0; i<n; i++) {
            if(a[i] > maxLeft) {
                left[i] = a[i];
                maxLeft = a[i];
            }
            else {
                left[i] = maxLeft;
            }
            if(a[n-1-i] > maxRight) {
                right[n-1-i] = a[n-1-i];
                maxRight = a[n-1-i];
            }
            else {
                right[n-1-i] = maxRight;
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans += (min(left[i], right[i]) - a[i]);
        }
        return ans;
    }
};