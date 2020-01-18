class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        if (board.size() != 9) return false;
        bool rows[9][9];
        bool cols[9][9];
        bool boxes[9][9];
        for (auto i = 0; i < 9; ++i) {
            if (board[i].size() != 9) return false;
            for (auto j = 0; j < 9; ++j) {
                rows[i][j] = false;
                cols[i][j] = false;
                boxes[i][j] = false;
            }
        }
        for (auto i = 0; i < 9; ++i) {
            for (auto j = 0; j < 9; ++j) {
                auto ch = board[i][j];
                if (ch != '.') {
                    int char_idx = (ch - '0') - 1;
                    if (rows[i][char_idx]) {
                        return false;
                    }
                    rows[i][char_idx] = true;
                    if (cols[j][char_idx]) {
                        return false;
                    }
                    cols[j][char_idx] = true;
                    auto box_idx = (3 * (i / 3)) + (j / 3);
                    if (boxes[box_idx][char_idx]) {
                        return false;
                    }
                    boxes[box_idx][char_idx] = true;
                }
            }
        }
        return true;
    }
};

