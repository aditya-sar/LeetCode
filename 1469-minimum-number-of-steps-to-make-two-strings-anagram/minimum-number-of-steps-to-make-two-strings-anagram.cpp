class Solution {
public:
    int n;
    int ans = 0;
    unordered_map<char, int> mp1, mp2;

    int minSteps(string s, string t) {
        n = s.size();
        for(char &c : s) {
            mp1[c]++;
        }
        for(char &c : t) {
            mp2[c]++;
        }
        for(char c='a'; c<='z'; c++) {
            ans += abs(mp1[c] - mp2[c]);
        }
        ans = (ans >> 1);
        return ans;

        // bab
        // aba

        // abb
        // aab


        // a = 1
        // b = 2

        // a = 1
        // b = 2

    }
};