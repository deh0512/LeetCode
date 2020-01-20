class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> output{};
        for (auto i = 0; i < nums.size() - 3;) {
            auto first = nums[i];
            for (auto j = i + 1; j < nums.size() - 2;) {
                auto second = nums[j];
                for (int s = j + 1, t = nums.size() - 1; s < t;) {
                    if (first + second + nums[s] + nums[t] == target) {
                        output.push_back({first, second, nums[s], nums[t]});
                        while (s < t && nums[++s] == nums[s - 1]);
                        while (t > s && nums[--t] == nums[t + 1]);
                    }
                    else if (nums[s] < target - first - second - nums[t]) {
                        ++s;
                    }
                    else {
                        --t;
                    }
                }
                while (j < nums.size() - 2 && nums[++j] == nums[j - 1]);
            }
            while (i < nums.size() - 3 && nums[++i] == nums[i - 1]);
        }
        return output;
    }
};

