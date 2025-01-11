class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> mp;
        for(char &c : s) {
            mp[c]++;
        }
        int odd = 0;
        for(pair<char, int> pr : mp) {
            if(pr.second % 2 == 1) {
                odd++;
            }
        }
        if(odd > k || s.size() < k) {
            return false;
        }
        return true;
    }
};

/*
    anabelle 
    a - 2
    n - 1 
    b - 1
    e - 2
    l - 2


*/