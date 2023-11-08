class Solution {
public:
    vector<string> findRestaurant(vector<string>& a, vector<string>& b) {
        map<string,int> mp;
        vector<string> ans;
        for(int i=0; i<a.size(); i++) {
            if(mp.find(a[i]) == mp.end()) {
                mp.insert({a[i], i});
            }
        }
        int mn = INT_MAX;
        for(int i=0; i<b.size(); i++) {
            if(mp.find(b[i]) != mp.end()) {
                if(mp[b[i]] + i < mn){
                    mn = mp[b[i]] + i;
                }
            }
        }
        for(int i=0; i<b.size(); i++) {
            if(mp.find(b[i]) != mp.end() && mp[b[i]] + i == mn) {
                ans.push_back(b[i]);
            }
        }
        return ans;
    }
};