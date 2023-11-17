class Solution {
public:
    int n;

    int maximumProduct(vector<int>& a) {
        n = a.size();
        sort(a.begin(), a.end());
        int plus = a[n-1] * a[n-2] * a[n-3];
        int minus = a[0] * a[1] * a[n-1];
        return max(plus, minus);
    }
};