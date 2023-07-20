/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val; // we copied val of next node and gets atteached to node after next,
        // so the given node on paper gets deleted, and the the node next to given is still attached to
        // next->next
        node->next = node->next->next;
    }
};
