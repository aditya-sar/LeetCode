class Solution {
public:
    int n;
    vector<int> ans;

    vector<int> dailyTemperatures(vector<int>& a) {
        n = a.size();
        stack<int> stk;
        ans.resize(n);
        for (int i=0; i<n; i++) {
            while(!stk.empty() && a[i] > a[stk.top()]) {
                int pos = stk.top();
                stk.pop();
                ans[pos] = i - pos;
            }
            stk.push(i);
        }
        return ans;
    }
};