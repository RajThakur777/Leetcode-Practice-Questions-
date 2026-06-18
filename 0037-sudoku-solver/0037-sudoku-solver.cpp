class Solution {
public:
    bool isCheck(int row , int col , char digit , vector<vector<char>> &board) {
        for(int j=0; j<9; j++) {
            if(board[row][j] == digit) {
                return false;
            }
        }

        for(int i=0; i<9; i++) {
            if(board[i][col] == digit) {
                return false;
            }
        }

        int sr = (row - (row % 3));
        int sc = (col - (col % 3));

        for(int i=sr; i<sr+3; i++) {
            for(int j=sc; j<sc+3; j++) {
                if(board[i][j] == digit) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                if(board[i][j] == '.') {
                    for(char ch='1'; ch<='9'; ch++) {
                        if(isCheck(i , j , ch , board)) {
                            board[i][j] = ch;
                            if(solve(board) == true) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};