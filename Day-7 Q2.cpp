/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
private:
    void insertAtTail( Node* &head, Node* &tail, int value ){
        Node* newNode = new Node(value);
        if( head == NULL ){
            head = newNode;
            tail = newNode;
            return;
        }
        else{
            tail->next = newNode;
            tail = newNode;
        }
    }
public:
    Node* copyRandomList(Node* head) {
        // first we create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;

        Node* temp = head;
        while( temp != NULL ){
            insertAtTail( cloneHead, cloneTail, temp->val );
            temp = temp->next;
        }

        // creeating a map for the clone
        unordered_map<Node*,Node*>oldToNew;

        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        while( originalNode != NULL && cloneNode != NULL ){
            oldToNew[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }

        // setting the random pointer
        originalNode = head;
        cloneNode = cloneHead;

        while( originalNode != NULL ){
            cloneNode->random = oldToNew[ originalNode->random ];
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        } 
        return cloneHead;
    }
};
