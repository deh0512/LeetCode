class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen{};
        for (auto i = 0; i < nums.size(); ++i) {
            auto diff = target - nums[i];
            auto already = seen.find(diff);
            if (already != seen.end()) {
                return {(*already).second, i};
            }
            seen.emplace(nums[i], i);
        }
        return {-1, -1};
    }
};

