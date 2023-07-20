/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // creating a dummy node
        ListNode* start = new ListNode(-1);
        start->next = head;
        ListNode* fast = start;
        ListNode* slow = start;

        // traversing fast to make a winndow of n size, so when fast->next is Null, slow->next pointing
        // towards delete element
        for( int i=1; i<=n; i++ ){
            fast = fast->next;
        }

        while( fast->next != NULL ){
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return start->next;
    }
};
