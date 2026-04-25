#include <stdio.h>
#include <stdlib.h>

#define LEN             200
struct TreeNode
{
    struct TreeNode *right;
    struct TreeNode *left;
    int val;
};

struct TreeNode* invertTree(struct TreeNode *root)
{
    if(root == NULL) return root;
    invertTree(root->left);
    invertTree(root->right);
    struct TreeNode *curr = root->left;
    root->left = root->right;
    root->right = curr;
    return root;
};