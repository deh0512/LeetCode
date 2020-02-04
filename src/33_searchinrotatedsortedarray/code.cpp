class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return search(nums, 0, nums.size() - 1, target);
    }
    
private:
    int search(vector<int>& nums, int left, int right, int target) {
        if (left == right) return target == nums[right] ? right : -1;
        auto center = ((right - left) / 2) + left;
        if (nums[center] == target) return center;
        if ((target < nums[left] &&
             (nums[center] < nums[left] || target < nums[center])) ||
            (target > nums[left] && target > nums[center] && nums[center] >= nums[left]))
            return search(nums, center + 1, right, target);
        return search(nums, left, center, target);
    }
};

