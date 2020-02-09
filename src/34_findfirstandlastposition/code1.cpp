class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        auto lesser = search(nums, 0, nums.size() - 1, target - 1);
        if (lesser >= nums.size()) return {-1, -1};
        auto greater = search(nums, 0, nums.size() - 1, target + 1);
        if (greater <= 0 || lesser == greater) return {-1, -1};
        while (lesser < nums.size() && nums[lesser] < target) ++lesser;
        while (--greater >= 0 && nums[greater] > target);
        if (lesser > greater) return {-1, -1};
        return {lesser, greater};
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

