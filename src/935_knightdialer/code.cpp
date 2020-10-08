class Solution {
public:
    int knightDialer(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 10;
        vector<unsigned long> prior{};
        auto cur = vector<unsigned long>(10, 1ul);
        for (auto curHops = 1; curHops < n; ++curHops) {
            prior = move(cur);
            cur = vector<unsigned long>(10, 0ul);
            for (auto i = 0; i < 10; ++i) {
                for (auto j = 0; j < hops[i].size(); ++j) {
                    cur[i] += prior[hops[i][j]];
                }
                cur[i] %= modVal;
            }
        }
        return accumulate(cur.begin(), cur.end(), 0ul) % modVal;
    }
    
private:
    const unsigned long modVal = pow(10, 9) + 7;
    const vector<vector<int>> hops{
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {0, 3, 9},
        {},
        {0, 1, 7},
        {2, 6},
        {1, 3},
        {2, 4},
    };
};

