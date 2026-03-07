#define _CRT_SECURE_NO_WARNINGS_1

#include <stdio.h>
#include <stdlib.h>

// 定义二叉树结构体
typedef int DataType;
typedef struct TreeNode {
    DataType val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

//创建新节点
TreeNode* createNode(int value);

// 插入节点（递归）
TreeNode* insert(TreeNode* root, int value);

// 查找节点
TreeNode* search(TreeNode* root, int value);

// 前序遍历
void preorder(TreeNode* root);

// 中序遍历
void inorder(TreeNode* root);

// 后序遍历
void postorder(TreeNode* root);

// 删除节点
TreeNode* delete(TreeNode* root, int value);

// 销毁整棵树
void destroyTree(TreeNode* root);
