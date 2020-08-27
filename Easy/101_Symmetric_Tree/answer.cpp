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

helper function, check if they mirror each other

*/


class Solution {
public:
    bool helper(TreeNode* left, TreeNode* right) {
        if (!left && !right) {
            return true;
        }
        if ((!left || !right) || left->val != right->val) {
            return false;
        }
        
        return helper(left->left, right->right) && helper(left->right, right->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        return helper(root, root);
    }
};

//iterative
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        
        right.push(root);
        left.push(root);
        while(!right.empty() && !left.empty()) {
            TreeNode* cpR = right.front();
            right.pop();
            TreeNode* cpL = left.front();
            left.pop();
            
            if (!cpR && !cpL) {
                continue ;
            }
            if ((!cpR || !cpL) || (cpR->val != cpL->val)) {
                return false;
            }
            right.push(cpR->right);
            left.push(cpL->left);
            right.push(cpR->left);
            left.push(cpL->right);
        }
        
        return true;
    }
};