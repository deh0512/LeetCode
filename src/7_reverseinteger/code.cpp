class Solution {
public:
    int reverse(int x) {
        int sign = x >= 0 ? 1 : -1;
        long y = abs(static_cast<long>(x));
        long reversed = 0;
        while (y > 0) {
            long current = y % 10;
            reversed = (reversed * 10) + current;
            y = y / 10;
        }
        reversed *= sign;
        return reversed > INT_MAX || reversed < INT_MIN ? 0 : static_cast<int>(reversed);
    }
};

