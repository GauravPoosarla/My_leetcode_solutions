/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* temp=NULL;
    int sum=0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        sumOfLeftLeaves(root -> left);
        if(temp != NULL) {
            if(root -> left == temp && temp -> left == NULL && temp -> right == NULL) {
sum +=temp -> val;
                
            }
            temp = root;
        }else {
            temp = root;
            }
        sumOfLeftLeaves(root -> right);
        return sum;
    }
};