class Solution {
public: 
    int n;
    vector<string> ans;

    vector<string> findWords(vector<string>& words) {
        n = words.size();
        unordered_map<char, int> mp;
        for(char c : "qwertyuiop") {
            mp[c] = 1;
        }
        for(char c : "asdfghjkl") {
            mp[c] = 2;
        }
        for(char c : "zxcvbnm") {
            mp[c] = 3;
        }
        for(string &w : words) {
            unordered_set<int> st;
            for(char &c : w) {
                char x = c >= 'A' && c <= 'Z' ? c-'A'+'a' : c;
                st.insert(mp[x]);
            }
            if(st.size() == 1) {
                ans.push_back(w);
            }
        }    
        return ans;
    }
};