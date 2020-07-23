class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty() && b.empty()) {
            return "0";
        }
        auto maxLen = std::max(a.length(), b.length());
        auto carry = 0;
        auto output = std::stringstream{};
        for (auto i = 0u; i < maxLen; ++i) {
            auto x = i < a.length() ? a[a.length() - i - 1] - '0' : 0;
            auto y = i < b.length() ? b[b.length() - i - 1] - '0' : 0;
            auto sum = x + y + carry;
            output << (sum % 2);
            carry = sum / 2;
        }
        if (carry > 0) {
            output << '1';
        }
        auto outStr = output.str();
        std::reverse(outStr.begin(), outStr.end());
        return outStr;
    }
};

