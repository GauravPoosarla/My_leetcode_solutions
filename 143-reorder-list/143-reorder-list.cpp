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
    void reorderList(ListNode* head) {
        vector<ListNode*> arr;
        
        for(ListNode* iter = head; iter; iter = iter->next)
        {
            arr.push_back(iter);
        }
        
        int left = 1; 
        int right = size(arr) - 1;
        
        for(int i=0; i<size(arr); i++)
        {
            if(i%2 == 0)
            {
                head->next = arr[right--];
            }
            else
            {
                head->next = arr[left++];
            }
            head = head->next;
        }
        head->next = NULL;
    }
};