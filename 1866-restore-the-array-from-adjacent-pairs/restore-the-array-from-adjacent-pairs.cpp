class Solution {
public:
    vector<int> ans;
    int n;

    vector<int> restoreArray(vector<vector<int>>& a) {
        n = a.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            mp[a[i][0]].push_back(a[i][1]);
            mp[a[i][1]].push_back(a[i][0]);
        }
        for(pair<int, vector<int>> pr : mp) {
            if(pr.second.size() == 1) {
                ans = {pr.first, pr.second[0]};
                break;
            }
        }
        while(ans.size() <= n) {
            int last = ans[ans.size() - 1];
            int secondLast = ans[ans.size() - 2];
            vector<int> temp = mp[last];
            int next = temp[0] != secondLast ? temp[0] : temp[1];
            ans.push_back(next);
        }
        return ans;
    }
};