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
        queue<TreeNode*> parent;
        vector<vector<int>> ret;
        
        parent.push(root);
        while (!parent.empty()) {
            queue<TreeNode*> child;
            vector<int> level;
            while(!parent.empty()) {
                TreeNode* node = parent.front();
                parent.pop();
                level.push_back(node->val);
                if (node->left) {
                    child.push(node->left);    
                }
                if (node->right) {
                    child.push(node->right);    
                }
            }
            ret.push_back(level);
            parent = child;
        }
        
        return ret;
    }
};


















