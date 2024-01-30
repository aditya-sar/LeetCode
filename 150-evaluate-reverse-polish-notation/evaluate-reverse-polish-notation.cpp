class Solution {
public:
    bool isOperator(string s) {
        // Returns true if string is a mathematical operator
        return s == "-" || s == "+" || s == "*" || s == "/";
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string s : tokens) {
            if(isOperator(s)) {
                int y = stk.top();  // 2nd element in sequence
                stk.pop();
                int x = stk.top();  // 1st element in sequence
                stk.pop();
                int val = 0;
                if(s == "+") {
                    val = x + y;
                }
                else if(s == "-") {
                    val = x - y;
                }
                else if(s == "*") {
                    val = x * y;
                }
                else {
                    val = x / y;
                }
                stk.push(val);
            }
            else {
                stk.push(stoi(s));
            }
        }
        // Stack will contain only the answer at the end
        return stk.top();
    }
};