class Solution {
public:
    int n;

    bool uniqueOccurrences(vector<int>& a) {
        n = a.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[a[i]]++;
        }
        unordered_set<int> st;
        for(auto [key, value] : mp) {
            if(st.find(value) != st.end()) {
                return false;
            }
            st.insert(value);
        }
        return true;
    }
};