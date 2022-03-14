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
    int getDecimalValue(ListNode* head) {
        string num="";
        while(head!=NULL){
            num+=to_string(head->val);
            head=head->next;
        }
        
        int res=0,power=1;
        for(int i=num.size()-1;i>=0;i--){
            res+=power*(stoi(num.substr(i,1)));
            power*=2;
        }
        return res;
    }
};