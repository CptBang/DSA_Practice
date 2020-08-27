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

keep the node value of each subtree and head of the tree
check that left is smaller and right is greater

helper(root, currVal, val)
if ()

*/

// naive solution
class Solution {
public:
    bool helper(TreeNode* root, long min, long max) {
        if (!root) {
            return true;
        }
        
        if (root->val <= min || root->val >= max) {
            return false;
        }
        
        return helper(root->left, min, root->val) && helper(root->right, root->val, max);
    }
    
    bool isValidBST(TreeNode* root) {       
        return helper(root, LONG_MIN, LONG_MAX);
    }
};

// get to bottom left, use stack
class Solution {
public:
    bool isValidBST(TreeNode* root) {       
        stack<TreeNode*> inOrder;
        long check = LONG_MIN;
        
        while (root || !inOrder.empty()) {
            while (root) {
                inOrder.push(root);
                root = root->left;
            }
            
            root = inOrder.top();
            inOrder.pop();
            if (root->val <= check) {
                return false;
            }
            check = root->val;
            root = root->right;
        }
        
        return true;
    }
};