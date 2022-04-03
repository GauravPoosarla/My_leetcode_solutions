class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        if(m == n)
            return head;
        
        if(m > 1)
        {
            head->next = reverseBetween(head->next, m - 1, n - 1);
            return head;
        }
        else
        {
            ListNode* tailNode = reverseBetween(head->next, 1, n - 1);
            ListNode* tailNodeNext = head->next->next;
            
            head->next->next = head;
            head->next = tailNodeNext;

            return tailNode;
        }
    }
};