class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0) return false;
        initialize(board);
        for (auto y = 0; y <= max_y; ++y) {
            for (auto x = 0; x <= max_x; ++x) {
                if (dfs(board, word, 0, x, y)) return true;
            }
        }
        return false;
    }
    
private:
    int max_x;
    int max_y;
    vector<vector<bool>> used{};

    void initialize(const vector<vector<char>>& board) {
        max_y = board.size() - 1;
        max_x = board[0].size() - 1;
        for (auto y = 0; y <= max_y; ++y) {
            used.emplace_back();
            for (auto x = 0; x <= max_x; ++x) {
                used[y].push_back(false);
            }
        }
    }
    
    bool dfs(const vector<vector<char>>& board, const string& word, int letter, int pos_x, int pos_y) {
        if (letter >= word.size()) return true;
        if (board[pos_y][pos_x] == word[letter]) {
            used[pos_y][pos_x] = true;
            auto lp1 = letter + 1;
            auto xm1 = pos_x - 1;
            if (pos_x > 0 && !used[pos_y][xm1]) {
                if (dfs(board, word, lp1, xm1, pos_y)) return true;
            }
            auto ym1 = pos_y - 1;
            if (pos_y > 0 && !used[ym1][pos_x]) {
                if (dfs(board, word, lp1, pos_x, ym1)) return true;
            }
            auto xp1 = pos_x + 1;
            if (pos_x < max_x && !used[pos_y][xp1]) {
                if (dfs(board, word, lp1, xp1, pos_y)) return true;
            }
            auto yp1 = pos_y + 1;
            if (pos_y < max_y && !used[yp1][pos_x]) {
                if (dfs(board, word, lp1, pos_x, yp1)) return true;
            }
            if (lp1 >= word.size()) return true;
            used[pos_y][pos_x] = false;
        }
        return false;
    }
};

