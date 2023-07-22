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
    ListNode* rotateRight(ListNode* head, int k) {
        if( head == NULL || head->next == NULL || k==0 ){
            return head;
        }
        // we first find the length of the LL
        ListNode* temp = head;
        int len = 1;
        while( temp->next != NULL ){
            len++;
            temp = temp->next;
        }

        // now we make the LL circcular
        temp->next = head;
        // now we find the k if it is bigger than the length or not
        k = k%len; // as if k is larger than, for many iterations after len, the LL will be same as original
        int end = len - k;

        // now we find the node from where we have to make the cut
        while( end != 0 ){
            temp = temp->next;
            end--;
        }
        // now we have got the end node as temp
        head = temp->next;
        temp->next = NULL;

        return head;
    }
};
