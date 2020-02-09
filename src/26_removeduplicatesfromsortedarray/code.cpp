class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto l = nums.empty() ? 0 : 1;
        for (auto i = 1, j = 0; i < nums.size(); ++i) {
            if (nums[i] != nums[j]) {
                ++j;
                ++l;
                if (i != j) nums[j] = nums[i];
            }
        }
        return l;
    }
};

