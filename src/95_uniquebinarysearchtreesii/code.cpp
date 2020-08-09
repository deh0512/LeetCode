/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        dp.resize(n);
        for (auto& v : dp) {
            v.resize(n);
        }
        auto values = vector<int>{};
        values.resize(n);
        iota(values.begin(), values.end(), 1);
        return generateTrees(values);
    }
    
private:
    vector<TreeNode*> generateTrees(vector<int> values) {
        auto size = values.size();
        if (size == 0) {
            return {nullptr};
        }
        auto start = values[0];
        if (!dp[start - 1][size - 1].empty()) {
            return dp[start - 1][size - 1];
        }
        auto output = vector<TreeNode*>{};
        for (auto i = values.begin(); i != values.end(); ++i) {
            auto smaller = vector<int>{};
            smaller.insert(smaller.begin(), values.begin(), i);
            auto larger = vector<int>{};
            larger.insert(larger.begin(), i + 1, values.end());
            auto leftSubtrees = generateTrees(smaller);
            auto rightSubtrees = generateTrees(larger);
            for (auto& leftSubtree : leftSubtrees) {
                for (auto& rightSubtree : rightSubtrees) {
                    auto node = new TreeNode{*i, leftSubtree, rightSubtree};
                    output.push_back(node);
                }
            }
        }
        dp[start - 1][size - 1] = output;
        return output;
    }
    
    vector<vector<vector<TreeNode*>>> dp{};
};

