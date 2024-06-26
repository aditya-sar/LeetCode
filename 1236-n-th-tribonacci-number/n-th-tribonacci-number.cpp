class Solution {
public:
    int tribonacci(int n) {
        vector<int> v = {0, 1, 1};
        for(int i=3; i<n+1; i++) {
            int sum = v[i-3] + v[i-2] + v[i-1];
            v.push_back(sum);
        }
        return v[n];
    }
};