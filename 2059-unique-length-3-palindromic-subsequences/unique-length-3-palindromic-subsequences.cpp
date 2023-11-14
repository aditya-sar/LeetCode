class Solution {
public:
    int n;
    int ans = 0;

    int countPalindromicSubsequence(string s) {
        n = s.size();
        vector<int> minMap(26, INT_MAX), maxMap(26, INT_MIN);
        for(int i=0; i<n; i++) {
            int pos = s[i] - 'a';
            minMap[pos] = min(minMap[pos], i);
            maxMap[pos] = max(maxMap[pos], i);
        }
        for(int i=0; i<26; i++) {
            if(maxMap[i] == INT_MIN || minMap[i] == INT_MAX) {
                continue;
            }
            unordered_set<char> st;
            for(int j=minMap[i]+1; j < maxMap[i]; j++) {
                st.insert(s[j]);
            }
            ans += st.size();
        }
        return ans;
    }
};