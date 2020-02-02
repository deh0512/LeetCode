class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (nums.empty()) return 0;
        return search(nums, 0, nums.size() - 1, target);
    }
    
private:
    int search(vector<int>& nums, int left, int right, int target) {
        if (left == right) return target > nums[right] ? right + 1 : left;
        auto center = ((right - left) / 2) + left;
        if (nums[center] == target) return center;
        if (nums[center] > target) return search(nums, left, center, target);
        if (center == right) return center + 1;
        return search(nums, center + 1, right, target);
    }
};

