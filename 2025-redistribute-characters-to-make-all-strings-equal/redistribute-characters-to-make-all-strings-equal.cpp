class Solution {
public:
    int n;

    bool makeEqual(vector<string>& a) {
        n = a.size();
        unordered_map<char, int> mp;
        for(string w : a) {
            for(char c : w) {
                mp[c]++;
            }
        }
        for(pair<char, int> pr : mp) {
            if (pr.second % n != 0) {
                return false;
            }
        }
        return true;
        
    }
};