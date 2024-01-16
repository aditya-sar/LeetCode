class Solution {
public:
    stack<int> stk;

    int calPoints(vector<string>& ops) {
        for(string &s : ops) {
            if(stk.empty()) {
                stk.push(stoi(s));
            }
            else {
                if(s == "C") {
                    stk.pop();
                }
                else if(s == "D") {
                    stk.push(stk.top() * 2);
                }
                else if(s == "+") {
                    int x = stk.top();
                    stk.pop();
                    int y = stk.top();
                    stk.push(x);
                    stk.push(x + y);
                }
                else {
                    stk.push(stoi(s));
                }
            }
        }    
        int ans = 0;
        while(!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }
        return ans;
    }
};