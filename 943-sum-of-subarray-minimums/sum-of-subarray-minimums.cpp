
class Solution {
public:
    const int mod = 1e9 + 7;
    int n;

    int sumSubarrayMins(vector<int>& a) {
        n = a.size();
        stack<int> stk;
        long ans = 0;
        for(int i=0; i<=n; i++) {
            while(!stk.empty() && (i == a.size() || a[stk.top()] >= a[i])) {
                int mid = stk.top();
                stk.pop();
                int right = i, left = stk.empty() ? -1 : stk.top();
                long count = (mid - left) * (right - mid) % mod;
                ans = (ans + (count * a[mid]) % mod) % mod;
                // ans %= mod;
            }
            stk.push(i);
        }
        return ans;
    }
};

