class Solution {
public:
    int n, m;
    
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        m = nums1.size();
        n = nums2.size();
        vector<int> curr(n+1, INT_MIN), prev(n+1, INT_MIN);
        for(int i=1; i<=m; ++i) {
            for(int j=1; j<=n; ++j) {
                curr[j] = max({
                    nums1[i-1] * nums2[j-1], 
                    prev[j], 
                    curr[j-1], 
                    nums1[i-1] * nums2[j-1] + max(0, prev[j-1])
                });
            }
            swap(curr, prev);
        }
        return prev[n];
    }
};