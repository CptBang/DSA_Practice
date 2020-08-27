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

need a stack and vector to do it in place
inorder traversal - traversal of left subtrees, then right subtrees
    Input: [1,null,2,3]
       1
        \
         2
        /
       3

    Output: [1,3,2]

*/

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> inorder;
        vector<int> ret;
        
        while (root || !inorder.empty()) {
            while (root) {
                inorder.push(root);
                root = root->left;
            }
            
            ret.push_back(inorder.top()->val);
            root = inorder.top();
            inorder.pop();
            root = root->right;
        }
        
        return ret;
    }
};