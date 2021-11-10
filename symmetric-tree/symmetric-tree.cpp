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
    bool isSymmetric(TreeNode* left, TreeNode* right)
    {
        if(left == NULL and right == NULL)
        {
            return true;
        }
        else if(left == NULL or right == NULL)
        {
            return false;
        }
        else if(left->val != right->val)
        {
            return false;
        }
        
        return isSymmetric(left->left, right->right) and isSymmetric(right->left, left->right);
        
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
        {
            return true;
        }
        
        return isSymmetric(root->left, root->right);
    }
};