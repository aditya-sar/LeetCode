class Solution {
public:
    int n;

    vector<int> rearrangeArray(vector<int>& a) {
        n = a.size();
        vector<int> pos, neg;
        for(int i=0; i<n; i++) {
            if(a[i] >= 0) {
                pos.push_back(a[i]);
            }
            else {
                neg.push_back(a[i]);
            }
        }
        vector<int> ans;
        for(int i=0; i<n/2; i++) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
        }
        return ans;
    }
};