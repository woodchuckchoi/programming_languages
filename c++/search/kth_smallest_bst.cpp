class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> q;
        smallest(root, q);
        for (int i = 1; i < k; i++) {
            q.pop();
        }
        return -1 * q.top();
    }
    void smallest(TreeNode* root, priority_queue<int> &q) {
        if (root != NULL) {
            q.push(-1*root->val);
        }
        if (root->left) {
            smallest(root->left, q);
        }
        if (root->right) {
            smallest(root->right, q);
        }
    }
};
