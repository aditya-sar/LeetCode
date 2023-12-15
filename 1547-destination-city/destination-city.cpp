class Solution {
public:
    int n;
    unordered_map<string, string> mp;

    string solve(string &s) {
        if(mp.find(s) == mp.end()) {
            return s;
        }
        return solve(mp[s]);
    }

    string destCity(vector<vector<string>>& paths) {
        n = paths.size();
        for(vector<string> &v : paths) {
            mp[v[0]] = v[1];
        }  
        return solve(paths[0][0]);
    }
};