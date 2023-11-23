class Solution {
public:
    int n, m;
    vector<bool> ans;

    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        n = nums.size();
        m = l.size();
        for(int i=0; i<m; i++) {
            int left = l[i];
            int right = r[i];
            vector<int> v = vector<int>(nums.begin() + left, nums.begin() + right + 1);
            sort(v.begin(), v.end());
            int diff = v[1] - v[0];
            bool possible = true;
            for(int i=2; i<v.size(); i++) {
                if(v[i] - v[i-1] != diff) {
                    possible = false;
                    break;
                }
            }
            ans.push_back(possible);
        }
        return ans;
    }
};