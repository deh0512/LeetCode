class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows < 1) return "";
        if (s.empty() || numRows == 1 || s.length() < numRows) return s;
        auto skip = numRows + (numRows - 2);
        stringstream ss{};
        for (auto i = 0; i < s.length(); i += skip) ss << s[i];
        for (auto r = 1; r < numRows - 1; ++r) {
            auto zig = true;
            for (auto i = r; i < s.length();
                 i += zig ? skip - r * 2: r * 2, zig = !zig) ss << s[i];
        }
        for (auto i = numRows - 1; i < s.length(); i += skip) ss << s[i];
        return ss.str();
    }
};

