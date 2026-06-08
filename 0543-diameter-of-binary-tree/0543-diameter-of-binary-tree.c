/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;

int maxDepth(struct TreeNode* root) 
{
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return 1 + fmax(maxDepth(root->left), maxDepth(root->right));
}

int dia;

int diameterOfBinaryTree(struct TreeNode* root) 
{
    dia = 0;
    node *cur = root;
    while(cur)
    {
        int maxL = maxDepth(cur->left);
        int maxR = maxDepth(cur->right);
        dia = fmax(dia, maxL + maxR);
        
        if(maxL > maxR) cur = cur->left;
        else cur = cur->right;
    }
    return dia;
}