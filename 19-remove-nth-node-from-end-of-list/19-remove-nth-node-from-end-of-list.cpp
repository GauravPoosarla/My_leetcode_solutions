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
        int length = 0;
        
        ListNode* temp = head;
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        
        if(n > length)
        {
            return NULL;
        }
        
        if(n == length)
        {
            return head->next;
        }
        
        temp = head;
        
        int i = 0;
        
        while(i<length-n-1)
        {
            temp = temp->next;
            i++;
        }
        
        temp->next = temp->next->next;
        return head;
    }
};