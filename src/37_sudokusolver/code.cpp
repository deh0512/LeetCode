class Solution {
public:
    enum subsection : int {
        ROW = 0,
        COL = 1,
        BOX = 2
    };

    void solveSudoku(vector<vector<char>>& board) {
        if (initialize(board)) dfs(board, 0, 0);
    }

private:
    bool possible[3][9][9]{};

    bool initialize(const vector<vector<char>>& board) {
        if (board.size() != 9) return false;
        for (auto i = 0; i < 9; ++i) {
            if (board[i].size() != 9) return false;
            for (auto j = 0; j < 9; ++j) {
                possible[ROW][i][j] = true;
                possible[COL][i][j] = true;
                possible[BOX][i][j] = true;
            }
        }
        for (auto i = 0; i < 9; ++i) {
            for (auto j = 0; j < 9; ++j) {
                auto ch = board[i][j];
                if (ch != '.') {
                    auto x = (ch - '0') - 1;
                    auto b = (3 * (i / 3)) + (j / 3);
                    for (auto k = 0; k < 9; ++k) {
                        if (k != x) {
                            possible[ROW][i][x] = false;
                            possible[COL][j][x] = false;
                            possible[BOX][b][x] = false;
                        }
                    }
                }
            }
        }
        return true;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j) {
        if (i >= 9) return true;
        auto next_i = j >= 8 ? i + 1 : i;
        auto next_j = j >= 8 ? 0 : j + 1;
        if (board[i][j] == '.') {
            auto b = (3 * (i / 3)) + (j / 3);
            for (auto x = 0; x < 9; ++x) {
                if (possible[ROW][i][x] &&
                    possible[COL][j][x] &&
                    possible[BOX][b][x]) {
                    possible[ROW][i][x] = false;
                    possible[COL][j][x] = false;
                    possible[BOX][b][x] = false;
                    board[i][j] = (x + 1) + '0';
                    if (dfs(board, next_i, next_j)) return true;
                    possible[ROW][i][x] = true;
                    possible[COL][j][x] = true;
                    possible[BOX][b][x] = true;
                }
            }
            board[i][j] = '.';
        }
        else return dfs(board, next_i, next_j);
        return false;
    }
};

