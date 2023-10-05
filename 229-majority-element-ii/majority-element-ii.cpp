class Solution {
public:
    int n;
    vector<int> ans;
    unordered_map<int, int> mp;

    vector<int> majorityElement(vector<int>& a) {
        n = a.size();
        int target = n/3;
        for(int &x : a) {
            mp[x]++;
        }    
        for(pair<int, int> pr : mp) {
            if(pr.second > target) {
                ans.push_back(pr.first);
            }
        }
        return ans;
    }
};