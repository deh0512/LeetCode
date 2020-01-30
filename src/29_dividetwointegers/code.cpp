class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == INT_MIN) return dividend == INT_MIN ? 1 : 0;
        if (divisor == 1) return dividend;
        if (divisor == -1 && dividend == INT_MIN) return INT_MAX;
        bool negative = (dividend < 0) ^ (divisor < 0);
        auto adjust = false;
        if (dividend == INT_MIN) {
            adjust = true;
            ++dividend;
        }
        auto absDividend = abs(dividend);
        auto absDivisor = abs(divisor);
        if (absDivisor > absDividend) return 0;
        auto quotient = 0;
        auto multAbsDivisor = absDivisor;
        auto step = 1;
        while ((multAbsDivisor & 0xC0000000) == 0 && (multAbsDivisor << 1) < absDividend) {
            multAbsDivisor <<= 1;
            step <<= 1;
        }
        while (true) {
            while (absDividend >= multAbsDivisor) {
                if (negative) quotient -= step;
                else quotient += step;
                absDividend -= multAbsDivisor;
                if (adjust) {
                    ++absDividend;
                    adjust = false;
                }
            }
            if (step == 1) break;
            multAbsDivisor >>= 1;
            step >>= 1;
        }
        return quotient;
    }
};

