class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int d) {
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == d)
                return false;

            if (board[row][i] == d) {
                return false;
            }
        }

        int start_i = row / 3 * 3;
        int start_j = col / 3 * 3;

        for (int k = 0; k < 3; k++) {
            for (int l = 0; l < 3; l++) {
                if (board[start_i + k][start_j + l] == d) {
                    return false;
                }
            }
        }

        return true;
    }
    bool solver(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isValid(board, i, j,val)) {
                            board[i][j] = val;
                            if (solver(board)==1)
                                return true;
                            board[i][j] = '.';
                        }
                    }
                    // this means i tried for all 9 values but no one is working
                    // this means that means in past any value is incorrect
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
        
    }
};