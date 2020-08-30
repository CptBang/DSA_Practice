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

find center

[-10, -3, 0, 5, 9]
      0
     / \
   -3   9
   /   /
 -10  5

*/

class Solution {
public:
    TreeNode* recursive(vector<int>& nums, int left, int right) {
        if (right <= left) {
            return NULL;
        }
        
        int mid = (right + left) / 2;
        TreeNode* ret = new TreeNode(nums[mid]);
        
        ret->left = recursive(nums, left, mid);
        ret->right = recursive(nums, mid+1, right);
        
        return ret;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return recursive(nums, 0, nums.size());
    }
};













