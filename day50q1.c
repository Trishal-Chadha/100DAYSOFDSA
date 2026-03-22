#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    // Base case
    if (root == NULL || root->val == key)
        return root;

    // Search in left or right subtree
    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}#include <stdio.h>
#include <stdlib.h>

// Definition of Tree Node
struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Search in BST
struct TreeNode* searchBST(struct TreeNode* root, int key) {
    // Base case
    if (root == NULL || root->val == key)
        return root;

    // Search in left or right subtree
    if (key < root->val)
        return searchBST(root->left, key);
    else
        return searchBST(root->right, key);
}