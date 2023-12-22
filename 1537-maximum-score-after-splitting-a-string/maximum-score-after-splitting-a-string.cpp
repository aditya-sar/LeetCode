class Solution {
public:
    int n;

    int maxScore(string s) {
        n = s.size();
        int ans = 0;
        for(int i=1; i<n; i++) {
            string left = s.substr(0, i);
            string right = s.substr(i, n-i);
            int zero = 0, one = 0;
            for(char c : left) {
                zero += c == '0' ? 1 : 0;
            }
            for(char c : right) {
                zero += c == '1' ? 1 : 0;
            }
            ans = max(ans, zero + one);
        }
        return ans;
    }
};