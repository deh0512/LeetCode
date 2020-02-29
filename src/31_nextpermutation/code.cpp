class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        auto n = static_cast<int>(nums.size());
        auto i = n - 2;
        for (; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) break;
        }
        if (i >= 0) {
            auto j = n - 1;
            while (nums[j] <= nums[i]) --j;
            std::swap(nums[i], nums[j]);
        }
        std::sort(nums.begin() + i + 1, nums.end());
    }
};

