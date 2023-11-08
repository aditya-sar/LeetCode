class Solution {
public:
    int n;

    int distributeCandies(vector<int>& a) {
        n = a.size();    
        unordered_map<int, int> mp;
        for(int &x : a) {
            mp[x]++;
        }
        int sz = mp.size();
        return min(n/2, sz);
    }
};