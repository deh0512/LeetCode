class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        auto max = 0;
        auto m = prices[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; --i) {
            if (m - prices[i] > max) {
                max = m - prices[i];
            }
            if (prices[i] > m) {
                m = prices[i];
            }
        }
        return max;
    }
};

