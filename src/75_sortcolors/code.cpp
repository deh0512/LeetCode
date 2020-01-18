class Solution {
public:
    void sortColors(vector<int>& nums) {
        auto sm1 = nums.size() - 1;
        auto zeros = 0;
        auto twos = sm1;
        while (zeros < sm1 && nums[zeros] == 0) ++zeros;
        while (twos > 0 && nums[twos] == 2) --twos;
        for (auto i = zeros; i <= twos;) {
            if (nums[i] == 0 && i != zeros) {
                nums[i] = nums[zeros];
                nums[zeros++] = 0;
            }
            else if (nums[i] == 2 && i != twos) {
                nums[i] = nums[twos];
                nums[twos--] = 2;
            }
            else ++i;
        }
    }
};

