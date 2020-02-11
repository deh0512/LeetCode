class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solution{};
        vector<int> start{};
        search(candidates, target, start, 0, solution);
        return solution;
    }

private:
    void search(vector<int>& candidates, int target, vector<int>& current, int index, vector<vector<int>>& solution) {
        if (target < 0) return;
        if (target == 0) {
            solution.push_back(current);
            return;
        }
        for (auto i = index; i < candidates.size();) {
            current.push_back(candidates[i]);
            search(candidates, target - candidates[i], current, i + 1, solution);
            current.resize(current.size() - 1);
            auto j = i + 1;
            while (j < candidates.size() && candidates[j] == candidates[i]) ++j;
            i = j;
        }
    }
};

