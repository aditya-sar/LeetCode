class Solution {
    int n;

    int solve(vector<string>& a, int pos, unordered_map<char, bool> mp){
        if(pos == n) {
            return 0;
        }
        int skip = solve(a, pos+1, mp); 
        for(char c : a[pos]) {
            if(mp[c]) {
                return skip;
            }
            mp[c] = true;
        }
        int sz = a[pos].size();
        int take = sz + solve(a, pos+1, mp);
        return max(take, skip);
    }
public:
    int maxLength(vector<string>& a) {
        n = a.size();
        unordered_map<char, bool> mp;
        return solve(a, 0, mp);
    }
};