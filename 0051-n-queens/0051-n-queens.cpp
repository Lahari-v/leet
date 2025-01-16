class Solution {
public:
    bool isSafe(int r, int c, int n, vector<string>& board) {
        int dupeRow = r; 
        int dupeCol = c;
        while(r>=0 && c>=0) {
            if(board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        r = dupeRow;
        c = dupeCol;
        while(c>=0) {
            if(board[r][c] == 'Q')
                return false;
            c--;
        }
        r = dupeRow;
        c = dupeCol;
        while(r<n && c>=0) {
            if(board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
        return true;
    }
    void solve(int c, int n, vector<string>& board, vector<vector<string>>& res) {
        if(c == n) {
            res.push_back(board);
            return;
        }
        for(int r=0; r<n; r++) {
            if(isSafe(r, c, n, board)) {
                board[r][c] = 'Q';
                solve(c+1, n, board, res);
                board[r][c] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n; i++) {
            board.push_back(s);
        }
        solve(0, n, board, res);
        return res;
    }
};