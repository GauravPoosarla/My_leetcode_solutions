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
        unordered_map<Node*, Node*> mp;
        Node* temp = head;
        while(temp)
        {
            Node* deepCopy = new Node(temp->val);
            mp[temp] = deepCopy;
            temp = temp->next;
        }
        
        Node* newNodeHead = mp[head];
        Node* temp2 = newNodeHead;
        // cout << newNodeHead << " " << head << endl;
        temp = head;
        
        while(temp2)
        {
            temp2->next = mp[temp->next];
            temp2->random = mp[temp->random];
            temp2 = temp2->next;
            temp = temp->next;
        }
        return newNodeHead;
    }
};