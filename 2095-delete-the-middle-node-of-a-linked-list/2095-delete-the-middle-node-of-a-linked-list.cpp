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
    int findLen(ListNode* head)
    {
        int len = 0;
        while(head)
        {
            len++;
            head = head->next;
        }
        return len;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return NULL;
        
        int len = findLen(head);
        int count = 0;
        
        ListNode* prev = NULL;
        ListNode* nex = head;
        while(count < len/2)
        {
            prev = nex;
            nex = nex->next;
            count++;
        }
        prev->next = nex->next;
        return head;
    }
};