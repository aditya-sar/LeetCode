class Solution {
public:
    int n;
    vector<int> ans;

    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        n = nums.size();
        queue<pair<int, int>> q;
        q.push(make_pair(0, 0));
        while(!q.empty()) {
            pair<int, int> pr = q.front();
            q.pop();
            int x = pr.first;
            int y = pr.second;
            ans.push_back(nums[x][y]);
            if(y == 0 and x+1 < n) {
                q.push(make_pair(x+1, 0));
            }
            if(y+1 < nums[x].size()) {
                q.push(make_pair(x, y+1));
            }
        }
        return ans;
    }
};