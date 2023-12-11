class Solution {
public:
    int n;

    int findSpecialInteger(vector<int>& a) {
        n = a.size();
        unordered_map<int, int> mp;
        for(int &x : a) {
            mp[x]++;
        }
        for(pair<int, int> pr : mp) {
            if(pr.second > n/4) {
                return pr.first;
            }
        }
        return 0;
    }
};