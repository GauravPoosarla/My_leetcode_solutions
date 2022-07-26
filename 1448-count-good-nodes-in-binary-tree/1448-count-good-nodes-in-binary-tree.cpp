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
private:
    int f(TreeNode* root, int maxi)
    {
        if(root == NULL)
            return 0;
        
        int goodNodes = 0;
        if(root->val >= maxi)
        {
            maxi = root->val;
            goodNodes++;
        }
        
        return goodNodes + f(root->left, maxi) + f(root->right, maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        return f(root, root->val);
    }
};