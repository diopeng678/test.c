#define _CRT_SECURE_NO_WARNINGS_1
//void reverse(int* a, int left, int right) {
//    while (left < right) {
//        int tmp = a[left];
//        a[left] = a[right];
//        a[right] = tmp;
//        left++;
//        right--;
//
//    }
//
//
//}
//
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//}
//


//leetcode 138. 复制带随机指针的链表
struct Node* copyRandomList(struct Node* head) {
    //拷贝节点差入到源节点的后面

    struct Node* cur = head;
    while (cur) {
        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
        copy->val = cur->val;

        copy->next = cur->next;
        cur->next = copy;

        cur = copy->next;

    }
    //控制random
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (cur->random == NULL) {
            copy->random = NULL;
        }
        else {
            copy->random = cur->random->next;

        }
        cur = copy->next;

    }
    //把拷贝下来的节点取下来尾插成新的链表,然后恢复原链表(不恢复也行)
    struct Node* copyhead = NULL, * copytail = NULL;
    cur = head;
    while (cur)
    {
        struct Node* copy = cur->next;
        struct Node* next = copy->next;

        if (copytail == NULL)
        {
            copyhead = copytail = copy;
        }
        else {
            copytail->next = copy;
            copytail = copytail->next;
        }
        cur = next;
    }
    return copyhead;
}
//144题 前序遍历
//int treesize(struct TreeNode* root)
//{
//    if (root == NULL)
//        return 0;
//    else
//        return treesize(root->left) + treesize(root->right) + 1;
//}
//
//void preorder(struct TreeNode* root, int* a, int* pi)
//{
//    if (root == NULL)
//        return;
//
//    a[(*pi)++] = root->val;
//
//    preorder(root->left, a, pi);
//    preorder(root->right, a, pi);
//}
//
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize) {
//    *returnSize = treesize(root);
//    int* a = (int*)malloc(sizeof(int) * (*returnSize));
//    int i = 0;
//    preorder(root, a, &i);
//
//    return a;
//}