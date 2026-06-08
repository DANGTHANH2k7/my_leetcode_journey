/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;

int res = 0;

int maxLength(node *root)
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;

    int maxL = maxLength(root->left);
    int maxR = maxLength(root->right);
    
    res = fmax(res, maxL+maxR);

    return fmax(maxL, maxR) + 1;
}

int diameterOfBinaryTree(struct TreeNode* root) 
{
    res = 0;
    maxLength(root);
    return res;
}