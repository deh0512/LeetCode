class Solution {
public:
    bool isMatch(string s, string p) {
        int dp[(s.length() + 1) * (p.length() + 1)];
        memset(dp, 0, sizeof(dp));
        return search(dp, s, p, 0, 0);
    }
    
private:
    bool search(int* dp, string_view text, string_view pattern, int i, int j) {
        if (i > text.length() || j > pattern.length()) return false;
        if (j == pattern.length()) return i == text.length();
        if (i == text.length()) {
            return j < pattern.length() - 1 &&
                   pattern[j + 1] == '*' &&
                   search(dp, text, pattern, i, j + 2);
        }
        int dp_index = (pattern.length() * i) + j;
        if (dp[dp_index] != 0) return dp[dp_index] == 1;
        if (j < pattern.length() - 1 && pattern[j + 1] == '*') {
            if (search(dp, text, pattern, i + 1, j + 2) &&
                (pattern[j] == '.' || text[i] == pattern[j])) {
                dp[dp_index] = 1;
                return true;
            }
            if (search(dp, text, pattern, i + 1, j) &&
                (pattern[j] == '.' || text[i] == pattern[j])) {
                dp[dp_index] = 1;
                return true;
            }
            if (search(dp, text, pattern, i, j + 2)) {
                dp[dp_index] = 1;
                return true;
            }
            dp[dp_index] = -1;
            return false;
        }
        if ((pattern[j] == '.' || text[i] == pattern[j]) &&
            search(dp, text, pattern, i + 1, j + 1)) {
            dp[dp_index] = 1;
            return true;
        }
        dp[dp_index] = -1;
        return false;
    }
};

