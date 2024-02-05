class Solution {
public:
    int n;

    int firstUniqChar(string s) {
        n = s.size();
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c] += 1;
        }
        for(int i=0; i<n; i++) {
            if(mp[s[i]] == 1) {
                return i;
            }
        }
        return -1;
    }
};