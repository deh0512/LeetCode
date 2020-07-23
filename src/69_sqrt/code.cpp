class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) return 0;
        if (x <= 3) return 1;
        return search(2, x / 2, x);
    }
    
private:
    std::int32_t search(std::int32_t min, std::int32_t max, std::int32_t x) {
        auto h = std::int64_t{((max - min) / 2) + min};
        if (h <= min) return min;
        if (h * h > x) return search(min, h, x);
        return search(h, max, x);
    }
};

