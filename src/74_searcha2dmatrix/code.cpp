class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        if (matrix[0].empty()) return false;
        if (target < matrix[0][0]) return false;
        auto r = matrix.size() - 1;
        if (target > matrix[r][matrix[r].size() - 1]) return false;
        auto row = findRow(matrix, target, 0, r);
        return searchRow(row, target, 0, row.size() - 1);
    }
    
private:
    const vector<int>& findRow(const vector<vector<int>>& matrix, int target, int min, int max) {
        if (min == max) return matrix[min];
        auto h = ((max - min) / 2) + min;
        if (target < matrix[h][0]) return findRow(matrix, target, min, h);
        if (target > matrix[h][matrix[h].size() - 1]) return findRow(matrix, target, h + 1, max);
        return matrix[h];
    }
    
    bool searchRow(const vector<int>& row, int target, int min, int max) {
        if (min == max) return row[min] == target;
        auto h = ((max - min) / 2) + min;
        if (target > row[h]) return searchRow(row, target, h + 1, max);
        return searchRow(row, target, min, h);
    }
};

