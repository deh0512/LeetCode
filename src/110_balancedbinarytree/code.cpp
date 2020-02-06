/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int max = 0;
        return search(root, 0, max);
    }
    
private:
    bool search(TreeNode* node, int level, int& maxLevel) {
        if (!node) return true;
        int maxLeft = level;
        int maxRight = level;
        if (node->left && !search(node->left, level + 1, maxLeft)) return false;
        if (node->right && !search(node->right, level + 1, maxRight)) return false;
        maxLevel = max(maxLeft, maxRight);
        return abs(maxRight - maxLeft) < 2;
    }
};

