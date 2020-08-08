class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        auto output = vector<vector<int32_t>>{};
        auto subset = vector<int32_t>{};
        subset.reserve(nums.size());
        searchNextSubset(nums, 0u, output, subset);
        return output;
    }
    
private:
    void searchNextSubset(
        const vector<int32_t>& nums,
        const uint32_t curIndex,
        vector<vector<int32_t>>& subsets,
        vector<int32_t>& subset)
    {
        subsets.push_back(subset);
        for (auto i = curIndex; i < nums.size(); ++i)
        {
            if (i > curIndex && nums[i] == nums[i - 1u])
            {
                continue;
            }
            subset.push_back(nums[i]);
            searchNextSubset(nums, i + 1u, subsets, subset);
            subset.pop_back();
        }
    }
};

