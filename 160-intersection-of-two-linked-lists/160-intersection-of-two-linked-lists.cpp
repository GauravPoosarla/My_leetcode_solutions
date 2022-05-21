/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int getDifference(ListNode* head1, ListNode* head2)
    {
        int len1 = 0, len2 = 0;
        while(head1 || head2)
        {
            if(head1)
            {
                len1++;
                head1 = head1->next;
            }
            if(head2)
            {
                len2++;
                head2 = head2->next;
            }
        }
        return len1-len2;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int difference = getDifference(headA, headB);
        if(difference < 0)
            while(difference++ != 0) headB = headB->next;
        else
            while(difference-- != 0) headA = headA->next;
        
        while(headA and headB)
        {
            if(headA == headB)
                return headA;
            headA = headA -> next;
            headB = headB -> next;
        }
        return NULL;
    }
};