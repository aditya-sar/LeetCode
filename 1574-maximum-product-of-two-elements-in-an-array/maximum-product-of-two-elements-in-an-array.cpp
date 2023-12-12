class Solution {
public:
    int n;

    int maxProduct(vector<int>& a) {
        n = a.size();
        stable_sort(a.begin(), a.end());
        int ans = (a[n-1]-1) * (a[n-2] - 1);
        return ans;
    }
};