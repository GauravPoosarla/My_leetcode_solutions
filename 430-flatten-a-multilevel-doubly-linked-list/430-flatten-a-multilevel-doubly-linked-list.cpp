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
// private:
//     void travNodes(Node* head, vector<Node*>& ans)
//     {
//         ans.push_back(head);
//         if(head->child)
//         {
//             travNodes(head->child, ans);
//         }
//         if(head->next == NULL)
//         {
//             return;
//         }
//         travNodes(head->next, ans);
//     }
// public:
//     Node* flatten(Node* head) {
//         if(head == NULL)
//         {
//             return head;
//         }
//         vector<Node*> ans;
//         ans.push_back(NULL);
//         travNodes(head, ans);
        
//         for(int i=1; i<ans.size(); i++)
//         {
//             ans[i]->prev = ans[i-1];
//             ans[i]->next = ans[i+1];
//             ans[i]->child = NULL;
//         }
//         ans[ans.size()-1]->prev = ans[ans.size()-2];  
//         ans[ans.size()-1]->next = NULL;
//         ans[ans.size()-1]->child = NULL;
//         return ans[1];
//     }

public:
    void TravNodes(Node* head, vector<Node*>& ans){
        ans.push_back(head);   // Insert the current node
		 // if node has a child recursive call to the child
        if(head->child) TravNodes(head->child,ans);  
        if(!head->next) return;  // if next node is NULL return
        TravNodes(head->next,ans);  // Traverse the next node
    }
    
    Node* flatten(Node* head) {
        if(!head) return head;  // If there is node head return
        vector<Node*>ans;  // ans array to store nodes in order
        ans.push_back(NULL); // Let the first element be NULL as head->prev = NULL;
        TravNodes(head,ans);  // Helper function call
		// Iterate from the second element till second last element (1st ele is NULL)
        for(int i = 1;i<ans.size()-1;i++){ 
            ans[i]->prev = ans[i-1];   // set prev ele
            ans[i]->next = ans[i+1];  // set next ele
            ans[i]->child = nullptr;  // remove child ptr
        }
		// Set next and prev for last element
        ans[ans.size()-1]->prev = ans[ans.size()-2];  
        ans[ans.size()-1]->next = NULL;
        ans[ans.size()-1]->child = NULL;
        return ans[1];  // Return the head stored in ans[1]
    }
};