/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*

This is a terribly worded question
It also (presumably) leaks.

*/
class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node->next;
    }
};