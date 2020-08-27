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

class Solution {
public:
    // NOTE: while it's not important for most case, stack is more efficient than heap
    // And this looks more sexy. Just know that there can be stack overflows on some cases
    void inorderTraversal_rec(vector<int>& out, TreeNode* node) {
        if (!node)
            return;
        inorderTraversal_rec(out, node->left);
        out.push_back(node->val);
        inorderTraversal_rec(out, node->right);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        inorderTraversal_rec(ret, root);
        return ret;
    }
}
