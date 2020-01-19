class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        int tab[nums.size()];
        memset(tab, 0, sizeof(tab));
        tab[0] = nums[0] % 2 != 0 ? 1 : 0;
        auto cnt = tab[0] == k ? 1 : 0;
        for (auto i = 1; i < nums.size(); ++i) {
            tab[i] = tab[i - 1] + (nums[i] % 2 != 0 ? 1 : 0);
            if (tab[i] == k) ++cnt;
        }
        for (auto i = 1; i <= nums.size() - k; ++i) {
            auto odd = tab[i - 1] == 1;
            for (auto j = i; j < nums.size(); ++j) {
                if (odd) --tab[j];
                if (tab[j] == k) ++cnt;
            }
        }
        return cnt;
    }
};

