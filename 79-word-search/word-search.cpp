class Solution {
public:
    int n, m;
    int px[4] = {0, 0, -1, 1};
    int py[4] = {-1, 1, 0, 0};

    bool checkPos(int x, int y) {
        return x>=0 && y>=0 && x<n && y<m;
    }

    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int pos) {
        if(pos == word.size()) {
            return true;
        }
        if(!checkPos(x, y) || board[x][y] != word[pos]) {
            return false;
        }
        char c = board[x][y];
        board[x][y] = '#';
        for(int k=0; k<4; k++) {
            if(dfs(board, x+px[k], y+py[k], word, pos+1)) {
                return true;
            }
        }
        board[x][y] = c;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }    
        return false;
    }
};