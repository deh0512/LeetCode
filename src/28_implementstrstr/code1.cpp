class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        auto i = 0;
        for (; i < haystack.length(); ++i) {
            auto j = 0;
            while (i + j < haystack.length() &&
                   j < needle.length() &&
                   haystack[i + j] == needle[j]) ++j;
            if (j == needle.length()) return i;
        }
        return -1;
    }
};

