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
        
        ListNode* temp = reverse(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp;
        
    }
public:
    bool isPalindrome(ListNode* head) {
        int length = 0;
        
        ListNode* temp = head;
        
        while(temp != NULL)
        {
            temp = temp->next;
            length++;
        }
        
        // cout << length;
        
        int mid = length/2;
        // cout << mid << endl;
        
        temp = head;
        while(mid > 0)
        {
            temp = temp->next;
            mid--;
        }
        // cout << temp->val << endl;
        
        ListNode* reverseHead = reverse(temp);
        temp = head;
        
        while(reverseHead != NULL)
        {
            if(reverseHead->val != temp->val)
            {
                return false;
            }
            reverseHead = reverseHead->next;
            temp = temp->next;
        }
        return true;
    }
};