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
    ListNode* middleOfTheLinkedList(ListNode* head)
    {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast->next and fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode* reverseOfTheLinkedList(ListNode* head)
    {
        if(head == NULL or head->next == NULL)
        {
            return head;
        }
        
        ListNode* temp = reverseOfTheLinkedList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode* mid = middleOfTheLinkedList(head);
        ListNode* reverse = reverseOfTheLinkedList(mid->next);
        
        while(reverse)
        {
            if(head->val != reverse->val)
                return false;
            
            head = head->next;
            reverse = reverse->next;
        }
        return true;
    }
};