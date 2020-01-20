class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int new_len = nums.size();
        for (int i = 0, j = nums.size() - 1; i <= j; ++i) {
            if (nums[i] == val) {
                while (j > i && nums[j] == val) {
                    --new_len;
                    --j;
                }
                nums[i] = nums[j--];
                --new_len;
            }
        }
        nums.resize(new_len);
        return new_len;
    }
};

