class Solution {
public:
    int n;
    int ans = 0;
    unordered_map<char, int> mp1, mp2;

    int minSteps(string s, string t) {
        n = s.size();
        for(int i=0; i<n; i++) {
            mp1[s[i]]++;
            mp2[t[i]]++;
        }
        for(char c='a'; c<='z'; c++) {
            ans += abs(mp1[c] - mp2[c]);
        }
        return (ans >> 1);
    }
};