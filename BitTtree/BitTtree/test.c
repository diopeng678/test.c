#define _CRT_SECURE_NO_WARNINGS_1
#include"bitree.h"


// 主函数
int main() {
    TreeNode* root = NULL;

    // 插入节点
    int data[] = { 5, 3, 7, 2, 4, 6, 6, };
    int n = sizeof(data) / sizeof(data[0]);
    for (int i = 0; i < n; i++)
        root = insert(root, data[i]);

    // 遍历
    printf("中序遍历(有序)：");
    inorder(root);
    printf("\n");

    printf("前序遍历：");
    preorder(root);
    printf("\n");

    printf("后序遍历：");
    postorder(root);
    printf("\n");

    // 查找
    int key = 66;
    TreeNode* found = search(root, key);
    printf("查找%d：%s\n", key, (found ? "找到" : "未找到"));

    // 删除节点
    root = delete(root, 3);
    printf("删除3后中序遍历：");
    inorder(root);
    printf("\n");

    // 销毁树
    destroyTree(root);
    root = NULL;

    return 0;
}