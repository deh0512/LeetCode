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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return dfs(p, q);
    }

private:
    bool dfs(TreeNode* p, TreeNode* q) {
        if (!p) return !q;
        if (!q || p->val != q->val) return false;
        if (!dfs(p->left, q->left)) return false;
        return dfs(p->right, q->right);
    }
};

