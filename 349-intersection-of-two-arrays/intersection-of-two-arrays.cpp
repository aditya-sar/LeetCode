class Solution {
public:
    vector<int> ans;

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st(nums1.begin(), nums1.end()), stAns;
        for(int &x : nums2) {
            if(st.find(x) != st.end()) {
                stAns.insert(x);
            }
        }
        return vector<int>(stAns.begin(), stAns.end());
    }
};