class Solution {
public:
    int n;

    int openLock(vector<string>& deadends, string target) {
        n = deadends.size();
        unordered_set<string> st(deadends.begin(), deadends.end());

        // If target in deadend, then not possible to open : return -1;
        if(st.find(target) != st.end() || st.find("0000") != st.end()) {
            return -1;
        }

        queue<pair<string, int>> q;
        q.push({"0000", 0});

        // Already visited combinations
        unordered_set<string> vis;
        vis.insert("0000");
        
        // BFS 
        while(!q.empty()) {
            pair<string, int> pr = q.front();
            q.pop();
            string s = pr.first;
            int moves = pr.second;
            if(s == target) {
                return moves;
            }

            // Make current digit one less and one more to check
            for(int i=0; i<4; i++) {
                for(int diff : {-1, 1}) {
                    string t = s;
                    t[i] = '0' + ((t[i] - '0' + diff + 10) % 10);
                    if(vis.find(t) == vis.end() && st.find(t) == st.end()) {
                        vis.insert(t);
                        q.push({t, moves + 1});
                    }    
                }
            }
        }
        return -1;
    }
};