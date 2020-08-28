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

/*

for each level, make a vector
2 queues: one for previous level, one for current level
while the queue isnt empty we can keep adding to the vector

*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> ret;
        queue<TreeNode*> parent;
        queue<TreeNode*> child;
        parent.push(root);

        // NOTE: this way, you reuse your heap allocation
        // no new vectors/queues are created on every level
        // mind that the swap(c) function is O(1).
        vector<int> level;
        while (!parent.empty()) {
            TreeNode* node = parent.front();
            parent.pop();

            level.push_back(node->val);
            if (node->left) {
                child.push(node->left);    
            }
            if (node->right) {
                child.push(node->right);    
            }

            if (parent.empty()) {
                ret.push_back(level);
                level.clear();
                parent.swap(child);
            }
        }
        
        return ret;
    }
};
