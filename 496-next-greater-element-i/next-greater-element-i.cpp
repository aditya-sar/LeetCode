class Solution {
public:
    int n, m;
    vector<int> ans;

    vector<int> nextGreaterElement(vector<int>& a, vector<int>& b) {
        n = a.size();
        m = b.size();
        unordered_map<int, int> mp;
        for(int i=0; i<m; i++) {
            mp[b[i]] = i;
        }
        for(int &x : a) {
            bool found = false;
            for(int i=mp[x]+1; i<m; i++) {
                if(b[i]>x) {
                    ans.push_back(b[i]);
                    found = true;
                    break;
                }
            }
            if(!found) {
                ans.push_back(-1);
            }
        }    
        return ans;
    }
};