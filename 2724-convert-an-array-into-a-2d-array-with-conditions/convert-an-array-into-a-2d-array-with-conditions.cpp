/*

1,3,4,1,2,3,1

1 -> 1
2 -> 0
3 -> 0
4 -> 0

1 2 3 4 
1 3 
1

*/

class Solution {
public:
    vector<vector<int>> ans;
    int n;

    vector<vector<int>> findMatrix(vector<int>& nums) {
        n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]]++;
        }
        unordered_map<int, int> :: iterator it;
        while(!mp.empty()) {
            vector<int> numRow;
            for(it = mp.begin(); it != mp.end();) {
                numRow.push_back(it -> first);
                it -> second--;
                if(it -> second == 0) {
                    it = mp.erase(it);
                }
                else {
                    it++;
                }
            }
            ans.push_back(numRow);
        }
        return ans;
    }
};

