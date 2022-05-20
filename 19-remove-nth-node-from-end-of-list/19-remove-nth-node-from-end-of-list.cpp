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
        if(head == NULL)
            return head;
        
        int length = 0;
        ListNode* temp = head;
        
        while(temp)
        {
            length++;
            temp = temp->next;
        }
        
        if(n > length)
            return NULL;
        if(n == length)
            return head->next;
        
        int indexToBeRemoved = length-n-1;
        temp = head;
        while(indexToBeRemoved--)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        return head;
    }
};