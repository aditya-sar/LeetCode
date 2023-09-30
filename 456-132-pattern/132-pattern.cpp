class Solution {
public:
    int n;

    bool find132pattern(vector<int>& a) {
        n = a.size();    
        int third = INT_MIN;
        stack<int> stk;
        for(int i=n-1; i>=0; i--) {
            if(a[i] < third) {
                return true;
            }
            while(!stk.empty() && stk.top() < a[i]) {
                third = stk.top();
                stk.pop();
            }
            stk.push(a[i]);
        }
        return false;
    }
};