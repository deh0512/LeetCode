class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) {
            return {};
        }
        auto output = vector<vector<int>>{};
        auto current = vector<int>{};
        permute(output, current, nums);
        return output;
    }
    
private:
    void permute(vector<vector<int>>& output, vector<int>& current, vector<int>& unused) {
        if (unused.empty()) {
            output.push_back(current);
        }
        else {
            for (auto i = 0; i < unused.size(); ++i) {
                auto x = unused[i];
                current.push_back(x);
                unused.erase(unused.begin() + i);
                permute(output, current, unused);
                unused.insert(unused.begin() + i, x);
                current.pop_back();
            }
        }
    }
};

