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
    bool isSymmetric(TreeNode* root) {
        if (root) return isSame(root->left, root->right);
        return true;
    }
    
    bool isSame(TreeNode *a, TreeNode *b) {
        if (a == NULL && b == NULL) return true;
        if (a != NULL && b != NULL) return (a->val == b->val && isSame(a->left, b->right) && isSame(a->right, b->left));
        return false;
    }
};
