class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        auto output = vector<vector<int32_t>>{};
        output.push_back(vector<int32_t>{});
        auto searched = unordered_set<int32_t>{};
        auto subset = vector<int32_t>{};
        subset.reserve(nums.size());
        for (auto i = 0u; i < nums.size(); ++i)
        {
            if (searched.find(nums[i]) == searched.end())
            {
                searchNextSubset(nums, i, output, subset);
                searched.insert(nums[i]);
            }
        }
        return output;
    }
    
private:
    void searchNextSubset(
        const vector<int32_t>& nums,
        const uint32_t curIndex,
        vector<vector<int32_t>>& subsets,
        vector<int32_t>& subset)
    {
        subset.push_back(nums[curIndex]);
        if (find(subsets.begin(), subsets.end(), subset) == subsets.end())
        {
            subsets.push_back(subset);
			auto searched = unordered_set<int32_t>{};
			for (auto i = curIndex + 1u; i < nums.size(); ++i)
			{
				if (searched.find(nums[i]) == searched.end())
				{
					searchNextSubset(nums, i, subsets, subset);
					searched.insert(nums[i]);
				}
			}
        }
        subset.pop_back();
    }
};

