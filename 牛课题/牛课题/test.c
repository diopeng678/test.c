#define _CRT_SECURE_NO_WARNINGS_1

#include <stdio.h>
#include<stdlib.h>

typedef struct BintreeNode
{
    struct BintreeNode* left;
    struct BintreeNode* right;
    char val;
}BTNode;

BTNode* CreateTree(char* a, int* pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->val = a[(*pi)++];
    root->left = CreateTree(a, pi);
    root->right = CreateTree(a, pi);
    return root;
}

void InOrder(BTNode* root)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root->left);
    printf("%c ", root->val);
    InOrder(root->right);
}


int main() {

    char a[100];
    scanf("%s", a);
    int i = 0;
    BTNode* root = CreateTree(a, &i);
    InOrder(root);
    return 0;
}