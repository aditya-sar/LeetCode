class Solution {
public:
    int mod = 1e9 + 7;
    int n;

    int countHomogenous(string s) {
        n = s.size();
        long long ans = 0;
        char c = s[0];
        long long count = 0;
        for(int i=0; i<n; i++) {
            if(s[i] == c) {
                count++;
            }
            else {
                ans += ((count)*(count + 1) / 2) % mod;
                c = s[i];
                count = 0;
                i--;
            }
        }
        ans += (count * (count + 1) / 2) % mod;
        return ans;
    }
};