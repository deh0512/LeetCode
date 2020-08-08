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
    bool isValidBST(TreeNode* root) {
        return isValidBST(root, nullopt, nullopt);
    }

private:
    bool isValidBST(TreeNode* root, optional<int> min, optional<int> max) {
        if (root == nullptr) {
            return true;
        }
        if (root->left != nullptr) {
            if (root->left->val >= root->val ||
                min.has_value() && root->left->val <= min.value() ||
                max.has_value() && root->left->val >= max.value()) {
                return false;
            }
        }
        if (root->right != nullptr) {
            if (root->right->val <= root->val ||
                min.has_value() && root->right->val <= min.value() ||
                max.has_value() && root->right->val >= max.value()) {
                return false;
            }
        }
        return isValidBST(root->left, min, root->val) &&
               isValidBST(root->right, root->val, max);
    }
};

