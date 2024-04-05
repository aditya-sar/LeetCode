class Solution {
public:
    int n;
    string ans = "";
    
    string makeGood(string s) {
        n = s.size();
        stack<char> st;
        int diff = abs('a' - 'A');
        for(int i=0; i<n; i++) {
            if(st.empty()) {
                st.push(s[i]);
            }
            else if(abs(st.top() - s[i]) == diff) {
                st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;      
    }
};