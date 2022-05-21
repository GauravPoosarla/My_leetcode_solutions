/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_set<ListNode*> sz;
        ListNode* temp = headA;
        while(temp)
        {
            sz.insert(temp);
            temp = temp->next;
        }
        
        temp = headB;
        while(temp)
        {
            if(sz.find(temp) != sz.end())
                return temp;
            temp = temp->next;
        }
        return NULL;
    }
};