class Solution {
public:
    using ll = long long;
    ll ans = 0, n;

    int maxFrequency(vector<int>& a, int k) {
        n = a.size();
        sort(a.begin(), a.end());
        ll sum = 0, r = 0;
        for (ll j=0, i=0; i<n; i++) {
            sum += a[i];
            while ((i - r + 1) * a[i] - sum > k) {
                sum -= a[r];
                r++;
            }
            ans = max(ans, i - r + 1);
        }
        return ans;
    }
};