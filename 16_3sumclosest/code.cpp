class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return 0;
        sort(nums.begin(), nums.end());
        auto closest = INT_MAX;
        for (auto i = 0; i < nums.size() - 2;) {
            auto first = nums[i];
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                auto current = first + nums[j] + nums[k];
                if (closest == INT_MAX || abs(target - current) < abs(target - closest)) {
                    closest = current;
                }
                if (nums[j] < target - (first + nums[k])) {
                    while (j < k && nums[++j] == nums[j - 1]);
                }
                else {
                    while (k > j && nums[--k] == nums[k + 1]);
                }
            }
            while (i < nums.size() - 2 && nums[++i] == nums[i - 1]);
        }
        return closest;
    }
};

