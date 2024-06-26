class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> mp1, mp2;
        for(int i=0; i<n; i++) {
            if(mp1[s[i]] and mp1[s[i]] != t[i] or mp2[t[i]] and mp2[t[i]] != s[i]) {
                return false;
            }
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
        return true;
    }
};