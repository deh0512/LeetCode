class Solution {
public:
    int numTrees(int n) {
        dp.resize(n);
        fill(dp.begin(), dp.end(), -1);
        return numTreesSearch(n);
    }
    
private:
    vector<int> dp{};
    
    int numTreesSearch(int n) {
        if (n <= 2) {
            return n;
        }
        if (dp[n - 1] >= 0) {
            return dp[n - 1];
        }
        auto num = 2 * numTreesSearch(n - 1);
        for (auto i = 1; i < n / 2; ++i) {
            num += (2 * (numTreesSearch(n - (i + 1)) * numTreesSearch(i)));
        }
        if ((n % 2) != 0) {
            num += numTreesSearch((n - 1) / 2) * numTreesSearch((n - 1) / 2);
        }
        dp[n - 1] = num;
        return num;
    }
};

