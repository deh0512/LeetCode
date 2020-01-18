class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1l = word1.length();
        int w2l = word2.length();
        int dp[w1l + 1][w2l + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 0;
        for (auto i = 1; i <= w1l; ++i) dp[i][0] = i;
        for (auto j = 1; j <= w2l; ++j) dp[0][j] = j;
        for (auto i = 1; i <= w1l; ++i) {
            for (auto j = 1; j <= w2l; ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else {
                    auto ins = dp[i][j - 1] + 1;
                    auto del = dp[i - 1][j] + 1;
                    auto rep = dp[i - 1][j - 1] + 1;
                    dp[i][j] = min(ins, min(del, rep));
                }
            }
        }
        return dp[w1l][w2l];
    }
};

