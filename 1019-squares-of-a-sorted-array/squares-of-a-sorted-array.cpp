class Solution {
public:
    int n;

    vector<int> sortedSquares(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        for(int x : nums) {
            v.push_back(x*x);
        }  
        stable_sort(v.begin(), v.end());
        return v;
    }
};