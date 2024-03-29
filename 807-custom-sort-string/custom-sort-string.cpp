class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> mp;
        for(char c : s) {
            mp[c]++;
        }
        string ans = "";
        for(char c : order) {
            if(mp[c]) {
                while(mp[c]--) {
                    ans.push_back(c);
                }
                mp[c] = 0;
            }
        }
        for(char let = 'a'; let <= 'z'; let++) {
            if(mp[let]) {
                while(mp[let]--) {
                    ans.push_back(let);
                }
            }
        }
        return ans;
    }
};