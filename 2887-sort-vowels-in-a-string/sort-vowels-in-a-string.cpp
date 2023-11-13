class Solution {
public:
    int n;

    string sortVowels(string s) {
        n = s.size();
        string vow = "aeiouAEIOU";
        unordered_set<char> st(vow.begin(), vow.end());
        string t = "";
        for(char &c : s) {
            if(st.find(c) != st.end()) {
                t.push_back(c);
            }
        }
        sort(t.begin(), t.end());
        int pos = 0;
        for(int i=0; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                s[i] = t[pos++];
            }
        }
        return s;
    }
};