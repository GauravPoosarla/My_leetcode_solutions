/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
private:
    void travNodes(Node* head, vector<Node*>& ans)
    {
        ans.push_back(head);
        if(head->child)
        {
            travNodes(head->child, ans);
        }
        if(head->next == NULL)
        {
            return;
        }
        travNodes(head->next, ans);
    }
public:
    Node* flatten(Node* head) {
        if(head == NULL)
        {
            return head;
        }
        vector<Node*> ans;
        ans.push_back(NULL);
        travNodes(head, ans);
        
        for(int i=1; i<ans.size()-1; i++)
        {
            ans[i]->prev = ans[i-1];
            ans[i]->next = ans[i+1];
            ans[i]->child = NULL;
        }
        ans[ans.size()-1]->prev = ans[ans.size()-2];  
        ans[ans.size()-1]->next = NULL;
        ans[ans.size()-1]->child = NULL;
        return ans[1];
    }
};