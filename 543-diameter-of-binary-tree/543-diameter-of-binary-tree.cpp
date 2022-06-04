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
    int diameterOfBinaryTree(TreeNode* root, int& maxi)
    {
        if(root == NULL)
            return 0;
        
        int lh = diameterOfBinaryTree(root->left, maxi);
        int rh = diameterOfBinaryTree(root->right, maxi);
        
        maxi = max(maxi, lh+rh);
        return 1+ max(lh, rh);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int max = INT_MIN;
        diameterOfBinaryTree(root, max);
        return max;
    }
};