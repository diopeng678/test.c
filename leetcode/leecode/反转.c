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
//struct Node* copyRandomList(struct Node* head) {
//    //拷贝节点差入到源节点的后面
//
//    struct Node* cur = head;
//    while (cur) {
//        struct Node* copy = (struct Node*)malloc(sizeof(struct Node));
//        copy->val = cur->val;
//
//        copy->next = cur->next;
//        cur->next = copy;
//
//        cur = copy->next;
//
//    }
//    //控制random
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        if (cur->random == NULL) {
//            copy->random = NULL;
//        }
//        else {
//            copy->random = cur->random->next;
//
//        }
//        cur = copy->next;
//
//    }
//    //把拷贝下来的节点取下来尾插成新的链表,然后恢复原链表(不恢复也行)
//    struct Node* copyhead = NULL, * copytail = NULL;
//    cur = head;
//    while (cur)
//    {
//        struct Node* copy = cur->next;
//        struct Node* next = copy->next;
//
//        if (copytail == NULL)
//        {
//            copyhead = copytail = copy;
//        }
//        else {
//            copytail->next = copy;
//            copytail = copytail->next;
//        }
//        cur = next;
//    }
//    return copyhead;
//}
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
//179 两数之和等于固定值
//class Solution {
//public:
//    vector<int> twoSum(vector<int>& price, int target) {
//        int left = 0;
//        int right = price.size() - 1;
//        while (left < right)
//        {
//            int sum = price[left] + price[right];
//            if (sum < target) left++;
//            else if (sum > target) right--;
//            else return { price[left],price[right] };
//        }
//        return { -1,-1 };
//    }
//};

//双指针解决 15 三数之和
//class Solution {
//public:
//    vector<vector<int>> threeSum(vector<int>& nums) {
//        vector<vector<int>> ret;
//        sort(nums.begin(), nums.end());
//        int n = nums.size();
//        for (int i = 0;i < nums.size();)
//        {
//            if (nums[i] > 0) break;
//            int left = i + 1, right = n - 1, target = -nums[i];
//            while (left < right)
//            {
//                if (nums[left] + nums[right] < target) left++;
//                else if (nums[left] + nums[right] > target) right--;
//                else
//                {
//                    ret.push_back({ nums[i], nums[left], nums[right] });
//                    left++, right--;
//                    // 去重操作 left 和right 
//                    while (left < right && nums[left] == nums[left - 1]) left++;
//                    while (left < right && nums[right] == nums[right + 1]) right--;
//                }
//            }
//            i++;
//            while (i < nums.size() && nums[i] == nums[i - 1]) i++;
//        }
//        return ret;
//    }
//
//};
//209 窗口滑动 
//class Solution {
//public:
//    int minSubArrayLen(int target, vector<int>& nums) {
//        int n = nums.size(), sum = 0, len = INT_MAX;
//        for (int left = 0, right = 0; right < n; right++)
//        {
//            sum += nums[right];
//            while (sum >= target)
//            {
//                len = min(len, right - left + 1);
//                sum -= nums[left++];
//            }
//        }
//        return len == INT_MAX ? 0 : len;
//    }
//};
//滑动窗口解决 3 无重复字符的最长子串
//class Solution {
//public:
//    int lengthOfLongestSubstring(string s) {
//        int hash[128] = { 0 };
//        int left = 0;
//        int right = 0;
//        int ret = 0;
//        int n = s.size();
//        while (right < n)
//        {
//            hash[s[right]]++;
//            while (hash[s[right]] > 1)
//            {
//                hash[s[left++]]--;
//            }
//            ret = max(ret, right - left + 1);
//            right++;
//        }
//        return ret;
//    }
//};
//1004 滑动窗口解决 最大连续1的个数 III
//class Solution {
//public:
//    int longestOnes(vector<int>& nums, int k) {
//        int left = 0;
//        int right = 0;
//        int zero = 0, n = nums.size();
//        int ret = 0;
//        while (right < n)
//        {
//            if (nums[right] == 0)
//            {
//                zero++;
//            }
//            while (zero > k)
//            {
//                if (nums[left++] == 0)   zero--;
//            }
//            right++;
//            ret = max(ret, right - left);
//        }
//        return ret;
//    }
//}
//进窗口 判断 出窗口 更新结果

// 155 最小栈 
//class MinStack {
//public:
//    MinStack() {
//
//    }
//
//    void push(int val) {
//        _st.push(val);
//        if (_minst.empty() || _minst.top() >= val)
//        {
//            _minst.push(val);
//        }
//    }
//
//    void pop() {
//        if (_st.top() == _minst.top())
//        {
//            _minst.pop();
//        }
//        _st.pop();
//    }
//
//    int top() {
//        return _st.top();
//    }
//
//    int getMin() {
//        return _minst.top();
//    }
//private:
//    stack <int> _st;
//    stack <int> _minst;
//};
//
// 
//JZ31 栈的压入、弹出序列牛课题
//class Solution {
//public:
//
//    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
//        int popi = 0;
//        stack <int> st;
//        for (auto& e : pushV)
//        {
//            st.push(e);
//            while (!st.empty() && st.top() == popV[popi])
//            {
//                st.pop();
//                popi++;
//            }
//        }
//        // write code here
//        return st.empty();
//    }
//};
// 
//1658 将X减到零的最小操作数
//class Solution {
//public:
//    int minOperations(vector<int>& nums, int x) {
//        int sum = 0;
//        for (int s : nums) sum += s;
//        int target = sum - x;
//        if (target < 0) return -1;
//        int ret = -1;
//        for (int left = 0, right = 0, tmp = 0;right < nums.size(); right++)
//        {
//            tmp += nums[right];
//            while (tmp > target)
//            {
//                tmp -= nums[left++];
//            }
//            if (tmp == target)
//                ret = max(ret, right - left + 1);
//
//        }
//        if (ret == -1) return -1;
//        else return nums.size() - ret;
//    }
//};
//904 解决水果成篮问题 滑动窗口解决 最多包含两种不同的水果
//class Solution {
//public:
//    int totalFruit(vector<int>& f) {
//        int left = 0, right = 0;
//        int hash[100001] = { 0 };
//        int ret = 0;
//        for (int kinds = 0;right < f.size(); right++)
//        {
//            if (hash[f[right]] == 0)  kinds++;
//            hash[f[right]]++;
//            while (kinds > 2)
//            {
//                hash[f[left]]--;
//                if (hash[f[left]] == 0) kinds--;
//                left++;
//            }
//            ret = max(ret, right - left + 1);
//        }
//        return ret;
//    }
//};