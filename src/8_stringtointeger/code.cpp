class Solution {
public:
    int myAtoi(string str) {
        size_t i = 0;
        while (i < str.length() && str[i] == ' ') ++i;
        if (i >= str.length()) return 0;
        auto sign = 1;
        if (str[i] == '+') {
            ++i;
        }
        else if (str[i] == '-') {
            sign = -1;
            ++i;
        }
        if (i >= str.length()) return 0;
        auto value = 0l;
        for (; i < str.length(); ++i) {
            if (str[i] >= '0' && str[i] <= '9') {
                value = (value * 10) + (str[i] - '0');
                if (value * sign < INT_MIN) {
                    return INT_MIN;
                }
                else if (value * sign > INT_MAX) {
                    return INT_MAX;
                }
            }
            else {
                break;
            }
        }
        return value * sign;
    }
};

