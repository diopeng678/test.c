#define _CRT_SECURE_NO_WARNINGS_1
#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

// 创建新节点
TreeNode* createNode(int value) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 插入节点（递归）
TreeNode* insert(TreeNode* root, int value) {
    if (root == NULL) 
        return createNode(value);
    if (value < root->val)
        root->left = insert(root->left, value);
    else if (value > root->val)
        root->right = insert(root->right, value);
    // 如果等于则什么也不做（不允许重复） 也就是直接返回了
    return root;
}

// 查找节点
TreeNode* search(TreeNode* root, int value) {
    if (root == NULL || root->val == value) 
        return root;
    if (value < root->val)
        return search(root->left, value);
    else
        return search(root->right, value);
}

// 前序遍历
void preorder(TreeNode* root) {
    if (root == NULL) return;
    printf("%d ", root->val);
    preorder(root->left);
    preorder(root->right);
}

// 中序遍历
void inorder(TreeNode* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

// 后序遍历
void postorder(TreeNode* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

// 删除节点
TreeNode* delete(TreeNode* root, int value) {
    if (root == NULL) 
        return root;
    if (value < root->val)
        root->left = delete(root->left, value);
    else if (value > root->val)
        root->right = delete(root->right, value);
    else { // 找到要删除的节点
        if (root->left == NULL) {
            TreeNode* tmp = root->right;
            free(root);
            return tmp;
        }
        else if (root->right == NULL) {
            TreeNode* tmp = root->left;
            free(root);
            return tmp;
        }
        else {
            // 找右子树最小节点
            TreeNode* tmp = root->right;
            while (tmp->left != NULL)
                tmp = tmp->left;
            root->val = tmp->val;
            root->right = delete(root->right, tmp->val);
        }
    }
    return root;
}

// 销毁整棵树
void destroyTree(TreeNode* root) {
    if (root == NULL) 
        return;
    destroyTree(root->left);
    destroyTree(root->right);
    free(root);
}

