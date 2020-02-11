class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        for (auto i = index; i < candidates.size(); ++i) {
            current.push_back(candidates[i]);
            search(candidates, target - candidates[i], current, i, solution);
            current.resize(current.size() - 1);
        }
    }
};

