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

//leetcode 572. 另一个树的子树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
//    if (p == NULL && q == NULL)
//        return true;
//
//    if (p == NULL || q == NULL)
//        return false;
//
//    if (p->val != q->val)
//        return false;
//
//    return isSameTree(p->left, q->left)
//        && isSameTree(p->right, q->right);
//}
//
// ///
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
//    if (root == NULL)
//        return false;
//    if (root->val == subRoot->val
//        && isSameTree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot)
//        || isSubtree(root->right, subRoot);
//
//]
//189
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
//
// 
// 
// di
//void rotate(int* nums, int numsSize, int k) {
//    k %= numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//}
//
// 复写零leetcode 1089
//class Solution {
//public:
//    void duplicateZeros(vector<int>& arr) {
//        int dest = -1, cur = 0, n = arr.size();
//        while (cur < n)
//        {
//            if (arr[cur]) dest++;
//            else dest += 2;
//            if (dest >= n - 1) break;
//            cur++;
//        }
//
//
//        if (dest == n)
//        {
//            arr[n - 1] = 0;
//            cur--; dest -= 2;
//        }
//
//
//        while (cur >= 0)
//        {
//            if (arr[cur]) arr[dest--] = arr[cur--];
//            else
//            {
//                arr[dest--] = 0;
//                arr[dest--] = 0;
//                cur--;
//            }
//        }
//    }
//};
//快乐数计算 leetcode 202
//class Solution {
//public:
//
//    int Sum(int n)
//    {
//        int sum = 0;
//        while (n)
//        {
//            int t = n % 10;
//            sum += t * t;
//            n = n / 10;
//        }
//        return sum;
//    }
//
//    bool isHappy(int n)
//    {
//        int slow = n;
//        int fast = Sum(n);
//        while (slow != fast)
//        {
//            slow = Sum(slow);
//            fast = Sum(Sum(fast));
//        }
//        return slow == 1;
//
//    }
//};

//盛最多的水的容器 leetcode 11
//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int left = 0, right = height.size() - 1, ret = 0;
//
//        while (left < right)
//        {
//            int v = min(height[left], height[right]) * (right - left);
//            ret = max(ret, v);
//            if (height[left] > height[right]) right--;
//            else left++;
//
//        }
//        return ret;
//    }
//};

//611 有效三角形的个数
//class Solution {
//public:
//    int triangleNumber(vector<int>& nums) {
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        int ret = 0;
//        for (int i = n - 1;i >= 2; i--)
//        {
//            int left = 0;
//            int right = i - 1;
//            while (left < right)
//            {
//                if (nums[left] + nums[right] > nums[i])
//                {
//                    ret += right - left;
//                    right--;
//                }
//                else
//                {
//                    left++;
//                }
//            }
//        }
//        return ret;
//    }
//};