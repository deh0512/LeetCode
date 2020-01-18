class Solution {
public:
    enum Value {
        NONE,
        FALSE,
        TRUE
    };

    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != s1.size() + s2.size()) return false;
        for (auto i = 0; i <= s1.size(); ++i) {
            dp.push_back(vector<Value>(s2.size() + 1));
            fill(dp[i].begin(), dp[i].end(), NONE);
        }
        return dfs(s1, s2, s3, 0, 0, 0) == TRUE;
    }

private:
    vector<vector<Value>> dp{};

    Value dfs(string_view s1, string_view s2, string_view s3, int i, int j, int k) {
        if (k == s3.size()) return TRUE;
        if (dp[i][j] != NONE) return dp[i][j];
        if (s3[k] == s1[i]) {
            if ((dp[i][j] = dfs(s1, s2, s3, i + 1, j, k + 1)) == TRUE) return TRUE;
        }
        if (s3[k] == s2[j]) {
            if ((dp[i][j] = dfs(s1, s2, s3, i, j + 1, k + 1)) == TRUE) return TRUE;
        }
        return dp[i][j] = FALSE;
    }
};

