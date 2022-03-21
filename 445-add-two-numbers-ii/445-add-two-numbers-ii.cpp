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
private:
    ListNode* reverse(ListNode* head)
    {
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        ListNode* reverseHead = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return reverseHead;
        
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* reverseL1 = reverse(l1);
        ListNode* reverseL2 = reverse(l2);
        
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        int carry = 0;
        
        ListNode* ptr1 = reverseL1;
        ListNode* ptr2 = reverseL2;
        
        while(ptr1 and ptr2)
        {
            int sum = ptr1->val + ptr2->val + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            
            tail = tail->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        while(ptr1)
        {
            int sum = ptr1->val + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            
            tail = tail->next;
            ptr1 = ptr1->next;
        }
        
        while(ptr2)
        {
            int sum = ptr2->val + carry;
            carry = sum/10;
            tail->next = new ListNode(sum%10);
            
            tail = tail->next;
            ptr2 = ptr2->next;
        }
        
        if(carry)
        {
            tail->next = new ListNode(carry);
        }
        
        ListNode* finalHead = reverse(dummy->next);
        return finalHead;
    }
};