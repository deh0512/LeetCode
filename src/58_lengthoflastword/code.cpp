class Solution {
public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while (end >= 0 && s[end] == ' ') --end;
        if (end < 0) return 0;
        auto i = end - 1;
        for (; i >= 0; --i) {
            if (s[i] == ' ') break;
        }
        return end - i;
    }
};

