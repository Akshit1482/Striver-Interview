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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // getting the tail of first LL
        ListNode* tail = headA;
        while( tail->next != NULL ){
            tail = tail->next;
        }

        // creating a loop with the lat element of the LL
        tail->next = headA;

        // detecting and findng the intersection
        ListNode* fast = headB;
        ListNode* slow = headB;

        while( fast != NULL && fast->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;

            if( slow == fast ){
                slow = headB; // putting slow to initial point
                // iterating fromm initaial and intersecction pt, and where they meet, it is the
                //common node
                while( slow != fast ){
                    slow = slow->next;
                    fast = fast->next;
                }
                // after findin, undoing the loop
                tail->next = NULL;
                return slow;
            }
        }
        tail->next = NULL;
        return NULL;
    }
};
