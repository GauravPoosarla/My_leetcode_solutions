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
    void inorder(TreeNode* root, vector<int>& inr)
    {
        if(root == NULL)
            return;
        inorder(root->left, inr);
        inr.push_back(root->val);
        inorder(root->right, inr);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> inr;
        inorder(root, inr);
        return inr[k-1];
    }
};