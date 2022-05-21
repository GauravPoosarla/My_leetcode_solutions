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
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> sz;
        while(head)
        {
            if(sz.find(head) != sz.end())
                return true;
            sz.insert(head);
            head = head->next;
        }
        return false;
    }
};