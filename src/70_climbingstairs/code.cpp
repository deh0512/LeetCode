class Solution {
public:
    int climbStairs(int n) {
        dp.resize(n);
        fill(dp.begin(), dp.end(), -1);
        if (n <= 0) {
            return 0;
        }
        return searchClimbs(n);
    }
    
private:
    int searchClimbs(int n) {
        if (n < 2) {
            return 1;
        }
        if (dp[n - 1] >= 0) {
            return dp[n - 1];
        }
        return dp[n - 1] =
            (n >= 2 ? searchClimbs(n - 2) : 0) +
            searchClimbs(n - 1);
    }
    
    vector<int> dp{};
};

