class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        map<char, int> tMap, sMap;
        int ptr = 0, count = 0, mn = INT_MAX;
        string ans = "";
        for(int i=0; i<m; i++) {
            tMap[t[i]]++;
        }
        for(int i=0; i<n; i++) {
            if(tMap.find(s[i]) != tMap.end()) {
                // letter from s found in t
                sMap[s[i]]++;
                if(sMap[s[i]] <= tMap[s[i]]) {
                    count++;
                }
            }
            if(count == m) {
                // found a possible window
                while(sMap[s[ptr]] > tMap[s[ptr]] || tMap[s[ptr]] == 0) {
                    if(sMap[s[ptr]] > tMap[s[ptr]]) {
                        sMap[s[ptr]]--;    
                    }
                    ptr++;
                }
                if(i - ptr + 1 < mn) {
                    mn = i - ptr + 1;
                    ans = s.substr(ptr, i - ptr + 1);
                }
            }
        }
        return ans;
    }
};