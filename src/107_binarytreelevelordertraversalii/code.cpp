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
    vector<vector<int>> levelOrderBottom(const TreeNode* root) {
        if (!root) {
            return {};
        }
        auto levels = vector<vector<int>>{};
        traverse(levels, root, 0);
        std::reverse(levels.begin(), levels.end());
        return levels;
    }
    
private:
    void traverse(vector<vector<int>>& levels, const TreeNode* node, int level) {
        if (levels.size() < level + 1) {
            levels.push_back({});
        }
        levels[level].push_back(node->val);
        if (node->left) {
            traverse(levels, node->left, level + 1);
        }
        if (node->right) {
            traverse(levels, node->right, level + 1);
        }
    }
};

