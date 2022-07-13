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
    ListNode* mergeList(ListNode* l1, ListNode* l2)
    {
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        
        while(l1 and l2)
        {
            if(l1->val <= l2->val)
            {
                curr->next = l1;
                l1 = l1->next;
            }
            else
            {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1)
        {
            curr->next = l1;
            l1 = l1->next;
        }
        if(l2)
        {
            curr->next = l2;
            l2 = l2->next;
        }
        
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL or head->next == NULL)
            return head;
        
        ListNode* temp = head;
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast and fast->next)
        {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        
        ListNode* temp1 = sortList(head);
        ListNode* temp2 = sortList(slow);
        
        return mergeList(temp1, temp2);
    }
};