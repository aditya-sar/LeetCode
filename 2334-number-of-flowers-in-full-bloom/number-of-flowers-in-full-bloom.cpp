class Solution {
public:
    int n;

    vector<int> fullBloomFlowers(vector<vector<int>>& a, vector<int>& p) {
        vector<int> st, bt; 
        n = a.size();
        for(auto i : a) {
            int x = i[0];
            int y = i[1];
            st.push_back(x);
            bt.push_back(y);
        }
        sort(st.begin(), st.end());
        sort(bt.begin(), bt.end());
        vector<int> ans; 
        for(int i=0; i<p.size(); i++) {
            int low = st.size() - (upper_bound(st.begin(), st.end(), p[i]) - st.begin());
            int high = bt.size() - (lower_bound(bt.begin(), bt.end(), p[i]) - bt.begin());
            ans.push_back(abs(high - low));
        }
        return ans; 
    }
};
