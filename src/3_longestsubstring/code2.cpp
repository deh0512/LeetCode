class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) return s.length();
        int cs[256];
        memset(cs, -1, sizeof(cs));
        auto start = 0;
        auto i = 0;
        auto greatest = -1;
        for (; i < s.length(); ++i) {
            int c = s[i] & 0xff;
            if (cs[c] >= start) {
                auto temp = i - start;
                if (temp > greatest) greatest = temp;
                start = cs[c] + 1;
            }
            cs[c] = i;
        }
        if (i == s.length()) {
            auto temp = i - start;
            if (temp > greatest) greatest = temp;
        }
        return greatest;
    }
};

