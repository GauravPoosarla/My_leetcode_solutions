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
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;
        Node* front = head;
        
        while(iter)
        {
            front = iter->next;
            Node* deepCopy = new Node(iter->val);
            iter->next = deepCopy;
            deepCopy->next = front;
            iter = front;
        }
        
        iter = head;
        while(iter)
        {
            if(iter->random)
                iter->next->random = iter->random->next;
            
            iter = iter->next->next;
        }
        
        iter = head;
        Node* prevNewListHead = new Node(0);
        Node* copy = prevNewListHead;
        
        while(iter)
        {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = iter->next;
        }
        return prevNewListHead->next;
    }
};