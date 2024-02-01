class Solution {
public: 
    int n;
    vector<vector<int>> ans;
    
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        n = nums.size();
        stable_sort(nums.begin(), nums.end());
        vector<int> v;
        for(int i=0; i<n; i+=3) {
            if(nums[i+2] - nums[i] > k) {
                ans.clear();
                return ans;
            }
            ans.push_back({nums[i], nums[i+1], nums[i+2]});
        }
        return ans;
    }
};


/*
    1 3 3 2 7 3 
    1 2 3 3 3 7 
    
*/