class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        bool dp[s1.size() + 1][s2.size() + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        auto i = 0;
        while (i < s1.size() && (dp[i + 1][0] = s1[i] == s3[i])) ++i;
        auto j = 0;
        while (j < s2.size() && (dp[0][j + 1] = s2[j] == s3[j])) ++j;
        for (i = 1; i <= s1.size(); ++i) {
            for (j = 1; j <= s2.size(); ++j) {
                if (s1[i - 1] == s3[i + j - 1]) dp[i][j] = dp[i - 1][j];
                if (s2[j - 1] == s3[i + j - 1]) dp[i][j] = dp[i][j] || dp[i][j - 1];
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

