class Solution {
public:
    int n, m;

    int getCommon(vector<int>& a, vector<int>& b) {
        n = a.size();
        m = b.size();
        unordered_set<int> st;
        for(int &x : a) {
            st.insert(x);
        }
        for(int &x : b) {
            if(st.find(x) != st.end()) {
                return x;
            }
        }
        return -1;
    }
};