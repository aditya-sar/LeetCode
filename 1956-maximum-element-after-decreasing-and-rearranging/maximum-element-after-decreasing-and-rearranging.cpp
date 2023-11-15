class Solution {
public:
    int n;

    int maximumElementAfterDecrementingAndRearranging(vector<int>& a) {
        n = a.size();    
        vector<int> count(n);
        for(int i=0; i<n; i++) {
            count[min(a[i]-1, n-1)]++;
        }   
        int ans = 1;
        for(int i=1; i<n; i++) {
            ans = min(i+1, ans + count[i]);
        }
        return ans;
    }
};