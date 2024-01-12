class Solution {
public:
    int n;
    int left = 0, right = 0;
    unordered_set<char> st;

    
    bool halvesAreAlike(string s) {
        n = s.size();
        string vow = "aeiouAEIOU";
        st = unordered_set<char>(vow.begin(), vow.end());
        for(int i=0; i<n/2; i++) {
            if(st.find(s[i]) != st.end()) {
                left++;
            }
        }
        for(int i=n/2; i<n; i++) {
            if(st.find(s[i]) != st.end()) {
                right++;
            }
        }
        return left == right;
    }
};