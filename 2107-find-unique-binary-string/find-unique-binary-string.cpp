class Solution {
public:
    int n;
    string ans = "";

    string binary(int num, int n) {
        string s = "";
        while(num > 0) {
            s.push_back(num % 2 == 0 ? '0' : '1');
            num /= 2;
        }
        int req = n - s.size();
        for(int i=0; i<req; i++) {
            s.push_back('0');
        }
        reverse(s.begin(), s.end());
        return s;
    }

    string findDifferentBinaryString(vector<string>& a) {
        n = a.size();
        unordered_set<int> st;
        for(string &s : a) {
            int mul = 1;
            int dig = 0;
            for(int i=s.size()-1; i>=0; i--) {
                dig += (s[i] - '0') * mul;
                mul *= 2;
            }
            st.insert(dig);
        }    
        for(auto it : st) {
            cout << it << ' ';
        }
        int len = pow(2, n);
        for(int i=0; i<len; i++) {
            if(st.find(i) == st.end()) {
                cout << endl << i;
                ans = binary(i, n);
                break;
            }
        }
        return ans;
    }
};