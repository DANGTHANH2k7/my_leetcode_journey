/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode node;        

struct TreeNode* invertTree(struct TreeNode* root) 
{
    if(!root) return root;

    if(root->left || root-> right)
    {
        node *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
    }

    if(root->left&& 
    (root->left->left || root->left->right)) invertTree(root->left);
    if(root->right && 
    (root->right->left || root->right->right)) invertTree(root->right);

    return root;
} 