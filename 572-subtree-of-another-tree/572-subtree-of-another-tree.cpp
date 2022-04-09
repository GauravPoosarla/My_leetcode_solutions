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
    bool isSameTree(TreeNode* root, TreeNode* subRoot)
    {
        if(root == NULL and subRoot == NULL)
        {
            return true;
        }
        if(root == NULL or subRoot == NULL)
        {
            return false;
        }
        
        return root->val == subRoot->val and isSameTree(root->left, subRoot->left) and isSameTree(root->right, subRoot->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL and subRoot == NULL)
        {
            return true;
        }
        if(root == NULL or subRoot == NULL)
        {
            return false;
        }
        if(root->val == subRoot->val)
        {
            if(isSameTree(root, subRoot))
            {
                return true;
            }
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};