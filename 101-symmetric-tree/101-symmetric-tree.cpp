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
    bool isSymmetric(TreeNode* p, TreeNode* q)
    {
        if(p == NULL or q == NULL)
            return p == q;
        return ((p->val == q->val) and (isSymmetric(p->left, q->right)) and (isSymmetric(p->right, q->left)));
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL)
            return true;
        bool ans = isSymmetric(root->left, root->right);
        return ans;
    }
};