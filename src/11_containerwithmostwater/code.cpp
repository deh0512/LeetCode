class Solution {
public:
    int maxArea(vector<int>& height) {
        auto max = 0;
        for (int i = 0, j = height.size() - 1; i < j;) {
            auto h = min(height[i], height[j]);
            auto a = h * (j - i);
            if (a > max) {
                max = a;
            }
            if (height[i] <= height[j]) ++i;
            else --j;
        }
        return max;
    }
};

