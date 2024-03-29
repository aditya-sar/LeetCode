class Solution {
public:
    using ll = long long;
    ll n, ans = 0;

    long long countSubarrays(vector<int>& a, int k) {
        n = static_cast<ll>(a.size());
        ll mx = *max_element(a.begin(), a.end());
        ll l = 0, r = 0;
        while(r < n) {
            if(a[r] == mx) {
                k--;
            }
            r++;
            while(k == 0) {
                if(a[l] == mx) {
                    k++;
                }
                l++;
            }
            ans += l;
        }
        return ans;
    }
};