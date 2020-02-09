class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        auto i = search(nums, 0, nums.size() - 1, target);
        if (i < 0) return {-1, -1};
        auto left = searchLeft(nums, i, target);
        auto right = searchRight(nums, i, target);
        return {left, right};
    }
    
private:
    int search(vector<int>& nums, int left, int right, int target) {
        if (left == right) return nums[left] == target ? left : -1;
        auto center = ((right - left) / 2) + left;
        if (nums[center] == target) return center;
        if (nums[center] > target) return search(nums, left, center, target);
        return search(nums, center + 1, right, target);
    }
    
    int searchLeft(vector<int>& nums, int right, int target) {
        auto i = search(nums, 0, right, target);
        return i < 0 || i == right ? right : searchLeft(nums, i, target);
    }
    
    int searchRight(vector<int>& nums, int left, int target) {
        auto i = search(nums, left, nums.size(), target);
        return i < 0 || i == left ? left : searchRight(nums, i, target);
    }
};

