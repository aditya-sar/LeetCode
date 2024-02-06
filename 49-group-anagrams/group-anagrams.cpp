class Solution {
public:
    int n;
    vector<vector<string>> ans;

    vector<vector<string>> groupAnagrams(vector<string>& a) {
        n = a.size();
        unordered_map<string, vector<string>> mp;
        for(int i=0; i<n; i++) {
            string s = a[i];
            stable_sort(s.begin(), s.end());
            mp[s].push_back(a[i]);
        }    
        for(pair<string, vector<string>> pr : mp) {
            vector<string> v;
            for(string s : pr.second) {
                v.push_back(s);
            }
            ans.push_back(v);
        }
        return ans;
    }
};