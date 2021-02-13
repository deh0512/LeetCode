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
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return maxDepth(root, 1);
    }
    
private:
    int maxDepth(TreeNode* node, int depth) {
        return std::max(
            node->left ? maxDepth(node->left, depth + 1) : 0,
            std::max(
                node->right ? maxDepth(node->right, depth + 1) : 0,
                depth));
    }
};

