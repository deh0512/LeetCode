class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return s;
        auto longestCenter = 0;
        auto longestLength = 1;
        for (auto i = 0; i < s.length(); ++i) {
            if (i < s.length() - 1 && s[i] == s[i + 1]) {
                for (int j = i, k = i + 1; j >= 0 && k < s.length(); --j, ++k) {
                    if (s[j] != s[k]) break;
                    auto l = k - j + 1;
                    if (l > longestLength) {
                        longestLength = l;
                        longestCenter = i;
                    }
                }
            }
            for (int j = i - 1, k = i + 1; j >= 0 && k < s.length(); --j, ++k) {
                if (s[j] != s[k]) break;
                auto l = k - j + 1;
                if (l > longestLength) {
                    longestLength = l;
                    longestCenter = i;
                }
            }
        }
        return s.substr(longestCenter - ((longestLength - 1) / 2), longestLength);
    }
};

