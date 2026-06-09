/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void inorder(struct TreeNode* root, int* sol, int* returnSize){
    if(root == NULL){
        return;
    }
    inorder(root -> left, sol, returnSize);
    sol[(*returnSize)++] = root -> val;
    inorder(root -> right, sol, returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* sol = (int*)malloc(sizeof(int) * 101);
    inorder(root, sol, returnSize);
    return sol;
}