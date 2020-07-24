class Solution {
private:
    enum class Direction {
        RIGHT,
        DOWN,
        LEFT,
        UP
    };
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        const auto total = matrix.size() * matrix[0].size();
        auto output = vector<int>{};
        output.reserve(total);
        auto left = 0;
        auto right = static_cast<int>(matrix[0].size() - 1);
        auto top = 0;
        auto bottom = static_cast<int>(matrix.size() - 1);
        auto direction = Direction::RIGHT;
        auto visited = 0;
        while (visited < total) {
            switch (direction) {
                case Direction::RIGHT:
                    for (auto i = left; i <= right; ++i, ++visited) {
                        output.push_back(matrix[top][i]);
                    }
                    ++top;
                    direction = Direction::DOWN;
                    break;
                case Direction::DOWN:
                    for (auto i = top; i <= bottom; ++i, ++visited) {
                        output.push_back(matrix[i][right]);
                    }
                    --right;
                    direction = Direction::LEFT;
                    break;
                case Direction::LEFT:
                    for (auto i = right; i >= left; --i, ++visited) {
                        output.push_back(matrix[bottom][i]);
                    }
                    --bottom;
                    direction = Direction::UP;
                    break;
                case Direction::UP:
                    for (auto i = bottom; i >= top; --i, ++visited) {
                        output.push_back(matrix[i][left]);
                    }
                    ++left;
                    direction = Direction::RIGHT;
                    break;
            };
        }
        return output;
    }
};

