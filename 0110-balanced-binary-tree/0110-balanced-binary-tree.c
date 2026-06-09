/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;
int h(node* root)
{
    if(root==NULL) return 0;
    if(!root->left && !root->right) 
    {
        root->val = 1;
        return root->val;
    }
    root->val = fmax(h(root->left), h(root->right)) + 1;
    return root->val;
}
bool solve(node* root)
{
    if(root==NULL) return true;

    int hleft = 0; if(root->left)  hleft = root->left->val;
    int hright = 0; if(root->right)  hright = root->right->val;

    if(abs(hleft-hright) >= 2) return false;
    else
    {
        return(solve(root->left) && solve(root->right));
    }
}
bool isBalanced(struct TreeNode* root) 
{
    int hRoot = h(root);
    return solve(root);
}