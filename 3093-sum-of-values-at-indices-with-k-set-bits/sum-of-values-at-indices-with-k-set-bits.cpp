class Solution {
public:
    int n;

    int sumIndicesWithKSetBits(vector<int>& a, int k) {
        n = a.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            if(k == __builtin_popcount(i)) {
                ans += a[i];
            }
        }
        return ans;
    }
};