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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // keeps the depth information
            vector<int> cur_res;
            for (int i = 0; i < size; i++) {
                TreeNode *current_node = q.front();
                q.pop();
                cur_res.push_back(current_node->val);
                if (current_node->left != NULL) {
                    q.push(current_node->left);
                }
                if (current_node->right != NULL) {
                    q.push(current_node->right);
                }
            }
            res.push_back(cur_res);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
