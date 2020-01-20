class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() < 3) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> output{};
        for (auto i = 0; i < nums.size() - 2;) {
            auto first = nums[i];
            for (int j = i + 1, k = nums.size() - 1; j < k;) {
                if (first + nums[j] + nums[k] == 0) {
                    output.push_back({first, nums[j], nums[k]});
                    while (j < k && nums[++j] == nums[j - 1]);
                    while (k > j && nums[--k] == nums[k + 1]);
                }
                else if (nums[j] < -first - nums[k]) {
                    ++j;
                }
                else {
                    --k;
                }
            }
            while (i < nums.size() - 2 && nums[++i] == nums[i - 1]);
        }
        return output;
    }
};

