class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        if (nums.empty()) return 0;
        unordered_map<int, int> seen{};
        auto odds = 0;
        auto subs = 0;
        for (auto i = 0; i < nums.size(); ++i) {
            odds += nums[i] % 2;
            ++seen[odds];
            if (odds == k) subs += seen[0] + 1;
            else subs += seen[odds - k];
        }
        return subs;
    }
};

