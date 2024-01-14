class Solution {
public:
    int n, m;
    vector<int> vs, vt;

    bool closeStrings(string s, string t) {
        n = s.size();
        m = t.size();
        vs.resize(26);
        vt.resize(26);
        for(char c : s) {
            vs[c-'a']++;
        }
        for(char c : t) {
            vt[c-'a']++;
        }
        for(int i=0; i<26; i++) {
            if(vs[i] && !vt[i] || vt[i] && !vs[i]) {
                return false;
            }
        }
        sort(vs.begin(), vs.end());
        sort(vt.begin(), vt.end());
        for(int i=0; i<26; i++) {
            if(vs[i] != vt[i]) {
                return false;
            }
        }
        return true;
    }
};