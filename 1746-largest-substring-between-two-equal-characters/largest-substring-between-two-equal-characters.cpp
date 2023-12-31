class Solution {
public:
    int n;
    int ans = -1;

    int maxLengthBetweenEqualCharacters(string s) {
        n = s.size();
        for(int l=0; l<n; l++) {
            for(int r=l+1; r<n; r++) {
                if(s[l] == s[r]) {
                    ans = max(ans, r - l - 1);
                }
            }
        }
        return ans;
    }
};